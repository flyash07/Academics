
#include <LPC17xx.h>
#include "lcd.h" // use all the functions of lcd program
void scan_col(unsigned int);
void scan_row(void);
void calculate(void);
unsigned char Msg1[16] = "Calculating +/-";
unsigned char Msg2[7] = "   =  ";
unsigned char row, var, flag, key;  //flag2 for checking if 3 inputs are done
unsigned int i, var1, temp,flag2;
unsigned int row_num;
int j;
unsigned char SCAN_CODE[16] = {0x11,0x21,0x41,0x81,   //as scanned by the keyboard
															0x12,0x22,0x42,0x82,
															0x14,0x24,0x44,0x84,
															0x18,0x28,0x48,0x88};


unsigned char ASCII_CODE[16] = {'0','1','2','3',    //what we think when we enter
																'4','5','6','7',
																'8','9','+','-',
																' ',' ',' ',' '};


int main(void){
	
	
	SystemInit();
	SystemCoreClockUpdate();
	
	LPC_GPIO2->FIODIR |= 0x00003C00; //made output P2.10 to P2.13 (rows)                   0000 0011 1100 0000 0000
	LPC_GPIO1->FIODIR &= 0xF87FFFFF; //made input P1.23 to P1.26(cols)      1111 1000 0111 1111 1111 1111 1111 1111   

	lcd_init();	
	lcd_comdata(0x80, 0);
	delay_lcd(800);        //initial display of message
	lcd_puts(&Msg1[0]);
	
	while(1){
		flag2=0;
		
		scan_row(); //scanning for first digit
		flag2++;
		
		for(j=0;j<100000;j++);
		
		scan_row(); //scanning for operator
		flag2++;
		for(j=0;j<100000;j++);
		
		
		scan_row(); //scanning for second digit
		flag2++;
		for(j=0;j<100000;j++);
		
		calculate();
		
		for(j=0;j<100000;j++);
		
	}

}//end main

void scan_row(){
	
	while(1){
			for(row=1;row<5;row++){
				if(row == 1)
					var1 = 0x00000400;
				else if(row == 2)
					var1 = 0x00000800;
				else if(row == 3)
					var1 = 0x00001000;
				else if(row == 4)
					var1 = 0x00002000;
				LPC_GPIO2->FIOCLR = 0x00003C00; //first clear the port and send appropriate value for
				LPC_GPIO2->FIOSET = var1; //enabling the row
				flag = 0;
				scan_col(var1); //scan if any key pressed in the enabled row
				if(flag == 1)
					break;
			} //end for
			if(flag == 1)
				break;
	} // while(1)
	for(i=0;i<16;i++) //get the ascii code for display
			if(key == SCAN_CODE[i]){
				key = ASCII_CODE[i];
				Msg2[flag2]=key;
				break;
			} //end if(key == SCAN_CODE[i])
		lcd_comdata(0xC0,0);//display in the second line
		delay_lcd(800);
		lcd_puts(&Msg2[0]);
	
}


void scan_col(unsigned int rown){
	
	temp = LPC_GPIO1->FIOPIN;
	temp &= 0x07800000; //check if any key pressed in the enabled row
	if(temp){   //if key is pressend, fiopin corresponding bit becomes 1
		flag = 1;
		temp >>= 19; //Shifted to come at HN of byte
		rown >>= 10; //shifted to come at LN of byte
		key = temp|rown; //get SCAN_CODE
	}//if(temp3 != 0x00000000)
}//end scan

void calculate(){
	int sum;
	int d1=Msg2[0]- 0x30;
	int d2=Msg2[2] - 0x30;
	
	if(Msg2[1]=='+')
		sum=d1+d2;
	else
		sum=d1-d2;
	
	if(sum/10==0){
		Msg2[4]=sum+0x30;
		Msg2[5]=' ';
	}
	else{
		Msg2[4]= 0x31;
		Msg2[5]=(sum%10) + 0x30;
	}
	lcd_comdata(0xC0,0);//display in the second line
	delay_lcd(800);
	lcd_puts(&Msg2[0]);
}
