

;= Wait for VBlank
wait_vblank:
	ldh a,[rLY]
	cp 144
	jp c,wait_vblank

	ld a,0
	ld [rLCDC],a

	ret


;= Waits bc loops
;= * bc-Count
wait:
	nop
	nop
	nop
	dec bc
	ld a,c
	or b
	jr nz,wait

	ret


;= Waits bc waits
;= * bc-Count
long_wait:
	push bc

	ld bc,$FFFF
	call wait

	pop bc
	dec bc
	ld a,c
	or b
	jr nz,long_wait

	ret