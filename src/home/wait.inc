

;= Wait for VBlank
wait_vblank:
	ldh a,[rLY]
	cp 144
	jp c,wait_vblank

	ld a,0
	ld [rLCDC],a

	ret


;= Waits bc loops
wait:
	nop
	nop
	nop
	dec bc
	ld a,c
	or b
	jr nz,wait

	ret