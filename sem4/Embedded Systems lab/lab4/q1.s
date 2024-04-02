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
	LDR R1, =unpacked
	LDR R2, =packed
	LDR R3,[R1]
	LDR R4, =0X0F
	MOV R8, #0
	
LOOP
	LDR R5, =0
	AND R5, R3,R4
	LSR R5,R8
	ADD R0,R5
	ADD R8,#4
	LSL R4,#8
	CMP R8,#16
	BNE LOOP
	STR R0,[R2]
	
STOP	B STOP ; Be there
unpacked DCD 0X02040607 ;32 bit number - unpacked
	
	AREA mydata, DATA, READWRITE
packed DCD 0; packed result
	END