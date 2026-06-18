#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
    DDRB |= (1<<PB0) | (1<<PB1) | (1<<PB2);

    while(1)
    {
        PORTB = (1<<PB0);
        _delay_ms(10000);

        PORTB = (1<<PB1);
        _delay_ms(3000);

        PORTB = (1<<PB2);
        _delay_ms(10000);
    }
}