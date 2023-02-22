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
	LDR R2, =10
	MOV R5, #0
UP	LDR R3, [R0],#4 
	ADDS R5,R5,R3
	
	SUBS R2, #1
	BNE UP 
	STR R5,[R1],#4
	
STOP B STOP 
SRC DCD 1, 1, 1, 1, 1, 1, 1, 1 ,1, 1 
	AREA MYDATA, DATA, READWRITE 
DST DCD 0
	END 