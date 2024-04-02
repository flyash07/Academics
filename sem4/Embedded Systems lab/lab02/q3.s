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
	LDR R0, =SRC 
	LDR R1, =DST
	MOV R2, #0x26
	mov R4, #10
Loop1 

	STR R2,[R0],#4
	LDR R3,[R0]
	STR R3,[R1],#4
	ADDS R2,#4
	SUBS R4,#1
	BNE Loop1


	
STOP	B STOP ; Be there
; SRC location in data memory
	AREA mydata, DATA, READWRITE
SRC DCD 0,0,0,0,0,0,0,0,0,0
	AREA mydata1, DATA, READWRITE
DST DCD 0 ;DST location in data memory

	END