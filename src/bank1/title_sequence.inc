

title_sequence:
	ld a,112
	ldh [rSCY],a
	ld a,4
	ldh [rSCX],a

	;* Copy tiles
	ld hl,intro_tiles
	ld bc,test_char_2.end-intro_tiles
	ld de,_VRAM+$0000
	call mem_cpy

	;* Copy map
	ld hl,intro_map
	ld bc,intro_map.end - intro_map
	ld de,_VRAM+$1800
	call mem_cpy

	;* Copy sprite
	ld hl,_OAMRAM
	ld a,0
	ld [hl+],a
	ld a,9 * 8
	ld [hl+],a
	ld a,$0B
	ld [hl+],a
	ld a,0
	ld [hl+],a

	ld a,0
	ld [hl+],a
	ld a,10 * 8
	ld [hl+],a
	ld a,$0C
	ld [hl+],a
	ld a,0
	ld [hl+],a

	ld a,1 * 8
	ld [hl+],a
	ld a,9 * 8
	ld [hl+],a
	ld a,$0D
	ld [hl+],a
	ld a,0
	ld [hl+],a

	ld a,1 * 8
	ld [hl+],a
	ld a,10 * 8
	ld [hl+],a
	ld a,$0E
	ld [hl+],a
	ld a,0
	ld [hl+],a



	ld a,LCDCF_ON|LCDCF_BG8000|LCDCF_BGON|LCDCF_OBJ16|LCDCF_OBJON
	ld [rLCDC],a

	call fade_in

.loop:
	call wait_vblank
	
	ld a,[_OAMRAM+0]
	inc a
	ld [_OAMRAM+0],a

	ld a,[_OAMRAM+4]
	inc a
	ld [_OAMRAM+4],a

	ld a,[_OAMRAM+8]
	inc a
	ld [_OAMRAM+8],a

	ld a,[_OAMRAM+12]
	inc a
	ld [_OAMRAM+12],a

	ld a,LCDCF_ON|LCDCF_BG8000|LCDCF_BGON|LCDCF_OBJ8|LCDCF_OBJON
	ld [rLCDC],a

	ld bc,$1000
	call wait

	jp .loop

	ret