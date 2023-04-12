#include <LPC17xx.h>
#include <stdio.h>

unsigned int N=2;
unsigned int select_segment[4] = {0, 1<<23, 2<<23,4<<23};
unsigned int dig_count=0;
unsigned int digit_value[5]={9,9,9,9,9};
unsigned int seven_seg[10]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};
unsigned long int temp1,temp2,i=0;
int sign=1,reset=0;
unsigned int comp=0X0A;
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
		 delay();

			if(!(LPC_GPIO2->FIOPIN & 1<<12))
			{
				sign=1;
				reset=0;
				comp=0x0A;
			}
			else{
				sign=-1;
				reset=9;
				comp=0X00;
				
			}
			
			if(digit_value[1]==comp)
			{
				digit_value[1]=reset;
				digit_value[2]+=sign;
				if(digit_value[2]==comp)
				{
						digit_value[2]=reset;
					digit_value[3]+=sign;
					if(digit_value[3]==comp)
					{
						digit_value[3]=reset;
						digit_value[4]+=sign;
						if(digit_value[4]==comp)
						{
							digit_value[4]=reset;
						}
						
					}
					
				}
			}
			display();
			digit_value[1]+=sign;
		}
	
	}
	
void display(void) //To Display on 7-segments
{
	for (dig_count=5;dig_count>0;dig_count--){
	LPC_GPIO1->FIOPIN = select_segment[dig_count]; 
	LPC_GPIO0->FIOPIN = seven_seg[digit_value[dig_count]]<<4;
	delay();
	LPC_GPIO0->FIOCLR=0x00000FF0;
	}
}

void delay(void)
{
	for(i=0;i<50000;i++);

}