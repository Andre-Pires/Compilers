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
	sub	esp, 0
; CALL
	call	$prints
; TRASH
	add	esp, 0
; ADDRV
	push	dword [$a]
; CALL
	call	$readi
; TRASH
	add	esp, 0
; COPY
	push	dword [esp]
; ADDR
	push	dword $a
; STORE
	pop	ecx
	pop	eax
	mov	[ecx], eax
; CALL
	call	$prints
; TRASH
	add	esp, 0
; ADDRV
	push	dword [$b]
; CALL
	call	$readi
; TRASH
	add	esp, 0
; COPY
	push	dword [esp]
; ADDR
	push	dword $b
; STORE
	pop	ecx
	pop	eax
	mov	[ecx], eax
; CALL
	call	$prints
; TRASH
	add	esp, 0
; ADDRV
	push	dword [$c]
; CALL
	call	$readi
; TRASH
	add	esp, 0
; COPY
	push	dword [esp]
; ADDR
	push	dword $c
; STORE
	pop	ecx
	pop	eax
	mov	[ecx], eax
; ADDRV
	push	dword [$a]
; IMM
	push	dword 1
; LT
	pop	eax
	xor	ecx, ecx
	cmp	[esp], eax
	setl	cl
	mov	[esp], ecx
; ADDRV
	push	dword [$b]
; IMM
	push	dword 1
; LT
	pop	eax
	xor	ecx, ecx
	cmp	[esp], eax
	setl	cl
	mov	[esp], ecx
; OR
	pop	eax
	or	dword [esp], eax
; ADDRV
	push	dword [$c]
; IMM
	push	dword 1
; LT
	pop	eax
	xor	ecx, ecx
	cmp	[esp], eax
	setl	cl
	mov	[esp], ecx
; OR
	pop	eax
	or	dword [esp], eax
; JZ
	pop	eax
	cmp	eax, byte 0
	je	near $_i7
; CALL
	call	$prints
; TRASH
	add	esp, 0
; JMP
	jmp	dword $_i8
; LABEL
$_i7:
; ADDRV
	push	dword [$a]
; ADDRV
	push	dword [$b]
; ADD
	pop	eax
	add	dword [esp], eax
; ADDRV
	push	dword [$c]
; LE
	pop	eax
	xor	ecx, ecx
	cmp	[esp], eax
	setle	cl
	mov	[esp], ecx
; ADDRV
	push	dword [$a]
; ADDRV
	push	dword [$c]
; ADD
	pop	eax
	add	dword [esp], eax
; ADDRV
	push	dword [$b]
; LE
	pop	eax
	xor	ecx, ecx
	cmp	[esp], eax
	setle	cl
	mov	[esp], ecx
; OR
	pop	eax
	or	dword [esp], eax
; ADDRV
	push	dword [$c]
; ADDRV
	push	dword [$b]
; ADD
	pop	eax
	add	dword [esp], eax
; ADDRV
	push	dword [$a]
; LE
	pop	eax
	xor	ecx, ecx
	cmp	[esp], eax
	setle	cl
	mov	[esp], ecx
; OR
	pop	eax
	or	dword [esp], eax
; JZ
	pop	eax
	cmp	eax, byte 0
	je	near $_i5
; CALL
	call	$prints
; TRASH
	add	esp, 0
; JMP
	jmp	dword $_i6
; LABEL
$_i5:
; ADDRV
	push	dword [$a]
; ADDRV
	push	dword [$b]
; EQ
	pop	eax
	xor	ecx, ecx
	cmp	[esp], eax
	sete	cl
	mov	[esp], ecx
; ADDRV
	push	dword [$b]
; ADDRV
	push	dword [$c]
; EQ
	pop	eax
	xor	ecx, ecx
	cmp	[esp], eax
	sete	cl
	mov	[esp], ecx
; AND
	pop	eax
	and	dword [esp], eax
; JZ
	pop	eax
	cmp	eax, byte 0
	je	near $_i3
; CALL
	call	$prints
; TRASH
	add	esp, 0
; JMP
	jmp	dword $_i4
; LABEL
$_i3:
; ADDRV
	push	dword [$b]
; ADDRV
	push	dword [$c]
; EQ
	pop	eax
	xor	ecx, ecx
	cmp	[esp], eax
	sete	cl
	mov	[esp], ecx
; ADDRV
	push	dword [$a]
; ADDRV
	push	dword [$c]
; EQ
	pop	eax
	xor	ecx, ecx
	cmp	[esp], eax
	sete	cl
	mov	[esp], ecx
; OR
	pop	eax
	or	dword [esp], eax
; JZ
	pop	eax
	cmp	eax, byte 0
	je	near $_i1
; CALL
	call	$prints
; TRASH
	add	esp, 0
; JMP
	jmp	dword $_i2
; LABEL
$_i1:
; CALL
	call	$prints
; TRASH
	add	esp, 0
; LABEL
$_i2:
; LABEL
$_i4:
; LABEL
$_i6:
; LABEL
$_i8:
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
