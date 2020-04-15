	   AREA    |.text|, CODE, READONLY
       ALIGN        ; Ensures alignment. Functiondirective doesn't do it transparent
ModeState_ISR   PROC
				EXPORT  ModeState_ISR
		MOV     r0, #10		; Dummy
		MOV     r1, #3
				ENDP
					
		END
						
       ALIGN        ; Ensures alignment. Functiondirective doesn't do it transparent
; Chapter 11, 11.3 Software trigger		   
Call_ModeState_ISR   PROC
				EXPORT  Call_ModeState_ISR
		MOV     r0, #6		; ISR num on vector table
		LDR     r1, =0xE000EF00
		STR		r0, [r1]
		DSB
					ENDP
		END
						