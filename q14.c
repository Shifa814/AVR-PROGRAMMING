#define F_CPU 16000000UL
#include <avr/io.h>

void ADC_Init()
{
    ADMUX = (1<<REFS0);
    ADCSRA = (1<<ADEN) | (1<<ADPS2) | (1<<ADPS1);
}

uint16_t ADC_Read()
{
    ADCSRA |= (1<<ADSC);
    while(ADCSRA & (1<<ADSC));
    return ADC;
}

int main(void)
{
    DDRD |= (1<<PD6);   // PWM Output

    ADC_Init();

    TCCR0A = (1<<COM0A1) | (1<<WGM00) | (1<<WGM01);
    TCCR0B = (1<<CS01);

    while(1)
    {
        uint16_t adcValue = ADC_Read();

        OCR0A = adcValue / 4;   // 0-1023 → 0-255
    }
}