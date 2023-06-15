
; 
macro banked_call
	ld a,\1
	ld hl,\2
	rst $00
endm