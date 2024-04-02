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
VAL RN R1
	LDR R1, =N
	LDR R2,[R1]	
	MLA R3,R2,R2,R2
	MOV R4,R3,LSR #1
	
	
	LDR R6,=0x0FFF0FFF
	MOV R8,R6, ASR #1


STOP	B STOP 

	
N DCD 5
	END