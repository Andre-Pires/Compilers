; EXTRN
extern	$prints
; EXTRN
extern	$printi
; EXTRN
extern	$readi
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
; BSS
segment	.bss
; ALIGN
align	4
; LABEL
$c:
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
; CALL
	call	$readi
; PUSH
	push	eax
; COPY
	push	dword [esp]
; ADDR
	push	dword $x
; STORE
	pop	ecx
	pop	eax
	mov	[ecx], eax
; TRASH
	add	esp, 4
; IMM
	push	dword 4
; NEG
	neg	dword [esp]
; COPY
	push	dword [esp]
; ADDR
	push	dword $b
; STORE
	pop	ecx
	pop	eax
	mov	[ecx], eax
; TRASH
	add	esp, 4
; ADDR
	push	dword $b
; LOAD
	pop	eax
	push	dword [eax]
; COPY
	push	dword [esp]
; ADDR
	push	dword $c
; STORE
	pop	ecx
	pop	eax
	mov	[ecx], eax
; TRASH
	add	esp, 4
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
; ADDR
	push	dword $b
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
; ADDR
	push	dword $c
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
; ADDR
	push	dword $x
; LOAD
	pop	eax
	push	dword [eax]
; IMM
	push	dword 0
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
$_i4:
; CHAR
	db	0x70
; CHAR
	db	0x6F
; CHAR
	db	0x73
; CHAR
	db	0x69
; CHAR
	db	0x74
; CHAR
	db	0x69
; CHAR
	db	0x76
; CHAR
	db	0x6F
; CHAR
	db	0x21
; CHAR
	db	0x0A
; CHAR
	db	0x00
; TEXT
segment	.text
; ADDR
	push	dword $_i4
; CALL
	call	$prints
; TRASH
	add	esp, 4
; PUSH
	push	eax
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
	push	dword 0
; JGE
	pop	eax
	pop	ecx
	cmp	ecx, eax
	jge	near $_i2
; RODATA
segment	.rodata
; ALIGN
align	4
; LABEL
$_i5:
; CHAR
	db	0x6E
; CHAR
	db	0x65
; CHAR
	db	0x67
; CHAR
	db	0x61
; CHAR
	db	0x74
; CHAR
	db	0x69
; CHAR
	db	0x76
; CHAR
	db	0x6F
; CHAR
	db	0x21
; CHAR
	db	0x0A
; CHAR
	db	0x00
; TEXT
segment	.text
; ADDR
	push	dword $_i5
; CALL
	call	$prints
; TRASH
	add	esp, 4
; PUSH
	push	eax
; TRASH
	add	esp, 4
; LABEL
$_i2:
; ADDR
	push	dword $x
; LOAD
	pop	eax
	push	dword [eax]
; IMM
	push	dword 0
; JNE
	pop	eax
	pop	ecx
	cmp	ecx, eax
	jne	near $_i3
; RODATA
segment	.rodata
; ALIGN
align	4
; LABEL
$_i6:
; CHAR
	db	0x6E
; CHAR
	db	0x75
; CHAR
	db	0x6C
; CHAR
	db	0x6F
; CHAR
	db	0x21
; CHAR
	db	0x0A
; CHAR
	db	0x00
; TEXT
segment	.text
; ADDR
	push	dword $_i6
; CALL
	call	$prints
; TRASH
	add	esp, 4
; PUSH
	push	eax
; TRASH
	add	esp, 4
; LABEL
$_i3:
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
