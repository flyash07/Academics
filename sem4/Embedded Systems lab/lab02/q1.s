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
	MOV R0, 0x05 ; Load address of SRC into R0
	LDR R1, =SRC ; Load the address of DST onto R1
	LDR R2, =0x36
	LDR R3, [R1]
	;LDR R3, [R0] ; Load data pointed by R0 into R3
	;STR R3,[R1] ; Store data from R3 into the address pointed by R1
SRC DCD 25
STOP	B STOP ; Be there
	END