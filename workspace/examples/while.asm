; EXTRN
extern	$printi
; EXTRN
extern	$println
; BSS
segment	.bss
; ALIGN
align	4
; LABEL
$x:
; BYTE
	resb	4
; TEXT
segment	.text
; TEXT
segment	.text
; ALIGN
align	4
; GLOBL
global	$_entry:function
; LABEL
$_entry:
; ENTER
	push	ebp
	mov	ebp, esp
	sub	esp, 4
; JMP
	jmp	dword $_i1
; LABEL
$_i2:
; ADDR
	push	dword $x
; LOAD
	pop	eax
	push	dword [eax]
; CALL
	call	$printi
; TRASH
	add	esp, 4
; PUSH
	push	eax
; TRASH
	add	esp, 4
; CALL
	call	$println
; PUSH
	push	eax
; TRASH
	add	esp, 4
; ADDR
	push	dword $x
; COPY
	push	dword [esp]
; ADDR
	push	dword $x
; LOAD
	pop	eax
	push	dword [eax]
; IMM
	push	dword 1
; ADD
	pop	eax
	add	dword [esp], eax
; SWAP
	pop	eax
	pop	ecx
	push	eax
	mov	eax, ecx
	push	eax
; STORE
	pop	ecx
	pop	eax
	mov	[ecx], eax
; TRASH
	add	esp, 4
; LABEL
$_i1:
; ADDR
	push	dword $x
; LOAD
	pop	eax
	push	dword [eax]
; IMM
	push	dword 30
; JLT
	pop	eax
	pop	ecx
	cmp	ecx, eax
	jl	near $_i2
; LOCAL
	lea	eax, [ebp+-4]
	push	eax
; COPY
	push	dword [esp]
; IMM
	push	dword 0
; SWAP
	pop	eax
	pop	ecx
	push	eax
	mov	eax, ecx
	push	eax
; STORE
	pop	ecx
	pop	eax
	mov	[ecx], eax
; TRASH
	add	esp, 4
; LEAVE
	leave
; RET
	ret
