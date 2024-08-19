# 24C04_EEPROM
In this video i have interfaced 24c04 eeprom using atmega1284p clocked at 20 MHz. The i2c bus was set to 100 KHz(which i forgot to mention) speed, and on eeprom ic the A0,A1,A2 are set to zero by grounding. 

First i send the slave address which is 10100000 - 1010 is constant, then 000 is A0,A1,A2, and final 0 is for write, as explained in the video. 
Then i sent 0x00 for high byte and 0x10 for low byte to set the Data Register address, hi and lo byte is also known as word (2bytes).
Then you send the data which is 0x0f in our case then you end the I2C.

So the write process is done, Now we need to read the that from eeprom.
To do that first we need to send slave address + write(8bits), same as previous one. then you have to send hi and lo byte which is register address ie. 0x00 and 0x10. after setting this, the eeprom is locked to this address, so now we want to read into this address, to do that we do repeat start(same code line in my case). after that we do i2c read then we can put that in a variable or output to a port which in our case is portA.

And thats it, now you can read and write from a serial EEPROM.

also check here in my website for more info and other projects - https://numitron.wordpress.com/24c04-using-i2c/
