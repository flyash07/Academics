#include "LPC17xx.h"

int i,j;
uint8_t display[10]={0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D,0x07, 0x7F, 0x6F};
int d[4]={9};

void InitTimer0(void){
	LPC_TIM0->CTCR=0;
	LPC_TIM0->TCR=0x2;
	LPC_TIM0->PR=2;
	LPC_TIM0->MR0=999;
	LPC_TIM0->MCR=2;
	LPC_TIM0->EMR=0x20;
	LPC_TIM0->TCR=1;
}

void delay(void){
	InitTimer0();
	while(!(LPC_TIM0->EMR & 1));
}
	
	

int main(){
	SystemInit();
	SystemCoreClockUpdate();
	LPC_GPIO0->FIODIR |= 0xFF0;   //7 segment
	LPC_GPIO1->FIODIR |= 0xF<<23;  //decoder
	//LPC_GPIO1->FIOPIN |= 0<<23;   
	
	
	while(1){
		
		
	}
	
	for(d[3]=9;d[3]>=0;d[3]--){
		for(d[2]=9;d[2]>=0;d[2]--){
			for(d[1]=9;d[1]>=0;d[1]--){
				for(d[0]=9;d[0]>=0;d[0]--){
					for(i=0;i<4;i++){
						LPC_GPIO1->FIOPIN=i<<23;
						LPC_GPIO0->FIOPIN=display[d[i]]<<4;
						delay();
					}
					delay();
					}
				}
			}
		
	 // LPC_GPIO0->FIOCLR|=0X00000FF0;
if(d[3]==0)
			d[3]=10;
				}

		
	}


	