

;= The sequence showing my (current) logo and the one for the compo
;= Probably a better way, but fuck it, it works.
logo_sequence:
	ld a,%00011011
	ldh [rBGP],a
	call fade_out

	;* Wait for v-blank
	call wait_vblank

	;* Copy Szy Logo
	ld hl,szy_logo
	ld bc,szy_logo.end-szy_logo
	ld de,_VRAM+$01A0
	call mem_cpy

	;* Copy GBCompo Logo
	ld hl,gb_logo
	ld bc,gb_logo.end - gb_logo
	ld de,_VRAM+$01A0+szy_logo.end-szy_logo
	call mem_cpy

	;* Draw Szy logo
	ld hl,$9AA7
	ld a,$1A
	ld b,4
	ld de,26
.outer_loop_tile:
	ld c,6
.inner_loop_tile:
	ld [hl+],a
	inc a
	dec c
	jr nz,.inner_loop_tile

	add hl,de
	dec b
	jr nz,.outer_loop_tile

	;* Draw GBCompo logo
	ld hl,$9A95
	ld a,$33
	ld b,7
	ld de,23
.outer_loop_tile_2:
	ld c,9
.inner_loop_tile_2:
	ld [hl+],a
	inc a
	dec c
	jr nz,.inner_loop_tile_2

	add hl,de
	dec b
	jr nz,.outer_loop_tile_2

	;* Turn on LCD and set y
	ld a,LCDCF_ON|LCDCF_BG8000|LCDCF_BGON
	ld [rLCDC],a
	ld a,112
	ldh [rSCY],a

	call fade_in

	ld bc,4
	call long_wait

	ld d,$7C
	call pan_right

	ld bc,4
	call long_wait

	call fade_out

	ld bc,4
	call long_wait

	xor a
	ldh [rSCX],a
	ldh [rSCY],a

	ret

pan_right:
	ld bc,$0800
	call wait

	ld a,[rSCX]
	inc a
	cp d
	ld [rSCX],a
	jr nz,pan_right

	ret



reverse_palette:
	ld a,[rBGP]
	cpl
	ld [rBGP],a
	ret


fade_out:
	ld a,%01101111
	ldh [rBGP],a
	ld bc,$A000
	call wait

	ld a,%10111111
	ldh [rBGP],a
	ld bc,$A000
	call wait

	ld a,%11111111
	ldh [rBGP],a
	ld bc,$A000
	call wait

	ret

fade_in:
	ld a,%10111111
	ldh [rBGP],a
	ld bc,$A000
	call wait

	ld a,%01101111
	ldh [rBGP],a
	ld bc,$A000
	call wait

	ld a,%00011011
	ldh [rBGP],a
	ld bc,$A000
	call wait

	ret