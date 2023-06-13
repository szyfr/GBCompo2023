

;= Copy memory
;= * hl-Source
;= * de-Destination
;= * bc-Length
mem_cpy:
	ld a,[hl+]
	ld [de],a
	inc de
	dec bc
	ld a,c
	or b
	jr nz,mem_cpy

	ret


;= Clear memory
;= * hl-Destination
;= * bc-Length
;= * a-Value
mem_set:
	ld d,a
.loop:
	ld [hl],d
	inc hl
	dec bc

	ld a,c
	or b
	jr nz,.loop

	ret