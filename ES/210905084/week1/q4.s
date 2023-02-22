	ALIGN
	AREA mycode,CODE, READONLY
	ENTRY
	EXPORT Reset_Handler
		
Reset_Handler
		LDR R0=SRC
		LDR r4=1
		mov r6,#10
		mov r7,#5
st		str r4,[r0],#4
		mul r4,r7
		subs r6,#1
		bne st
		sub r0,#4
		LDR R1,=SRC
		mov r5,#5
up		ldr r2,[r1]
		ldr r3,[r0]
		str r2,[r0],#4
		ldr r3,[r1],#4
		subs r5,#1
		bne up
STOP
		B STOP
		AREA mydata,DATA,READWRITE
SRC DCD 0
		END
		