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
	LDR R1, =0x1015ABC6 
	STR R1, [R0]
	LDR R2, =DST
	STR R1,[R2]
	
STOP	B STOP ; Be there

	AREA mydata, DATA, READWRITE
DST DCD 0 ;DST location in data memory
SRC DCD 0 ; SRC location in data memory
	END