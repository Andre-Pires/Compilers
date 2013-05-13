; TEXT
segment	.text
; ALIGN
align	4
; GLOBL
global	$prints:function
; LABEL
$prints:
; ENTER
	push	ebp
	mov	ebp, esp
	sub	esp, 0
; LEAVE
	leave
; RET
	ret
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
	sub	esp, 0
; ADDRV
	push	dword [$cnt]
; ADDRV
	push	dword [$cnt]
; IMM
	push	dword 1
; ADD
	pop	eax
	add	dword [esp], eax
; COPY
	push	dword [esp]
; ADDR
	push	dword $cnt
; STORE
	pop	ecx
	pop	eax
	mov	[ecx], eax
; ADDRV
	push	dword [$n]
; IMM
	push	dword 1
; JGT
	pop	eax
	pop	ecx
	cmp	ecx, eax
	jg	near $_i1
; ADDRV
	push	dword [$fibonacci]
; ADDRV
	push	dword [$n]
; COPY
	push	dword [esp]
; ADDR
	push	dword $fibonacci
; STORE
	pop	ecx
	pop	eax
	mov	[ecx], eax
; JMP
	jmp	dword $_i2
; LABEL
$_i1:
; ADDRV
	push	dword [$fibonacci]
; ADDRV
	push	dword [$n]
; IMM
	push	dword 1
; SUB
	pop	eax
	sub	dword [esp], eax
; CALL
	call	$fibonacci
; TRASH
	add	esp, 0
; ADDRV
	push	dword [$n]
; IMM
	push	dword 2
; SUB
	pop	eax
	sub	dword [esp], eax
; CALL
	call	$fibonacci
; TRASH
	add	esp, 0
; ADD
	pop	eax
	add	dword [esp], eax
; COPY
	push	dword [esp]
; ADDR
	push	dword $fibonacci
; STORE
	pop	ecx
	pop	eax
	mov	[ecx], eax
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
	sub	esp, 4
; LEAVE
	leave
; RET
	ret
