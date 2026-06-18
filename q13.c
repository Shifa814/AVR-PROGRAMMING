#define F_CPU 16000000UL
#include <avr/io.h>

void UART_Init()
{
    UBRR0L=103;
    UCSR0B=(1<<RXEN0);
    UCSR0C=(1<<U