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
	    LDR r6, = result
		MOV r2, #00
		LDR r0, = value1
		LDR r1, [r0]
		LDR r0, = value2
		LDR r3, [r0]
UP
	    CMP r1,r3
		BCC STORE
		SUB r1,r3
		ADD r2,#01
		B UP
STORE
	    STR r2,[r6], #4
		STR r1,[r6]
STOP
	    B STOP
value1 DCD 12
value2 DCD 4
		AREA mydata,DATA,READWRITE
result DCD 0
		END 