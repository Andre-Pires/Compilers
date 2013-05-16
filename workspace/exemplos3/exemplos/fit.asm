; DATA
segment	.data
; ALIGN
align	4
; LABEL
$PAGSIZ:
; INTEGER
	dd	1
; TEXT
segment	.text
; BSS
segment	.bss
; ALIGN
align	4
; LABEL
$null:
; BYTE
	resb	4
; TEXT
segment	.text
; DATA
segment	.data
; ALIGN
align	4
; LABEL
$base:
; INTEGER
	dd	1
; TEXT
segment	.text
; EXTRN
extern	$brk
; TEXT
segment	.text
; ALIGN
align	4
; GLOBL
global	$abs:function
; LABEL
$abs:
; ENTER
	push	ebp
	mov	ebp, esp
	sub	esp, 4
; LOCAL
	lea	eax, [ebp+12]
	push	eax
; LOAD
	pop	eax
	push	dword [eax]
; IMM
	push	dword 0
; JLT
	pop	eax
	pop	ecx
	cmp	ecx, eax
	jl	near $_i1
; LOCAL
	lea	eax, [ebp+12]
	push	eax
; LOAD
	pop	eax
	push	dword [eax]
; COPY
	push	dword [esp]
; LOCAL
	lea	eax, [ebp+-4]
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
	lea	eax, [ebp+12]
	push	eax
; LOAD
	pop	eax
	push	dword [eax]
; NEG
	neg	dword [esp]
; COPY
	push	dword [esp]
; LOCAL
	lea	eax, [ebp+-4]
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
global	$first:function
; LABEL
$first:
; ENTER
	push	ebp
	mov	ebp, esp
	sub	esp, 8
; LEAVE
	leave
; RET
	ret
; TEXT
segment	.text
; ALIGN
align	4
; GLOBL
global	$new:function
; LABEL
$new:
; ENTER
	push	ebp
	mov	ebp, esp
	sub	esp, 24
; LEAVE
	leave
; RET
	ret
; TEXT
segment	.text
; ALIGN
align	4
; GLOBL
global	$free:function
; LABEL
$free:
; ENTER
	push	ebp
	mov	ebp, esp
	sub	esp, 20
; LEAVE
	leave
; RET
	ret
; EXTRN
extern	$printi
; EXTRN
extern	$prints
; EXTRN
extern	$println
; TEXT
segment	.text
; ALIGN
align	4
; GLOBL
global	$dump:function
; LABEL
$dump:
; ENTER
	push	ebp
	mov	ebp, esp
	sub	esp, 8
; LEAVE
	leave
; RET
	ret
