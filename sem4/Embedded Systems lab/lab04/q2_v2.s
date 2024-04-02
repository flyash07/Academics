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
	LDR R1, =packed
	LDR R2, =hex
	LDR R3,[R1]
	LDR R4, =0x01 
	LDR R5, =0xF  ;will store quotient
	MOV R0,#0
	LDR R7, =0X0A
		
LOOP	
	AND R6,R3,R5
	MLA R0,R6,R4,R0
	MUL R4,R7
	LSR R3,#4
	CMP R3,#0
	BNE LOOP
	
	STR R0,[R2]
	
STOP	B STOP ; Be there

packed DCD 0X00000267	;32 bit number - packed
	
	AREA mydata, DATA, READWRITE
hex DCD 0; packed result
	END