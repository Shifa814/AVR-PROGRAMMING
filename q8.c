#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

void setPWM(uint8_t duty)
{
    OCR0A = duty;
}

int main(void)
{
    DDRD |= (1<<PD6);
    DDRD &= ~(1<<PD2);

    TCCR0A = (1<<COM0A1)|(1<<WGM00)|(1<<WGM01);
    TCCR0B = (1<<CS01);

    uint8_t level=0;
    uint8_t duty[4]={64,128,192,0};

    setPWM(duty[level]);

    while(1)
    {
        if(!(PIND&(1<<PD2)))
        {
            _delay_ms(200);
            level=(level+1)%4;
            setPWM(duty[level]);

            while(!(PIND&(1<<PD2)));
        }
    }
}