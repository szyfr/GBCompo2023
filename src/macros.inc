
; 
macro banked_call
	ld b,\1
	ld hl,\2
	rst $00
endm