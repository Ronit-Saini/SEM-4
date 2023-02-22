	AREA RESET, DATA, READONLY
	EXPORT __Vectors
__Vectors
	DCD 0x10001000
	DCD Reset_Handler
	ALIGN
	AREA mycode, CODE, READONLY
	ENTRY 
	EXPORT Reset_Handler
Reset_Handler
	LDR R6,=RESULT
	MOV R2,#0
	LDR R0,=VALUE1
	LDR R1,[R0]
UP 	CMP R1,#0xa
	bcc store
	sub r1,#0xa
	add r2,#01
	B UP
store strb r1,[r6],#1
      mov r1,r2
	  mov r2,#0
	  cmp r1,#0xa
	  bcs UP
	strb r1,[r6],#1
	mov r3,r6
	ldr r2,=packed
	ldr r6,=RESULT
up1	ldrb r0,[r6],#1
	ldrb r1,[r6],#1
	lsl r1,#4
	orr r1,r0
	strb r1,[r2],#1
	sub r4,#2
	sub r4,#1
	BGE up1
STOP
	B STOP
VALUE1 DCD 0x0035
	
	AREA mydata,DATA,READWRITE	
RESULT DCD 0
packed DCD 0
	END