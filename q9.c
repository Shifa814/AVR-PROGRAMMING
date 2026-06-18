#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
    DDRD |= (1<<PD6);
    DDRD &= ~(1<<PD2);

    TCCR0A = (1<<COM0A1)|(1<<WGM00)|(1<<WGM01);
    TCCR0B = (1<<CS01);

    uint8_t level=0;
    uint8_t pwm[4]={64,128,192,255};

    OCR0A=pwm[level];

    while(1)
    {
        if(!(PIND&(1<<PD2)))
        {
            _delay_ms(50);

            level=(level+1)%4;
            OCR0A=pwm[level];

            while(!(PIND&(1<<PD2)));
        }
    }
}