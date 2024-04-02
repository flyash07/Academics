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
	LDR R4, =16  ; divisor
	LDR R5, =0  ;will store quotient
	MOV R6, #0  ; will keep remainders
	MOV R3, R5  ; copy of dividend
	LDR R7, =0 ;LSR COUNT
	
	
	
LOOP	
	B DIV
	LSR R3,R7
	ADD R0,R3
	ADD R7,#4
	MOV R3,R5
	MOV R5,#0
	CMP R3,#0
	BNE LOOP
	STR R0,[R2]
	
STOP	B STOP ; Be there
DIV
	SUBS R3,R4
	ADD R5,#1
	CMP R3,#16 
	BCS DIV
	B LOOP
packed DCD 0X00002467 ;32 bit number - packed


	
	AREA mydata, DATA, READWRITE
hex DCD 0; packed result
	END