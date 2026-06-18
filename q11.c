#define F_CPU 16000000UL
#include <avr/io.h>

void ADC_Init()
{
    ADMUX=(1<<REFS0);
    ADCSRA=(1<<ADEN)|(1<<ADPS2)|(1<<ADPS1);
}

uint16_t ADC_Read()
{
    ADCSRA|=(1<<ADSC);
    while(ADCSRA&(1<<ADSC));
    return ADC;
}

int main()
{
    DDRB |= (1<<PB1);

    ADC_Init();

    TCCR1A=(1<<COM1A1)|(1<<WGM11);
    TCCR1B=(1<<WGM13)|(1<<WGM12)|(1<<CS11);
    ICR1=39999;

    while(1)
    {
        uint16_t adc=ADC_Read();
        OCR1A=1000+(adc*1000UL)/1023;
    }
}