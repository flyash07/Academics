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
	LDR R2, =20
	MUL R3,R1,R2
	LDR R4, =0x12345678
	LDR R5, =0xABBBBBBB
	UMULL R7,R6,R5,R4

STOP	B STOP 
	END