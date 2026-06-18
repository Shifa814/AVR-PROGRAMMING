#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
    DDRB = 0xFF;

    while(1)
    {
        for(uint8_t i = 0; i < 8; i++)
        {
            PORTB = (1 << i);
            _delay_ms(200);
        }
    }
}