; TEXT
segment	.text
; ALIGN
align	4
; GLOBL
global	$printi:function
; LABEL
$printi:
; ENTER
	push	ebp
	mov	ebp, esp
	sub	esp, 0
; LEAVE
	leave
; RET
	ret
; EXTRN
extern	$println
; EXTRN
extern	$readi
; TEXT
segment	.text
; ALIGN
align	4
; GLOBL
global	$entry:function
; LABEL
$entry:
; ENTER
	push	ebp
	mov	ebp, esp
	sub	esp, 0
; CALL
	call	$printi
; TRASH
	add	esp, 0
; CALL
	call	$println
; TRASH
	add	esp, 0
; ADDRV
	push	dword [$entry]
; IMM
	push	dword 0
; COPY
	push	dword [esp]
; ADDR
	push	dword $entry
; STORE
	pop	ecx
	pop	eax
	mov	[ecx], eax
; LEAVE
	leave
; RET
	ret
