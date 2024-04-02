#include "LPC17xx.h"

int i,j;
uint8_t display[10]={0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D,0x07, 0x7F, 0x6F};
uint8_t d[4]={4,3,2,1};
int main(){
	SystemInit();
	SystemCoreClockUpdate();
	LPC_PINCON->PINSEL4 &=0XFCFFFFFF;
	
	LPC_GPIO0->FIODIR |= 0xFF0;   //7 segment
	LPC_GPIO1->FIODIR |= 0xF<<23;  //decoder
	LPC_GPIO1->FIOPIN |= 0<<23; 
	LPC_GPIO2->FIODIR &= 0xFFFFEFFF;  
	
	while(1){
		
	for(i=0;i<4;i++){
		LPC_GPIO1->FIOPIN=i<<23;
		LPC_GPIO0->FIOPIN=display[d[i]]<<4;
		for(j=0;j<1000;j++);
	}
	}
}
	
