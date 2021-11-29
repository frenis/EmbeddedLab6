#include <msp430.h>

volatile float voltage1, voltage2;

unsigned int adc[4];
void main(void)
{
    WDTCTL = WDTPW | WDTHOLD;   // stop watchdog timer

    ADC10CTL1 = INCH_3 + ADC10DIV_0 + CONSEQ_3 + SHS_0; // read inputs from A0 to A3
    ADC10CTL0 = SREF_0 + ADC10SHT_2 + MSC + ADC10ON;    // using 5V reference
    ADC10AE0 = BIT3 + BIT0;
    ADC10DTC1 = 4;


    while(1){
        ADC10CTL0 &= ~ENC;
        while (ADC10CTL1 & BUSY);
        ADC10CTL0 |= ENC + ADC10SC;
        ADC10SA = (unsigned int)adc;
        voltage1 = adc[0]*3.3/1023; // Convert ADC output to voltage
        voltage2 = adc[3]*3.3/1023;
    }
}
