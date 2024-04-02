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
	MOV R4,#0
	MOV R1,#4
	LDR R0, =list
	LDR R2, =result
L1 
	LDR R3, [R0,R4]
	STR R3, [R2,R4]
	ADD R4,#4
	SUB R1,#1
	CMP R1,#0
	BNE L1
	mov r5, #3 ; outer counter
	LDR R0, =result
	
outer	
	
	MOV r1,r0 ; has the min value rn
	mov r9,r0; i
	mov r2,r0  ;i+1 = j
	add r0,#1
	mov r8, #4 ; inner counter
	
inner
	add r2,#1 ;j variable
	ldr r3,[r1] ;arr[min]
	ldr r4,[r2] ;arr[j]
	cmp r3,r4
	bcc skip
	mov r1,r2
skip
	SUBS R8,#1
	BNE inner
	ldr r6,[r1]
	ldr r7,[r9]
	str r7,[r1]
	str r6,[r9]
	SUBS R5,#1
	BNE outer
STOP B STOP
	
	
list DCD 0x10,0x05,0x33,0x24
	AREA data1, DATA, READWRITE
result DCD 0,0,0,0,0,0,0,0,0,0
	end