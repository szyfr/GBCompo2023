
;= Definitions
include "src/includes/hardware.inc"
include "src/constants.inc"

;= RAM
include "src/ram/hram.inc"
include "src/ram/sram.inc"
include "src/ram/vram.inc"
include "src/ram/wram.inc"


;= Home
include "src/home/reset_vectors.inc"
include "src/home/interrupts.inc"
include "src/home/copy_dma.inc"
include "src/home/memory.inc"
include "src/home/wait.inc"



section "Entry", rom0[$0100]
EntryPoint:
	nop
	jp  Start


section "Header", rom0[$0104]
ds $150 - @, 0
	
	
section "Start", rom0[$0150]
Start:

	;* Clear WRAM
	ld hl,_RAM
	ld bc,$2000
	xor a
	call mem_set

	;* Preserve SP
	ld sp,$DFFF

	;* Clear HRAM, then copy DMA
	ld hl,_HRAM
	ld bc,$007F
	xor a
	call mem_set
	call copy_dma

	;* Return stack to normal
	ld sp,$FFFE

	
	;ld hl,template_function
	;ld b,1
	;rst $00

.main_loop:
	jp .main_loop





;;= Bank 1
section "bank0", romx[$4000], bank[1]
db 1

template_function:
	ret

;;= Bank 2

