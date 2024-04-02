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
	LDR R1, =N1
	LDR R2, =N2
	LDR R3,[R1]
	LDR R4,[R2]
	B GCD
	
updation1
	SUB R3,R3,R4
	B GCD
updation2
	SUB R4,R4,R3
	B GCD
GCD
	CMP R3,R4
	BEQ OUT
	BCS updation1
	BCC updation2

OUT
	LDR R4,=g
	STR R3,[R4]
	LDR R3,[R1]
	LDR R4,[R2]
	

	
N1 DCD 5
N2 DCD 6

STOP	B STOP 
	END
	AREA mydata, DATA, READONLY
g  DCD 0
l  DCD 0