#include <LPC17xx.h>
#include <stdio.h>

unsigned int N=2;
unsigned int select_segment[4] = {0, 1<<23, 2<<23,3<<23};
unsigned int dig_count=0;
unsigned int digit_value[4]={9,9,9,9};
unsigned int seven_seg[10]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};
unsigned long int temp1,temp2,i=0;

void delay(void);
void display(void);
int main(void)
{ 
	 SystemInit();
	 SystemCoreClockUpdate();
	 LPC_PINCON->PINSEL0 &= 0xFF0000FF; //P0.4 to P0.11 GPIO data lines
	 LPC_PINCON->PINSEL3 &= 0xFFC03FFF; //P1.23 to P1.26 GPIO enable lines
	 LPC_GPIO0->FIODIR |= 0x00000FF0; //P0.4 to P0.11 output
	 LPC_GPIO1->FIODIR |= 0x07800000; //P1.23 to P1.26 output
	
	while(1)
		{
		 for(i=0;i<1000;i++);

			
			if(digit_value[0]==0x0)
			{
				digit_value[0]=9;
				digit_value[1]-=1;
				if(digit_value[1]==0x0)
				{
						digit_value[1]=9;
					digit_value[2]-=1;
					if(digit_value[2]==0x0)
					{
						digit_value[2]=9;
						digit_value[3]-=1;
						if(digit_value[3]==0x0)
						{
							digit_value[3]=9;
						}
						
					}
					
				}
			}
			display();
			digit_value[0]-=1;
		}
	
	}
	
void display(void) //To Display on 7-segments
{
	//for (dig_count=4;dig_count>0;dig_count--){
	LPC_GPIO1->FIOPIN = select_segment[0]; 
	LPC_GPIO0->FIOPIN = seven_seg[digit_value[0]]<<4;
	for(i=0;i<1000;i++);
	//LPC_GPIO0->FIOCLR=0x00000FF0;
	LPC_GPIO1->FIOPIN = select_segment[1]; 
	LPC_GPIO0->FIOPIN = seven_seg[digit_value[1]]<<4;
	for(i=0;i<1000;i++);
	//LPC_GPIO0->FIOCLR=0x00000FF0;
	LPC_GPIO1->FIOPIN = select_segment[2]; 
	LPC_GPIO0->FIOPIN = seven_seg[digit_value[2]]<<4;
	for(i=0;i<1000;i++);
	//LPC_GPIO0->FIOCLR=0x00000FF0;
	LPC_GPIO1->FIOPIN = select_segment[3]; 
	LPC_GPIO0->FIOPIN = seven_seg[digit_value[3]]<<4;
	for(i=0;i<1000;i++);
	LPC_GPIO0->FIOCLR=0x00000FF0;
		
	for(i=0;i<1000;i++);
	
	//}
	
		//

}

void delay(void)
{
	for(i=0;i<50000;i++);

}