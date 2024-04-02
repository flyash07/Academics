	AREA RESET, DATA, READONLY
	EXPORT __Vectors
__Vectors
	DCD 0x10001000 ; stack pointer value when stack is empty
	DCD Reset_Handler ; reset vector
	ALIGN
	AREA mycode, CODE, READONLY
	ENTRY
	EXPORT Reset_Handler
Reset_Handler
	LDR R1, =10
	LDR R2, =200
	LDR R3, =0x00
	
Loop
	
	SUBS R2,R1
	ADD R3,#1
	BNE Loop

STOP	B STOP 
	END