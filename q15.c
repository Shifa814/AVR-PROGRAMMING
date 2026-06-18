#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

void I2C_Init(void)
{
    TWSR = 0x00;
    TWBR = 72;
}

int main(void)
{
    I2C_Init();

    while(1)
    {
        // BMP280-il ninn temperature/pressure read cheyyuka
        // OLED-il display cheyyuka

        _delay_ms(1000);
    }
}