#include <LPC17xx.h>
//#include "keyboard.h"
unsigned int temp,i,j;
void initPWM(void);
void updatePulseWidth(unsigned int pulseWidth);
void delayMS(unsigned int milliseconds);
unsigned char SCAN_CODE[4] = {0x11,0x21,0x41,0x81};
unsigned char  key;
int scan_col(unsigned int rown, int t);
int main(void)

{
	int t=0;
	int pulseWidths[] = {3000, 7500, 15000, 22500}; //Pulse Widths for varying LED Brightness
	initPWM(); //Initialize PWM
	LPC_GPIO1->FIODIR &= 0xFFFFFF0F;
	
	while(1){
		t=scan_col(0x01,t);
		updatePulseWidth(pulseWidths[t]); //Update LED Pulse Width	
	}
}


void initPWM(void){
	LPC_PINCON->PINSEL3 |= 0x8000; //Select PWM1.4 output for Pin1.23,function 2
	LPC_PWM1->PCR = 0x1000; //enable PWM1.1, by default it is single Edged
	LPC_PWM1->PR = 0;
	LPC_PWM1->MR0 = 30000; //period=10ms if pclk=cclk/4
	LPC_PWM1->MCR = (1<<1); //Reset PWM TC on PWM1MR0 match
	LPC_PWM1->LER = 0xff; //update values in MR0 and MR1
	LPC_PWM1->TCR = 0x00000002; //RESET COUNTER TC and PC
	LPC_PWM1->TCR = 0x00000009; //enable TC and PC
}

void updatePulseWidth(unsigned int pulseWidth){
	LPC_PWM1->MR4 = pulseWidth; //Update MR4 with new value
	LPC_PWM1->LER = 0xff; //Load the MR4 new value at start of next cycle
}
/*
void delayMS(unsigned int milliseconds) //Using Timer0
{
	LPC_TIM0->CTCR = 0x0; //Timer mode
	LPC_TIM0->PR = 2; //Increment TC at every 3 pclk
	LPC_TIM0->TCR = 0x02; //Reset Timer
	LPC_TIM0->TCR = 0x01; //Enable timer
	while(LPC_TIM0->TC < milliseconds); //wait until timer counter reaches the desired delay
	LPC_TIM0->TCR = 0x00; //Disable timer
}
*/
int scan_col(unsigned int rown, int t){
	
	temp = LPC_GPIO0->FIOPIN;
	temp &= 0x000000F0; //check if any key pressed in the enabled row
	if(temp){   //if key is pressend, fiopin corresponding bit becomes 1
		key = temp|rown; //get SCAN_CODE
		for(i=0;i<4;i++) //get the ascii code for display
			if(key == SCAN_CODE[i]){
				return i;
			}
	}//if(temp3 != 0x00000000)
	return t;
}//end scan
