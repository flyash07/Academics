#include "LPC17xx.h"

int i,j;
uint8_t display[10]={0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D,0x07, 0x7F, 0x6F};
unsigned int d[4]=0;
unsigned int number=9999;
int d1,d2,d3,d4;
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
	LPC_GPIO0->FIODIR ?
	//LPC_GPIO1->FIOPIN |= 0<<23;   
	
	
	while(1){
		if(!(LPC_GPIO0->FIOPIN & 1<<21)){
			
			//d1=d/1000%10;d2=(d/100)%10;d3=(d/10)%10....
			for(i=0,k1=1000,k2=1;i<4;i++,k1/=10,k2*=10){
				LPC_GPIO1->FIOPIN=i<<23;
				d[i]=(number/k1)%10;
				LPC_GPIO0->FIOPIN=display[d[i]]<<4;
				delay();
			}
			delay();
			number--;
			if(number==-1) number=9999;
					
		}
		else{
			for(i=0,k1=1000,k2=1;i<4;i++,k1/=10,k2*=10){
				LPC_GPIO1->FIOPIN=i<<23;
				d[i]=(number/k1)%10;
				LPC_GPIO0->FIOPIN=display[d[i]]<<4;
				delay();
			}
			delay();
			number++;
			if(number==1000) number=0;
		}
		// LPC_GPIO0->FIOCLR|=0X00000FF0;
		
	}
	
}


	