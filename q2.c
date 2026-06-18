#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
    DDRB |= (1<<PB0) | (1<<PB1);
    DDRD &= ~(1<<PD2);

    PORTD |= (1<<PD2);

    uint8_t state = 0;

    PORTB |= (1<<PB0);

    while(1)
    {
        if(!(PIND & (1<<PD2)))
        {
            _delay_ms(50);

            if(state == 0)
            {
                PORTB &= ~(1<<PB0);
                PORTB |= (1<<PB1);
                state = 1;
            }
            else
            {
                PORTB &= ~(1<<PB1);
                PORTB |= (1<<PB0);
                state = 0;
            }

            while(!(PIND & (1<<PD2)));
        }
    }
}