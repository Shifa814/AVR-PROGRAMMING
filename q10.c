#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

void ADC_Init()
{
    ADMUX = (1<<REFS0);
    ADCSRA = (1<<ADEN)|(1<<ADPS2)|(1<<ADPS1);
}

uint16_t ADC_Read()
{
    ADCSRA |= (1<<ADSC);
    while(ADCSRA & (1<<ADSC));
    return ADC;
}

int main(void)
{
    DDRD |= (1<<PD6);
    DDRD &= ~(1<<PD2);

    ADC_Init();

    TCCR0A=(1<<COM0A1)|(1<<WGM00)|(1<<WGM01);
    TCCR0B=(1<<CS01);

    uint8_t system_on=0;

    while(1)
    {
        if(!(PIND&(1<<PD2)))
        {
            _delay_ms(200);
            system_on=!system_on;

            while(!(PIND&(1<<PD2)));
        }

        if(system_on)
        {
            uint16_t temp=ADC_Read();

            if(temp<300)
                OCR0A=80;
            else
                OCR0A=220;
        }
        else
        {
            OCR0A=0;
        }
    }
}