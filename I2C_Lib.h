/*
 * I2C_Lib.h
 *
 * Created: 25-Mar-24 1:00:37 PM
 *  Author: iqbal
 */ 


#ifndef I2C_LIB_H_
#define I2C_LIB_H_

#include <avr/io.h>

void I2C_Init()
{
	PRR0 &= ~(1<< PRTWI);             // turn off power reduction mode so that I2C can work
	TWBR = 2;
	TWCR |= (1<<TWEN); // Enable i2c
	TWSR = 0x00; // prescaler 1
	
}

void I2C_Start_Or_Restart()
{
	TWCR = (1<<TWINT | 1<<TWEN | 1<<TWSTA); // --- start condition
	while (!(TWCR & (1<<TWINT))); // --- check if transmission is done
}

void I2C_Stop()
{
	TWCR |= (1<<TWINT) | (1<<TWEN) | (1<<TWSTO); // --- stop condition
}

void I2C_Write(char x)
{
	TWDR = x;
	TWCR = (1<<TWINT | 1<<TWEN); // Enable and clear flag
	while (!(TWCR & (1<<TWINT))); // --- check if transmission is done
}
char I2C_Read()
{
	TWCR = (1<<TWEN | 1<<TWINT); 
	while (!(TWCR & (1<<TWINT)));// --- check if transmission is done
	return TWDR;
}


#endif /* I2C_LIB_H_ */