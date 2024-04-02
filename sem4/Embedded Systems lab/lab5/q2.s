	AREA RESET, DATA, READONLY
	EXPORT __Vectors
__Vectors
	DCD 0x40001000 ; stack pointer value when stack is empty
	DCD Reset_Handler ; reset vector
	ALIGN
	AREA mycode, CODE, READONLY
	ENTRY
	EXPORT Reset_Handler
Reset_Handler
	MOV R0,#1
	LDR R1,=X
	LDR R3,[R1]
	BL factorial
	LDR R3,=result
	STR R0, [R3]

Stop B Stop

X DCD 4

factorial
	MUL R0,R0,R3
	SUBS R3,#1
	BNE factorial
	BX LR
	AREA mydara,DATA,READWRITE
result DCD 0
	END