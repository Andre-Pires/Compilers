; EXTRN
extern	$prints
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
; RODATA
segment	.rodata
; ALIGN
align	4
; LABEL
$_i21:
; CHAR
	db	0x69
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
	db	0x61
; CHAR
	db	0x73
; CHAR
	db	0x20
; CHAR
	db	0x64
; CHAR
	db	0x69
; CHAR
	db	0x6D
; CHAR
	db	0x65
; CHAR
	db	0x6E
; CHAR
	db	0x73
; CHAR
	db	0xC3
; CHAR
	db	0xB5
; CHAR
	db	0x65
; CHAR
	db	0x73
; CHAR
	db	0x20
; CHAR
	db	0x64
; CHAR
	db	0x6F
; CHAR
	db	0x20
; CHAR
	db	0x70
; CHAR
	db	0x72
; CHAR
	db	0x69
; CHAR
	db	0x6D
; CHAR
	db	0x65
; CHAR
	db	0x69
; CHAR
	db	0x72
; CHAR
	db	0x6F
; CHAR
	db	0x20
; CHAR
	db	0x6C
; CHAR
	db	0x61
; CHAR
	db	0x64
; CHAR
	db	0x6F
; CHAR
	db	0x20
; CHAR
	db	0x64
; CHAR
	db	0x6F
; CHAR
	db	0x20
; CHAR
	db	0x74
; CHAR
	db	0x72
; CHAR
	db	0x69
; CHAR
	db	0xC3
; CHAR
	db	0xA2
; CHAR
	db	0x6E
; CHAR
	db	0x67
; CHAR
	db	0x75
; CHAR
	db	0x6C
; CHAR
	db	0x6F
; CHAR
	db	0x3A
; CHAR
	db	0x20
; CHAR
	db	0x00
; TEXT
segment	.text
; ADDR
	push	dword $_i21
; CALL
	call	$prints
; TRASH
	add	esp, 4
; PUSH
	push	eax
; TRASH
	add	esp, 4
; ADDR
	push	dword $a
; COPY
	push	dword [esp]
; CALL
	call	$readi
; PUSH
	push	eax
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
; RODATA
segment	.rodata
; ALIGN
align	4
; LABEL
$_i22:
; CHAR
	db	0x69
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
	db	0x61
; CHAR
	db	0x73
; CHAR
	db	0x20
; CHAR
	db	0x64
; CHAR
	db	0x69
; CHAR
	db	0x6D
; CHAR
	db	0x65
; CHAR
	db	0x6E
; CHAR
	db	0x73
; CHAR
	db	0xC3
; CHAR
	db	0xB5
; CHAR
	db	0x65
; CHAR
	db	0x73
; CHAR
	db	0x20
; CHAR
	db	0x64
; CHAR
	db	0x6F
; CHAR
	db	0x20
; CHAR
	db	0x73
; CHAR
	db	0x65
; CHAR
	db	0x67
; CHAR
	db	0x75
; CHAR
	db	0x6E
; CHAR
	db	0x64
; CHAR
	db	0x6F
; CHAR
	db	0x20
; CHAR
	db	0x6C
; CHAR
	db	0x61
; CHAR
	db	0x64
; CHAR
	db	0x6F
; CHAR
	db	0x20
; CHAR
	db	0x64
; CHAR
	db	0x6F
; CHAR
	db	0x20
; CHAR
	db	0x74
; CHAR
	db	0x72
; CHAR
	db	0x69
; CHAR
	db	0xC3
; CHAR
	db	0xA2
; CHAR
	db	0x6E
; CHAR
	db	0x67
; CHAR
	db	0x75
; CHAR
	db	0x6C
; CHAR
	db	0x6F
; CHAR
	db	0x3A
; CHAR
	db	0x20
; CHAR
	db	0x00
; TEXT
segment	.text
; ADDR
	push	dword $_i22
; CALL
	call	$prints
; TRASH
	add	esp, 8
; PUSH
	push	eax
; TRASH
	add	esp, 4
; ADDR
	push	dword $b
; COPY
	push	dword [esp]
; CALL
	call	$readi
; PUSH
	push	eax
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
; RODATA
segment	.rodata
; ALIGN
align	4
; LABEL
$_i23:
; CHAR
	db	0x69
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
	db	0x61
; CHAR
	db	0x73
; CHAR
	db	0x20
; CHAR
	db	0x64
; CHAR
	db	0x69
; CHAR
	db	0x6D
; CHAR
	db	0x65
; CHAR
	db	0x6E
; CHAR
	db	0x73
; CHAR
	db	0xC3
; CHAR
	db	0xB5
; CHAR
	db	0x65
; CHAR
	db	0x73
; CHAR
	db	0x20
; CHAR
	db	0x64
; CHAR
	db	0x6F
; CHAR
	db	0x20
; CHAR
	db	0x74
; CHAR
	db	0x65
; CHAR
	db	0x72
; CHAR
	db	0x63
; CHAR
	db	0x65
; CHAR
	db	0x69
; CHAR
	db	0x72
; CHAR
	db	0x6F
; CHAR
	db	0x20
; CHAR
	db	0x6C
; CHAR
	db	0x61
; CHAR
	db	0x64
; CHAR
	db	0x6F
; CHAR
	db	0x20
; CHAR
	db	0x64
; CHAR
	db	0x6F
; CHAR
	db	0x20
; CHAR
	db	0x74
; CHAR
	db	0x72
; CHAR
	db	0x69
; CHAR
	db	0xC3
; CHAR
	db	0xA2
; CHAR
	db	0x6E
; CHAR
	db	0x67
; CHAR
	db	0x75
; CHAR
	db	0x6C
; CHAR
	db	0x6F
; CHAR
	db	0x3A
; CHAR
	db	0x20
; CHAR
	db	0x00
; TEXT
segment	.text
; ADDR
	push	dword $_i23
; CALL
	call	$prints
; TRASH
	add	esp, 12
; PUSH
	push	eax
; TRASH
	add	esp, 4
; ADDR
	push	dword $c
; COPY
	push	dword [esp]
; CALL
	call	$readi
; PUSH
	push	eax
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
	push	dword $a
; LOAD
	pop	eax
	push	dword [eax]
; IMM
	push	dword 1
; JGE
	pop	eax
	pop	ecx
	cmp	ecx, eax
	jge	near $_i19
; RODATA
segment	.rodata
; ALIGN
align	4
; LABEL
$_i24:
; CHAR
	db	0x41
; CHAR
	db	0x73
; CHAR
	db	0x20
; CHAR
	db	0x64
; CHAR
	db	0x69
; CHAR
	db	0x6D
; CHAR
	db	0x65
; CHAR
	db	0x6E
; CHAR
	db	0x73
; CHAR
	db	0xC3
; CHAR
	db	0xB5
; CHAR
	db	0x65
; CHAR
	db	0x73
; CHAR
	db	0x20
; CHAR
	db	0x64
; CHAR
	db	0x6F
; CHAR
	db	0x73
; CHAR
	db	0x20
; CHAR
	db	0x6C
; CHAR
	db	0x61
; CHAR
	db	0x64
; CHAR
	db	0x6F
; CHAR
	db	0x73
; CHAR
	db	0x20
; CHAR
	db	0x64
; CHAR
	db	0x6F
; CHAR
	db	0x20
; CHAR
	db	0x74
; CHAR
	db	0x72
; CHAR
	db	0x69
; CHAR
	db	0xC3
; CHAR
	db	0xA2
; CHAR
	db	0x6E
; CHAR
	db	0x67
; CHAR
	db	0x75
; CHAR
	db	0x6C
; CHAR
	db	0x6F
; CHAR
	db	0x20
; CHAR
	db	0x64
; CHAR
	db	0x65
; CHAR
	db	0x76
; CHAR
	db	0x65
; CHAR
	db	0x6D
; CHAR
	db	0x20
; CHAR
	db	0x73
; CHAR
	db	0x65
; CHAR
	db	0x72
; CHAR
	db	0x20
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
	db	0x61
; CHAR
	db	0x73
; CHAR
	db	0x0A
; CHAR
	db	0x00
; TEXT
segment	.text
; ADDR
	push	dword $_i24
; CALL
	call	$prints
; TRASH
	add	esp, 16
; PUSH
	push	eax
; TRASH
	add	esp, 4
; JMP
	jmp	dword $_i20
; LABEL
$_i19:
; ADDR
	push	dword $b
; LOAD
	pop	eax
	push	dword [eax]
; IMM
	push	dword 1
; JGE
	pop	eax
	pop	ecx
	cmp	ecx, eax
	jge	near $_i17
; RODATA
segment	.rodata
; ALIGN
align	4
; LABEL
$_i25:
; CHAR
	db	0x41
; CHAR
	db	0x73
; CHAR
	db	0x20
; CHAR
	db	0x64
; CHAR
	db	0x69
; CHAR
	db	0x6D
; CHAR
	db	0x65
; CHAR
	db	0x6E
; CHAR
	db	0x73
; CHAR
	db	0xC3
; CHAR
	db	0xB5
; CHAR
	db	0x65
; CHAR
	db	0x73
; CHAR
	db	0x20
; CHAR
	db	0x64
; CHAR
	db	0x6F
; CHAR
	db	0x73
; CHAR
	db	0x20
; CHAR
	db	0x6C
; CHAR
	db	0x61
; CHAR
	db	0x64
; CHAR
	db	0x6F
; CHAR
	db	0x73
; CHAR
	db	0x20
; CHAR
	db	0x64
; CHAR
	db	0x6F
; CHAR
	db	0x20
; CHAR
	db	0x74
; CHAR
	db	0x72
; CHAR
	db	0x69
; CHAR
	db	0xC3
; CHAR
	db	0xA2
; CHAR
	db	0x6E
; CHAR
	db	0x67
; CHAR
	db	0x75
; CHAR
	db	0x6C
; CHAR
	db	0x6F
; CHAR
	db	0x20
; CHAR
	db	0x64
; CHAR
	db	0x65
; CHAR
	db	0x76
; CHAR
	db	0x65
; CHAR
	db	0x6D
; CHAR
	db	0x20
; CHAR
	db	0x73
; CHAR
	db	0x65
; CHAR
	db	0x72
; CHAR
	db	0x20
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
	db	0x61
; CHAR
	db	0x73
; CHAR
	db	0x0A
; CHAR
	db	0x00
; TEXT
segment	.text
; ADDR
	push	dword $_i25
; CALL
	call	$prints
; TRASH
	add	esp, 20
; PUSH
	push	eax
; TRASH
	add	esp, 4
; JMP
	jmp	dword $_i18
; LABEL
$_i17:
; ADDR
	push	dword $c
; LOAD
	pop	eax
	push	dword [eax]
; IMM
	push	dword 1
; JGE
	pop	eax
	pop	ecx
	cmp	ecx, eax
	jge	near $_i15
; RODATA
segment	.rodata
; ALIGN
align	4
; LABEL
$_i26:
; CHAR
	db	0x41
; CHAR
	db	0x73
; CHAR
	db	0x20
; CHAR
	db	0x64
; CHAR
	db	0x69
; CHAR
	db	0x6D
; CHAR
	db	0x65
; CHAR
	db	0x6E
; CHAR
	db	0x73
; CHAR
	db	0xC3
; CHAR
	db	0xB5
; CHAR
	db	0x65
; CHAR
	db	0x73
; CHAR
	db	0x20
; CHAR
	db	0x64
; CHAR
	db	0x6F
; CHAR
	db	0x73
; CHAR
	db	0x20
; CHAR
	db	0x6C
; CHAR
	db	0x61
; CHAR
	db	0x64
; CHAR
	db	0x6F
; CHAR
	db	0x73
; CHAR
	db	0x20
; CHAR
	db	0x64
; CHAR
	db	0x6F
; CHAR
	db	0x20
; CHAR
	db	0x74
; CHAR
	db	0x72
; CHAR
	db	0x69
; CHAR
	db	0xC3
; CHAR
	db	0xA2
; CHAR
	db	0x6E
; CHAR
	db	0x67
; CHAR
	db	0x75
; CHAR
	db	0x6C
; CHAR
	db	0x6F
; CHAR
	db	0x20
; CHAR
	db	0x64
; CHAR
	db	0x65
; CHAR
	db	0x76
; CHAR
	db	0x65
; CHAR
	db	0x6D
; CHAR
	db	0x20
; CHAR
	db	0x73
; CHAR
	db	0x65
; CHAR
	db	0x72
; CHAR
	db	0x20
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
	db	0x61
; CHAR
	db	0x73
; CHAR
	db	0x0A
; CHAR
	db	0x00
; TEXT
segment	.text
; ADDR
	push	dword $_i26
; CALL
	call	$prints
; TRASH
	add	esp, 24
; PUSH
	push	eax
; TRASH
	add	esp, 4
; JMP
	jmp	dword $_i16
; LABEL
$_i15:
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
; ADD
	pop	eax
	add	dword [esp], eax
; ADDR
	push	dword $c
; LOAD
	pop	eax
	push	dword [eax]
; JGT
	pop	eax
	pop	ecx
	cmp	ecx, eax
	jg	near $_i13
; RODATA
segment	.rodata
; ALIGN
align	4
; LABEL
$_i27:
; CHAR
	db	0x4E
; CHAR
	db	0xC3
; CHAR
	db	0xA3
; CHAR
	db	0x6F
; CHAR
	db	0x20
; CHAR
	db	0xC3
; CHAR
	db	0xA9
; CHAR
	db	0x20
; CHAR
	db	0x75
; CHAR
	db	0x6D
; CHAR
	db	0x20
; CHAR
	db	0x74
; CHAR
	db	0x72
; CHAR
	db	0x69
; CHAR
	db	0xC3
; CHAR
	db	0xA2
; CHAR
	db	0x6E
; CHAR
	db	0x67
; CHAR
	db	0x75
; CHAR
	db	0x6C
; CHAR
	db	0x6F
; CHAR
	db	0x0A
; CHAR
	db	0x00
; TEXT
segment	.text
; ADDR
	push	dword $_i27
; CALL
	call	$prints
; TRASH
	add	esp, 28
; PUSH
	push	eax
; TRASH
	add	esp, 4
; JMP
	jmp	dword $_i14
; LABEL
$_i13:
; ADDR
	push	dword $a
; LOAD
	pop	eax
	push	dword [eax]
; ADDR
	push	dword $c
; LOAD
	pop	eax
	push	dword [eax]
; ADD
	pop	eax
	add	dword [esp], eax
; ADDR
	push	dword $b
; LOAD
	pop	eax
	push	dword [eax]
; JGT
	pop	eax
	pop	ecx
	cmp	ecx, eax
	jg	near $_i11
; RODATA
segment	.rodata
; ALIGN
align	4
; LABEL
$_i28:
; CHAR
	db	0x4E
; CHAR
	db	0xC3
; CHAR
	db	0xA3
; CHAR
	db	0x6F
; CHAR
	db	0x20
; CHAR
	db	0xC3
; CHAR
	db	0xA9
; CHAR
	db	0x20
; CHAR
	db	0x75
; CHAR
	db	0x6D
; CHAR
	db	0x20
; CHAR
	db	0x74
; CHAR
	db	0x72
; CHAR
	db	0x69
; CHAR
	db	0xC3
; CHAR
	db	0xA2
; CHAR
	db	0x6E
; CHAR
	db	0x67
; CHAR
	db	0x75
; CHAR
	db	0x6C
; CHAR
	db	0x6F
; CHAR
	db	0x0A
; CHAR
	db	0x00
; TEXT
segment	.text
; ADDR
	push	dword $_i28
; CALL
	call	$prints
; TRASH
	add	esp, 32
; PUSH
	push	eax
; TRASH
	add	esp, 4
; JMP
	jmp	dword $_i12
; LABEL
$_i11:
; ADDR
	push	dword $c
; LOAD
	pop	eax
	push	dword [eax]
; ADDR
	push	dword $b
; LOAD
	pop	eax
	push	dword [eax]
; ADD
	pop	eax
	add	dword [esp], eax
; ADDR
	push	dword $a
; LOAD
	pop	eax
	push	dword [eax]
; JGT
	pop	eax
	pop	ecx
	cmp	ecx, eax
	jg	near $_i9
; RODATA
segment	.rodata
; ALIGN
align	4
; LABEL
$_i29:
; CHAR
	db	0x4E
; CHAR
	db	0xC3
; CHAR
	db	0xA3
; CHAR
	db	0x6F
; CHAR
	db	0x20
; CHAR
	db	0xC3
; CHAR
	db	0xA9
; CHAR
	db	0x20
; CHAR
	db	0x75
; CHAR
	db	0x6D
; CHAR
	db	0x20
; CHAR
	db	0x74
; CHAR
	db	0x72
; CHAR
	db	0x69
; CHAR
	db	0xC3
; CHAR
	db	0xA2
; CHAR
	db	0x6E
; CHAR
	db	0x67
; CHAR
	db	0x75
; CHAR
	db	0x6C
; CHAR
	db	0x6F
; CHAR
	db	0x0A
; CHAR
	db	0x00
; TEXT
segment	.text
; ADDR
	push	dword $_i29
; CALL
	call	$prints
; TRASH
	add	esp, 36
; PUSH
	push	eax
; TRASH
	add	esp, 4
; JMP
	jmp	dword $_i10
; LABEL
$_i9:
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
; JNE
	pop	eax
	pop	ecx
	cmp	ecx, eax
	jne	near $_i7
; ADDR
	push	dword $b
; LOAD
	pop	eax
	push	dword [eax]
; ADDR
	push	dword $c
; LOAD
	pop	eax
	push	dword [eax]
; JNE
	pop	eax
	pop	ecx
	cmp	ecx, eax
	jne	near $_i1
; RODATA
segment	.rodata
; ALIGN
align	4
; LABEL
$_i30:
; CHAR
	db	0x74
; CHAR
	db	0x72
; CHAR
	db	0x69
; CHAR
	db	0xC3
; CHAR
	db	0xA2
; CHAR
	db	0x6E
; CHAR
	db	0x67
; CHAR
	db	0x75
; CHAR
	db	0x6C
; CHAR
	db	0x6F
; CHAR
	db	0x20
; CHAR
	db	0x65
; CHAR
	db	0x71
; CHAR
	db	0x75
; CHAR
	db	0x69
; CHAR
	db	0x6C
; CHAR
	db	0xC3
; CHAR
	db	0xA1
; CHAR
	db	0x65
; CHAR
	db	0x72
; CHAR
	db	0x6F
; CHAR
	db	0x0A
; CHAR
	db	0x00
; TEXT
segment	.text
; ADDR
	push	dword $_i30
; CALL
	call	$prints
; TRASH
	add	esp, 40
; PUSH
	push	eax
; TRASH
	add	esp, 4
; JMP
	jmp	dword $_i2
; LABEL
$_i1:
; RODATA
segment	.rodata
; ALIGN
align	4
; LABEL
$_i31:
; CHAR
	db	0x74
; CHAR
	db	0x72
; CHAR
	db	0x69
; CHAR
	db	0xC3
; CHAR
	db	0xA2
; CHAR
	db	0x6E
; CHAR
	db	0x67
; CHAR
	db	0x75
; CHAR
	db	0x6C
; CHAR
	db	0x6F
; CHAR
	db	0x20
; CHAR
	db	0x69
; CHAR
	db	0x73
; CHAR
	db	0xC3
; CHAR
	db	0xB3
; CHAR
	db	0x63
; CHAR
	db	0x65
; CHAR
	db	0x6C
; CHAR
	db	0x65
; CHAR
	db	0x73
; CHAR
	db	0x0A
; CHAR
	db	0x00
; TEXT
segment	.text
; ADDR
	push	dword $_i31
; CALL
	call	$prints
; TRASH
	add	esp, 44
; PUSH
	push	eax
; TRASH
	add	esp, 4
; LABEL
$_i2:
; JMP
	jmp	dword $_i8
; LABEL
$_i7:
; ADDR
	push	dword $b
; LOAD
	pop	eax
	push	dword [eax]
; ADDR
	push	dword $c
; LOAD
	pop	eax
	push	dword [eax]
; JNE
	pop	eax
	pop	ecx
	cmp	ecx, eax
	jne	near $_i5
; RODATA
segment	.rodata
; ALIGN
align	4
; LABEL
$_i32:
; CHAR
	db	0x74
; CHAR
	db	0x72
; CHAR
	db	0x69
; CHAR
	db	0xC3
; CHAR
	db	0xA2
; CHAR
	db	0x6E
; CHAR
	db	0x67
; CHAR
	db	0x75
; CHAR
	db	0x6C
; CHAR
	db	0x6F
; CHAR
	db	0x20
; CHAR
	db	0x69
; CHAR
	db	0x73
; CHAR
	db	0xC3
; CHAR
	db	0xB3
; CHAR
	db	0x63
; CHAR
	db	0x65
; CHAR
	db	0x6C
; CHAR
	db	0x65
; CHAR
	db	0x73
; CHAR
	db	0x0A
; CHAR
	db	0x00
; TEXT
segment	.text
; ADDR
	push	dword $_i32
; CALL
	call	$prints
; TRASH
	add	esp, 48
; PUSH
	push	eax
; TRASH
	add	esp, 4
; JMP
	jmp	dword $_i6
; LABEL
$_i5:
; ADDR
	push	dword $a
; LOAD
	pop	eax
	push	dword [eax]
; ADDR
	push	dword $c
; LOAD
	pop	eax
	push	dword [eax]
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
$_i33:
; CHAR
	db	0x74
; CHAR
	db	0x72
; CHAR
	db	0x69
; CHAR
	db	0xC3
; CHAR
	db	0xA2
; CHAR
	db	0x6E
; CHAR
	db	0x67
; CHAR
	db	0x75
; CHAR
	db	0x6C
; CHAR
	db	0x6F
; CHAR
	db	0x20
; CHAR
	db	0x69
; CHAR
	db	0x73
; CHAR
	db	0xC3
; CHAR
	db	0xB3
; CHAR
	db	0x63
; CHAR
	db	0x65
; CHAR
	db	0x6C
; CHAR
	db	0x65
; CHAR
	db	0x73
; CHAR
	db	0x0A
; CHAR
	db	0x00
; TEXT
segment	.text
; ADDR
	push	dword $_i33
; CALL
	call	$prints
; TRASH
	add	esp, 52
; PUSH
	push	eax
; TRASH
	add	esp, 4
; JMP
	jmp	dword $_i4
; LABEL
$_i3:
; RODATA
segment	.rodata
; ALIGN
align	4
; LABEL
$_i34:
; CHAR
	db	0x74
; CHAR
	db	0x72
; CHAR
	db	0x69
; CHAR
	db	0xC3
; CHAR
	db	0xA2
; CHAR
	db	0x6E
; CHAR
	db	0x67
; CHAR
	db	0x75
; CHAR
	db	0x6C
; CHAR
	db	0x6F
; CHAR
	db	0x20
; CHAR
	db	0x65
; CHAR
	db	0x73
; CHAR
	db	0x63
; CHAR
	db	0x61
; CHAR
	db	0x6C
; CHAR
	db	0x65
; CHAR
	db	0x6E
; CHAR
	db	0x6F
; CHAR
	db	0x0A
; CHAR
	db	0x00
; TEXT
segment	.text
; ADDR
	push	dword $_i34
; CALL
	call	$prints
; TRASH
	add	esp, 56
; PUSH
	push	eax
; TRASH
	add	esp, 4
; LABEL
$_i4:
; LABEL
$_i6:
; LABEL
$_i8:
; LABEL
$_i10:
; LABEL
$_i12:
; LABEL
$_i14:
; LABEL
$_i16:
; LABEL
$_i18:
; LABEL
$_i20:
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
