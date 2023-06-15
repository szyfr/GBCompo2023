
SECTION "Reset Vectors", ROM0[$0000]

SECTION "rst00", ROM0[$0000]
;= Local jumptable
;= * hl-FunctionPTR
;= * b-ROMBank
RST00:
	;* Save ROM bank
	ld a,[rROMB]
	push af

	;* Set new bank
	ld a,b
	ld [rROMB0],a

	;* Call function
	rst $10

	;* Return to original bank
	pop af
	ld [rROMB0],a

	ret


SECTION "rst10", ROM0[$0010]
;= Jump to hl
RST10:
	jp hl


SECTION "rst18", ROM0[$0018]
;= Copy from bank
RST18:
	ret
;	ld a,[rROMB]
;	push af
;
;	ld a,b
;	ld [rROMB],a
;
;
;	call mem_cpy