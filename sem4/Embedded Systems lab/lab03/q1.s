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
	LDR R1, =V1 
	LDR R2, =V2
	LDR R3, =V3
	LDR R4,[R1]
	LDR R5,[R2]
	sub R0,R5,R4
	STR R0,[R3]
V1 DCD 0X12345678 ; First 32 bit number
V2 DCD 0XABCDEF12 ; Second 32 bit number
STOP	B STOP ; Be there
	AREA mydata, DATA, READWRITE
V3 DCD 0
	END