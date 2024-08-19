#define F_CPU 1000000UL
#include <avr/io.h>
#include "I2C_Lib.h"
#include <util/delay.h>

//-------------------------------------------------------
// To read from eeprom with address, first init, start

// then slave + W(0)
// then write register high byte, then low byte
// repeat start and do slave address with read(1)
// use variable or port to output i2c data
// stop

int main(void)
{
   DDRA = 0xff;
   I2C_Init();
   
   I2C_Start_Or_Restart();
   I2C_Write(0b10100000); // slave address + W(0)
   I2C_Write(0x00); // word address register_high byte
   I2C_Write(0x01); // word address register_low byte
   
    I2C_Start_Or_Restart();
    I2C_Write(0b10100001); // slave address + R(1)
   
   //  I2C_Write(0x55); // data register

    PORTA = I2C_Read();

    I2C_Stop();
   
    while (1) 
    {
		
    }
}