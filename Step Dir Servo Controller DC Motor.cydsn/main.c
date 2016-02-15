#include <project.h>
#include <stdlib.h>
#include <stdio.h>

// Packets coming in have to be 4 byte aligned due to the API for reading the data.
// Packets going out don't have that restriction.
#define PACKET_TYPE_PERF_DATA 1
#define PACKET_SIZE_PERF_DATA 20
#define PACKET_TYPE_GET_CONFIG 2
#define PACKET_SIZE_GET_CONFIG 2
#define PACKET_TYPE_SET_CONFIG 3
#define PACKET_SIZE_SET_CONFIG 14
#define PACKET_TYPE_START_PERF_DATA 4
#define PACKET_SIZE_START_PERF_DATA 2
#define PACKET_TYPE_STOP_PERF_DATA 5
#define PACKET_SIZE_STOP_PERF_DATA 2
#define PACKET_TYPE_START_FAKE_STEP_COUNTER 6
#define PACKET_SIZE_START_FAKE_STEP_COUNTER 2
#define PACKET_TYPE_STOP_FAKE_STEP_COUNTER 7
#define PACKET_SIZE_STOP_FAKE_STEP_COUNTER 2
#define PACKET_TYPE_CONFIG 8
#define PACKET_SIZE_CONFIG 14

uint16 LastQuadCount, LastStepCount;
uint16 QuadCount, StepCount;
uint16 PWMPeriod = 4000, MaxIntegralTerm = 4096;
int16 ErrorMax = 15;
int16 Kp = 30, Ki = 1, Kd = 1;
int16 Error, LastError;
int16 Integral_Term;
uint8 MotorEnabled = 1;
int32 PIDValue;

CY_ISR( QuadOverflow_Handler ) {
    QuadDec_1_ClearInterrupt(QuadDec_1_INTR_MASK_CC_MATCH);    
    // Update the last counts and error
    // Capture should have the previous count in it, if it's 0xFFFF then we overflowed, if it's 0x0000 we underflowed
    uint16 Capture = QuadDec_1_ReadCapture();
    uint16 QuadCount = QuadDec_1_ReadCounter();
    if (Capture >= 0xFFF0U) {
        // Overflow
        Error -= (((uint16)0xFFFFU) - LastQuadCount) // Change from the last time we read it
                    - (QuadCount - 0x8000); // handles the reload to 0x8001 or 0x7FFF if simultaneous events occur
        LastQuadCount = QuadCount;
    } else if (Capture <= 0x000F) {
        // Underflow   
        Error += (LastQuadCount) // Change from the last time we read it (to zero)
                    + (QuadCount - 0x8000); // handles the reload to 0x8001 or 0x7FFF if simultaneous events occur
        LastQuadCount = QuadCount;
    }
}

CY_ISR( StepDirOverflow_Handler ) {
    uint8 stat_reg = StepDirCounter_ReadStatusRegister();
    StepCount = StepDirCounter_ReadCounter();
    if ((stat_reg & 0x04) > 0) {
        // Overflow    
        Error +=(((uint16)0xFFFFU) - LastStepCount);
        LastStepCount = StepCount;
    } else if ((stat_reg & 0x08) > 0) {
        // Underflow
        Error -= LastStepCount;
        LastStepCount = StepCount;
    } 
}

CY_ISR( SerialTimer_Handler ) {
    SerialDataTimer_ClearInterrupt(SerialDataTimer_INTR_MASK_TC);
    // Send the serial data
    uint8 data[PACKET_SIZE_PERF_DATA];
    data[0] = PACKET_SIZE_PERF_DATA;
    data[1] = PACKET_TYPE_PERF_DATA;
    ((uint16*)data)[1] = LastQuadCount;
    ((uint16*)data)[2] = LastStepCount;
    ((int16*)data)[3] = Error;
    ((int16*)data)[4] = LastError;
    ((int16*)data)[5] = Integral_Term;
    ((uint16*)data)[6] = QuadCount;
    ((uint16*)data)[7] = StepCount;
    ((int32*)data)[4] = PIDValue;
    // I think that gets them all packed in.
    // This should end up being 8*2bytes + 4 bytes = 20 bytes.
    UART_1_SpiUartPutArray(data, PACKET_SIZE_PERF_DATA);
}
CY_ISR( PIDLoop_Handler) {
    // Does the PID calculation and updates the globals, set the PWM
    PIDTimer_ClearInterrupt(PIDTimer_INTR_MASK_TC);
    
    QuadCount = QuadDec_1_ReadCounter();
    StepCount = StepDirCounter_ReadCounter();
    uint8 control = 0x00;
    // compute errors from last counts, update last counts
    Error += (int16)((int32)StepCount - (int32)LastStepCount);
    Error -= (int16)((int32)QuadCount - (int32)LastQuadCount);
    LastStepCount = StepCount;
    LastQuadCount = QuadCount;
    
      
    // Check if the error is outside our range
    if (Error > ErrorMax || Error < -ErrorMax) {
        // throw some form of error
        LedPin_Write(1);
    }
    Integral_Term += Error;      
    if (Integral_Term > MaxIntegralTerm) {
        Integral_Term = MaxIntegralTerm;   
    } else if (Integral_Term < -MaxIntegralTerm) {
        Integral_Term = -MaxIntegralTerm;   
    }
    //if (Error == 0) Integral_Term = 0;

    PIDValue = Kp * Error + (Integral_Term * Ki) + Kd * (Error - LastError);
    LastError = Error;
    // set the control register and set the PWM value
    
    if (MotorEnabled) {
        if (PIDValue > 0) {
            control = 0x03;        
        } else if (PIDValue < 0) {
            control = 0x01;
        }
    } else {
        if (PIDValue > 0) {
            control = 0x02;        
        } else if (PIDValue < 0) {
            control = 0x00;
        }
    }
    uint32 AbsPIDValue = abs(PIDValue);// / PIDOutputScaleFactor;    // Scale to fit into the range
    AbsPIDValue = PWMPeriod < AbsPIDValue ? PWMPeriod: AbsPIDValue;
    MotorPWM_WriteCompare(AbsPIDValue);
    MotorControlReg_Write(control);
}

void SerialSendConfig() {
    // Send a configuration packet over serial to the PC
    uint8 packet[PACKET_SIZE_CONFIG];
    packet[0] = PACKET_SIZE_CONFIG;
    packet[1] = PACKET_TYPE_CONFIG;
    ((int16*)packet)[1] = Kp;
    ((int16*)packet)[2] = Ki;
    ((int16*)packet)[3] = Kd;
    ((int16*)packet)[4] = ErrorMax;
    ((int16*)packet)[5] = PWMPeriod;
    ((int16*)packet)[6] = MaxIntegralTerm;
    UART_1_SpiUartPutArray(packet, PACKET_SIZE_CONFIG);
}

void SerialSetConfig(int16 _Kp, int16 _Ki, int16 _Kd, int16 _ErrorMax, int16 _PWMPeriod, int16 _MaxIntegralTerm) {
    Kp = _Kp;
    Ki = _Ki;
    Kd = _Kd;
    ErrorMax = _ErrorMax;
    PWMPeriod = _PWMPeriod;
    MaxIntegralTerm = _MaxIntegralTerm;
    MotorPWM_WritePeriod(PWMPeriod);
    LedPin_Write(0);
}

int main()
{

//    UART_1_SetCustomInterruptHandler(SerialInterrupt);
       
    PIDLoopInt_StartEx(PIDLoop_Handler);
    PIDLoopInt_SetPriority(2);  // 0 is highest (0-3)
   
    QuadCounterWrap_StartEx(QuadOverflow_Handler);
    QuadCounterWrap_SetPriority(0);
    
    StepDirCounterWrap_StartEx(StepDirOverflow_Handler);
    StepDirCounterWrap_SetPriority(1);
    
    SerialDataInt_StartEx(SerialTimer_Handler);
    SerialDataInt_SetPriority(3);
    
    MotorPWM_WritePeriod(PWMPeriod);
    
    UART_1_Start();
    MotorPWM_Start();
    QuadDec_1_Start();
    //SerialDataTimer_Start();
    StepDirCounter_Start();
    PIDTimer_Start();
    CyGlobalIntEnable; /* Enable global interrupts. */
    CyDelay(100);
    LedPin_Write(0);
    uint8 SerialBuffer[128];
    uint8 buffer_offset = 0;    // offset in int32's
    int i;
    for(;;)
    {
        if (UART_1_SpiUartGetRxBufferSize() > 0 ) {
            // There is data to look at.
            // Read it into a buffer
            // figure out if there is a packet there.
            SerialBuffer[buffer_offset] = (uint8)UART_1_SpiUartReadRxData(); // reads 1 byte from the buffer
            buffer_offset++;
            // first byte in the buffer should be the length of the packet in bytes
            if (SerialBuffer[0] <= buffer_offset) {
                // Should be enough in the buffer to make a packet
                // process the packet
                int packet_size = 0;
                switch (SerialBuffer[1]) {
                    case PACKET_TYPE_GET_CONFIG:
                        // Nothing actually in this packet beyond size/type
                        packet_size = PACKET_SIZE_GET_CONFIG;
                        SerialSendConfig();
                        break;
                    case PACKET_TYPE_SET_CONFIG:
                        packet_size = PACKET_SIZE_SET_CONFIG;
                        SerialSetConfig(((int16*)SerialBuffer)[1], ((int16*)SerialBuffer)[2], ((int16*)SerialBuffer)[3], ((int16*)SerialBuffer)[4], ((int16*)SerialBuffer)[5], ((int16*)SerialBuffer)[6]);
                        break;
                    case PACKET_TYPE_START_PERF_DATA:
                        packet_size = PACKET_SIZE_START_PERF_DATA;
                        // Nothing in the packet just start the timer
                        SerialDataTimer_Start();
                        break;
                    case PACKET_TYPE_STOP_PERF_DATA:
                        packet_size = PACKET_SIZE_STOP_PERF_DATA;
                        // Nothing in the packet just stop the timer
                        SerialDataTimer_Stop();
                        break;
                        /*
                    case PACKET_TYPE_START_FAKE_STEP_COUNTER:
                        packet_size = PACKET_SIZE_START_FAKE_STEP_COUNTER;
                        // Nothing in the packet just start the timer
                        Timer_1_Start();
                        break;
                    case PACKET_TYPE_STOP_FAKE_STEP_COUNTER:
                        packet_size = PACKET_SIZE_STOP_FAKE_STEP_COUNTER;
                        // Nothing in the packet just start the timer
                        Timer_1_Stop();
                        break;
                        */
                    default:
                        break;
                    }
                // reset the offset
                buffer_offset -= packet_size;
                for (i = 0; i < buffer_offset; i++) {
                    SerialBuffer[i] = SerialBuffer[i+packet_size];
                }
            }
        }
    }
}
