; EXTRN
extern	$prints
; EXTRN
extern	$printd
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
$_i1:
; CHAR
	db	0x2D
; CHAR
	db	0x70
; CHAR
	db	0x69
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
	push	dword $_i1
; CALL
	call	$prints
; TRASH
	add	esp, 4
; PUSH
	push	eax
; TRASH
	add	esp, 4
; ADDR
	push	dword $pi
; LOAD
	pop	eax
	push	dword [eax]
; CALL
	call	$printd
; TRASH
	add	esp, 4
; PUSH
	push	eax
; TRASH
	add	esp, 4
; RODATA
segment	.rodata
; ALIGN
align	4
; LABEL
$_i2:
; CHAR
	db	0x0A
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
; IMM
	push	dword 0
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
; LEAVE
	leave
; RET
	ret
