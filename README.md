# EmbeddedLab6
Lab 6 of Embedded Systems - section 4. This lab was worked on by Seth Freni and Vincent Del Tufo.
## lab6_1.c
This code is for question 1. Here a single photoresistor is being read through pin P1.4. The ADC is configured with a reference of 0-5V. The value light is the voltage being read from the ADC.
## lab6_2.c
This code is for question 2. Here a  photoresistor and a thermristor are being read through pins P1.3 and P1.0. The ADC is configured with a reference of 0-5V and is set to recieve data from multiple pins. The values voltage1 and voltage2 are the voltage being read from the ADC. 

All of the data from the ADC is sent to the array called adc of size 4. Since the pin for the CTL1 register is INCH_3, pins P1.0 through P1.3 will be recorded. From there the two important values were taken from the array and converted into voltages.
