#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

int main()
{
    DDRB=0xFF;
    DDRD &= ~(1<<PD2);

    while(1)
    {
        if(!(PIND&(1<<PD2)))
        {
            PORTB=0xAA;
        }
        else
        {
            PORTB=0x55;
        }
    }
}