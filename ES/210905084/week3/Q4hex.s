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
	    LDR r0, = num
		LDR r3, = result
		LDR r1, [r0]
		AND r2, r1,#0x0F 
		CMP r2, #09
		BLS DOWN
		ADD r2,#07
DOWN
	    
		ADD r2,#0x30
		STRB r2,[r3]
		AND r4,r1,#0xF0
		MOV r4,r4, LSR #04
		CMP r4,#09
		BLS DOWN1
		ADD r4,#07
		
DOWN1
	    ADD r4,#0x30
		STRB r4,[r3,#01]
STOP
	    B STOP
num DCD 0x12

		AREA mydata,DATA,READWRITE
result DCD 0
		END 