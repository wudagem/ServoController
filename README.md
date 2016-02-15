# ServoController
Basic PID Servo Controller based on the PSoC4 Devkit CY8CKIT-049-42XX

# To use 
You will need a CY8CKIT-049-42XX dev kit, eg http://www.digikey.ca/product-detail/en/CY8CKIT-049-42XX/428-3344-ND/4805328
An H Bridge suitable to drive the motor you have selected
A motor with a quadrature encoder and a suitable de-bouncing circuit, a simple RC filter with appropriate values for your pulse timings is sufficient.
A motion controller that creates a suitable step/dir pulse, I have been using GRBL.

The H bridge drive is currently configured to drive a common L298 H bridge, and is on pins 0.0 and 0.1.
The Quadrature encoder goes on pins 0.6 and 0.5.
The Step pulse goes on pin 2.6, and the dir pulse on 2.5