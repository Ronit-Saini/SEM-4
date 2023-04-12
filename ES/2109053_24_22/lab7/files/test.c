#include <LPC17xx.h>
unsigned int i,j; 
unsigned long LED = 0x00000010;
int main(void)
{
 SystemInit(); //Add these two function for its internal operation
 SystemCoreClockUpdate();
 LPC_PINCON->PINSEL0 &= 0xFF0000FF;
 //Configure Port0 PINS P0.4-P0.11 as GPIO function
 LPC_GPIO0->FIODIR |= 0x00000FF0;
//Configure P0.4-P0.11 as output port 
 while(1)
 {
	 
LED = 0x00000000;
for(i=1;i<5555;i++) //On the LED's serially
{
 LPC_GPIO0->FIOPIN = LED; 
 // Turn ON LED at LSB (LED connected to p0.4) 
for(j=0;j<1000;j++);//a random delay
 LED = LED +0X00000001; 
	if(LED > 0xFFF){
		LED=0x00000000;
	}
} 


}
}
