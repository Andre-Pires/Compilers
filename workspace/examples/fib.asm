; EXTRN
extern	$prints
; EXTRN
extern	$printi
; EXTRN
extern	$println
; EXTRN
extern	$readi
; BSS
segment	.bss
; ALIGN
align	4
; LABEL
$cnt:
; BYTE
	resb	4
; TEXT
segment	.text
; TEXT
segment	.text
; ALIGN
align	4
; GLOBL
global	$fibonacci:function
; LABEL
$fibonacci:
; ENTER
	push	ebp
	mov	ebp, esp
	sub	esp, 4
; ADDR
	push	dword $cnt
; COPY
	push	dword [esp]
; ADDR
	push	dword $cnt
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
; ADDR
	push	dword $n
; LOAD
	pop	eax
	push	dword [eax]
; IMM
	push	dword 1
; JGT
	pop	eax
	pop	ecx
	cmp	ecx, eax
	jg	near $_i1
; LOCAL
	lea	eax, [ebp+-4]
	push	eax
; COPY
	push	dword [esp]
; ADDR
	push	dword $n
; LOAD
	pop	eax
	push	dword [eax]
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
; JMP
	jmp	dword $_i2
; LABEL
$_i1:
; LOCAL
	lea	eax, [ebp+-4]
	push	eax
; COPY
	push	dword [esp]
; ADDR
	push	dword $n
; LOAD
	pop	eax
	push	dword [eax]
; IMM
	push	dword 1
; SUB
	pop	eax
	sub	dword [esp], eax
; CALL
	call	$fibonacci
; TRASH
	add	esp, 4
; PUSH
	push	eax
; ADDR
	push	dword $n
; LOAD
	pop	eax
	push	dword [eax]
; IMM
	push	dword 2
; SUB
	pop	eax
	sub	dword [esp], eax
; CALL
	call	$fibonacci
; TRASH
	add	esp, 8
; PUSH
	push	eax
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
$_i2:
; LEAVE
	leave
; RET
	ret
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
	sub	esp, 8
; LEAVE
	leave
; RET
	ret
