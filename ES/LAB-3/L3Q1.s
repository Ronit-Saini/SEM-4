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
	LDR R6,=RESULT
	MOV R2,#00
	LDR R0,=VALUE1
	LDR R1,[R0]
	LDR R0,=VALUE2
	LDR R3,[R0]
up 	cmp R1,R3
	bcc store
	sub R1,R3
	ADD R2,#01
	B up
store STR R2,[R6],#4
	STR R1,[R6]
STOP
	B STOP
VALUE1 DCD 10
VALUE2 DCD 2
		AREA data,DATA,READWRITE
RESULT DCD 0,0
		END