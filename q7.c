#include <avr/io.h>
#include <avr/interrupt.h>

ISR(TIMER1_COMPA_vect)
{
    PORTB ^= (1<<PB1);
}

ISR(TIMER2_COMPA_vect)
{
    PORTB ^= (1<<PB2);
}

int main(void)
{
    DDRB |= (1<<PB1)|(1<<PB2);

    TCCR1B |= (1<<WGM12)|(1<<CS12);
    OCR1A = 31249;
    TIMSK1 |= (1<<OCIE1A);

    TCCR2A |= (1<<WGM21);
    TCCR2B |= (1<<CS22)|(1<<CS21)|(1<<CS20);
    OCR2A = 244;
    TIMSK2 |= (1<<OCIE2A);

    sei();

    while(1);
}