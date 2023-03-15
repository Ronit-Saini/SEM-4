	AREA RESET,DATA,READONLY
	EXPORT __Vectors
__Vectors
	DCD 0x10001000
	DCD Reset_Handler
	ALIGN
	AREA mycode,CODE,READONLY
	ENTRY
	EXPORT Reset_Handler	
Reset_Handler
	LDR R0,=N
	LDR R6,=RESULT
	LDR R1,[R0]
	LDR R2,[R0]
	;MOV R3,#0xFFFF0000
	MOV R3,#0xFFFF
	LSL R3,#16
	MOV R7,#0xFFFF
	AND R1,R3
	LSR R1,#16
	AND R2,R7
	MUL R5,R1,R2
	STR R5,[R6]
STOP	
	B STOP
N DCD 0x12345678
	AREA mydata,DATA,READWRITE
RESULT DCD 0
	END