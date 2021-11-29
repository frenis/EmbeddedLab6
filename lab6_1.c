#include <msp430g2553.h>
volatile long lightRaw;
volatile float light;
void ConfigureAdc_light();
void main(void)
{
    WDTCTL = WDTPW + WDTHOLD; // Stop watchdog timer
    ConfigureAdc_light();
    _delay_cycles(5);         // Wait for ADC Ref to settle
    while(1){
         lightRaw = ADC10MEM;
         light = lightRaw*3.3/1023; // Convert ADC output to voltage
    }
}
// Configure ADC Temperature
void ConfigureAdc_light(){
     ADC10CTL1 = INCH_4 + ADC10DIV_0 + CONSEQ_2;
     ADC10CTL0 = SREF_0 | ADC10SHT_3 | ADC10ON; //Vref+, Vss, 64 ATD clocks per sample, internal 5V reference, turn ADCON
     ADC10CTL0 |= ENC + ADC10SC + MSC;
}
