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
	LDR R1, =hex
	LDR R2, =unpacked
	LDR R3,[R1]
	LDR R4, =0xA
	LDR R5, =0 ;will store quotient
	MOV R0,#0
	LDR R7, =16
			
LOOP1
	MOV R6,R3

	CMP R6,#10
	BCC SKIP
DIV
	SUB R6,R4
	ADD R5,#1
	CMP R6,#10
	BCS DIV
	
	;NOW R6 HAS REMAINDER
SKIP
	STRB R6,[R2],#1  ; POST - INCREMENT
	LSR R3,#4
	CMP R3,#0
	BNE LOOP1
	
	;NOW AT [R6] WE HAVE UNPACKED BCD
	
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

	
hex DCD 0X0000001A	;32 bit number - packed
	
	AREA mydata, DATA, READWRITE
unpacked DCD 0
packed DCD 0; packed result
	END