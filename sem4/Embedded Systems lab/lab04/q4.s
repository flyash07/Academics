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
	LDR R1, =packed1
	LDR R2, =packed2
	LDR R3,[R1]
	LDR R4,[R2]	
	LDR R7, =0 ; CARRY
	LDR R0, =0 ; WILL KEEP RESULT
	LDR R8, =0 ; WILL KEEP TRACK OF THE PLACE
	
extract	
	AND R5,R3,#0x0F ;will store quotient
	AND R6,R4,#0x0F
	ADD R6,R5
	ADD R6,R7 ; ADDING CARRY
	MOV R7,#0
	
	CMP R6,#10
	BCC SKIP
	SUB R6,#10  ; -10 AND CARRY MADE
	ADD R7,#1
	
SKIP
	LSL R6,R8 ;UNITS/TENTHS/HUNDRETHS
	ADD R0,R6
	ADD R8,#4
	LSR R3,#4
	LSR R4,#4
	CMP R3,#0
	BNE extract
	CMP R4,#0
	BNE extract
	
	LDR R1,=result
	STR R0,[R1]
		
STOP	B STOP ; Be there

	
packed1 DCD 0X00000012	;32 bit number - packed
packed2 DCD 0x00000349
	
	AREA mydata, DATA, READWRITE
result DCD 0
	END