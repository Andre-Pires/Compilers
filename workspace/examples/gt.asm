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
$a:
; BYTE
	resb	4
; TEXT
segment	.text
; BSS
segment	.bss
; ALIGN
align	4
; LABEL
$b:
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
; RODATA
segment	.rodata
; ALIGN
align	4
; LABEL
$_i1:
; CHAR
	db	0x43
; CHAR
	db	0x6F
; CHAR
	db	0x6D
; CHAR
	db	0x70
; CHAR
	db	0x61
; CHAR
	db	0x72
; CHAR
	db	0x61
; CHAR
	db	0x64
; CHAR
	db	0x6F
; CHAR
	db	0x72
; CHAR
	db	0x3A
; CHAR
	db	0x20
; CHAR
	db	0x6D
; CHAR
	db	0x61
; CHAR
	db	0x69
; CHAR
	db	0x6F
; CHAR
	db	0x72
; CHAR
	db	0x20
; CHAR
	db	0x71
; CHAR
	db	0x75
; CHAR
	db	0x65
; CHAR
	db	0x0A
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
; RODATA
segment	.rodata
; ALIGN
align	4
; LABEL
$_i2:
; CHAR
	db	0x49
; CHAR
	db	0x6E
; CHAR
	db	0x74
; CHAR
	db	0x72
; CHAR
	db	0x6F
; CHAR
	db	0x64
; CHAR
	db	0x75
; CHAR
	db	0x7A
; CHAR
	db	0x61
; CHAR
	db	0x20
; CHAR
	db	0x64
; CHAR
	db	0x6F
; CHAR
	db	0x69
; CHAR
	db	0x73
; CHAR
	db	0x20
; CHAR
	db	0x6E
; CHAR
	db	0x75
; CHAR
	db	0x6D
; CHAR
	db	0x65
; CHAR
	db	0x72
; CHAR
	db	0x6F
; CHAR
	db	0x73
; CHAR
	db	0x3A
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
	add	esp, 8
; PUSH
	push	eax
; TRASH
	add	esp, 4
; CALL
	call	$readi
; PUSH
	push	eax
; ADDR
	push	dword $a
; COPY
	push	dword [esp]
; STORE
	pop	ecx
	pop	eax
	mov	[ecx], eax
; TRASH
	add	esp, 4
; CALL
	call	$readi
; PUSH
	push	eax
; ADDR
	push	dword $b
; COPY
	push	dword [esp]
; STORE
	pop	ecx
	pop	eax
	mov	[ecx], eax
; TRASH
	add	esp, 4
; ADDR
	push	dword $a
; LOAD
	pop	eax
	push	dword [eax]
; ADDR
	push	dword $b
; LOAD
	pop	eax
	push	dword [eax]
; GT
	pop	eax
	xor	ecx, ecx
	cmp	[esp], eax
	setg	cl
	mov	[esp], ecx
; CALL
	call	$printi
; TRASH
	add	esp, 12
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
; IMM
	push	dword 0
; LOCAL
	lea	eax, [ebp+-4]
	push	eax
; COPY
	push	dword [esp]
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
