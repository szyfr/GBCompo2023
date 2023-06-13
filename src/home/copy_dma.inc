

section "dma", rom0[$0080]

; Copy DMA transfer function to HRAM
copy_dma:
	ld c,_HRAM_START
	ld b,call_dma.end - call_dma
	ld hl,dma_data

.loop:
	ld a,[hl+]
	ldh [c],a
	inc c
	dec b
	jr nz,.loop

	ret


dma_data:
	load "call dma", hram
call_dma:
	ld a,$C0
	ldh [rDMA],a
	ld a,$28
.loop:
	dec a
	jr nz,.loop
	ret
.end:
	endl