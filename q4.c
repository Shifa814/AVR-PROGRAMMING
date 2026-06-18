#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

void displayCount(uint8_t count)
{
    PORTB = (PORTB & 0xF0) | (count & 0x0F);
}

int main(void)
{
    DDRB |= 0x0F;
    DDRD &= ~(1<<PD2);

    PORTD |= (1<<PD2);

    uint8_t count = 0;

    displayCount(count);

    while(1)
    {
        if(!(PIND & (1<<PD2)))
        {
            _delay_ms(50);

            count++;

            if(count > 15)
                count = 0;

            displayCount(count);

            while(!(PIND & (1<<PD2)));
        }
    }
}