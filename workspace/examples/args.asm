; EXTRN
extern	$prints
; EXTRN
extern	$printi
; EXTRN
extern	$println
; EXTRN
extern	$readi
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
; RODATA
segment	.rodata
; ALIGN
align	4
; LABEL
$_i2:
; CHAR
	db	0x61
; CHAR
	db	0x72
; CHAR
	db	0x67
; CHAR
	db	0x63
; CHAR
	db	0x20
; CHAR
	db	0x3D
; CHAR
	db	0x20
; CHAR
	db	0x00
; TEXT
segment	.text
; ADDR
	push	dword $_i2
; CALL
	call	$prints
; TRASH
	add	esp, 4
; PUSH
	push	eax
; TRASH
	add	esp, 4
; ADDR
	push	dword $argc
; LOAD
	pop	eax
	push	dword [eax]
; CALL
	call	$printi
; TRASH
	add	esp, 8
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
	push	dword $argc
; LOAD
	pop	eax
	push	dword [eax]
; IMM
	push	dword 1
; JLE
	pop	eax
	pop	ecx
	cmp	ecx, eax
	jle	near $_i1
; RODATA
segment	.rodata
; ALIGN
align	4
; LABEL
$_i3:
; CHAR
	db	0x61
; CHAR
	db	0x72
; CHAR
	db	0x67
; CHAR
	db	0x76
; CHAR
	db	0x5B
; CHAR
	db	0x31
; CHAR
	db	0x5D
; CHAR
	db	0x20
; CHAR
	db	0x3D
; CHAR
	db	0x20
; CHAR
	db	0x00
; TEXT
segment	.text
; ADDR
	push	dword $_i3
; CALL
	call	$prints
; TRASH
	add	esp, 12
; PUSH
	push	eax
; TRASH
	add	esp, 4
; ADDR
	push	dword $argv
; LOAD
	pop	eax
	push	dword [eax]
; CALL
	call	$prints
; TRASH
	add	esp, 16
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
; LABEL
$_i1:
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
