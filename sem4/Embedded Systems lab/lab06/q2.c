#include "LPC17xx.h"
unsigned int i,j;
unsigned long LED=0x00000000;
int main(){
	SystemInit();
	SystemCoreClockUpdate();
	LPC_PINCON->PINSEL0 &= 0xFF0000FF;
	LPC_PINCON->PINSEL4 &=0XFCFFFFFF;
	LPC_GPIO0->FIODIR |= 0x00000FF0;
	LPC_GPIO2->FIODIR &= 0xFFFFEFFF;
	while(1){
		
		if(LPC_GPIO2->FIOPIN & 1<<12){
		    LED++;
				LPC_GPIO0->FIOPIN = LED<<4;
				for(j=0;j<100000;j++);
			  
			}
		else{
				LED--;
				LPC_GPIO0->FIOPIN = LED<<4;
				for(j=0;j<100000;j++);

			
		}
	}
}
