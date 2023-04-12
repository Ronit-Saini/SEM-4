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
	LPC_PINCON->PINSEL4 = 0xFCFFFFFF;
	 LPC_GPIO2->FIODIR = 0xFFFFEFFF;
//Configure P0.4-P0.11 as output port 
 while(1)
 {
	 
	if(!(LPC_GPIO2->FIOPIN&1<<12)){
		
	LED = 0x00000001;
 LPC_GPIO0->FIOPIN = LED; 
 // Turn ON LED at LSB (LED connected to p0.4) 
for(j=0;j<15;j++){//a random delay
	LED <<= 1; 
	LPC_GPIO0->FIOPIN = LED; 
	for(i=0;i<10000;i++);
}}




}
}
