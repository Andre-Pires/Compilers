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
; JGE
	pop	eax
	pop	ecx
	cmp	ecx, eax
	jge	near $_i19
; CALL
	call	$prints
; TRASH
	add	esp, 0
; JMP
	jmp	dword $_i20
; LABEL
$_i19:
; ADDRV
	push	dword [$b]
; IMM
	push	dword 1
; JGE
	pop	eax
	pop	ecx
	cmp	ecx, eax
	jge	near $_i17
; CALL
	call	$prints
; TRASH
	add	esp, 0
; JMP
	jmp	dword $_i18
; LABEL
$_i17:
; ADDRV
	push	dword [$c]
; IMM
	push	dword 1
; JGE
	pop	eax
	pop	ecx
	cmp	ecx, eax
	jge	near $_i15
; CALL
	call	$prints
; TRASH
	add	esp, 0
; JMP
	jmp	dword $_i16
; LABEL
$_i15:
; ADDRV
	push	dword [$a]
; ADDRV
	push	dword [$b]
; ADD
	pop	eax
	add	dword [esp], eax
; ADDRV
	push	dword [$c]
; JGT
	pop	eax
	pop	ecx
	cmp	ecx, eax
	jg	near $_i13
; CALL
	call	$prints
; TRASH
	add	esp, 0
; JMP
	jmp	dword $_i14
; LABEL
$_i13:
; ADDRV
	push	dword [$a]
; ADDRV
	push	dword [$c]
; ADD
	pop	eax
	add	dword [esp], eax
; ADDRV
	push	dword [$b]
; JGT
	pop	eax
	pop	ecx
	cmp	ecx, eax
	jg	near $_i11
; CALL
	call	$prints
; TRASH
	add	esp, 0
; JMP
	jmp	dword $_i12
; LABEL
$_i11:
; ADDRV
	push	dword [$c]
; ADDRV
	push	dword [$b]
; ADD
	pop	eax
	add	dword [esp], eax
; ADDRV
	push	dword [$a]
; JGT
	pop	eax
	pop	ecx
	cmp	ecx, eax
	jg	near $_i9
; CALL
	call	$prints
; TRASH
	add	esp, 0
; JMP
	jmp	dword $_i10
; LABEL
$_i9:
; ADDRV
	push	dword [$a]
; ADDRV
	push	dword [$b]
; JNE
	pop	eax
	pop	ecx
	cmp	ecx, eax
	jne	near $_i7
; ADDRV
	push	dword [$b]
; ADDRV
	push	dword [$c]
; JNE
	pop	eax
	pop	ecx
	cmp	ecx, eax
	jne	near $_i1
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
; JMP
	jmp	dword $_i8
; LABEL
$_i7:
; ADDRV
	push	dword [$b]
; ADDRV
	push	dword [$c]
; JNE
	pop	eax
	pop	ecx
	cmp	ecx, eax
	jne	near $_i5
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
	push	dword [$c]
; JNE
	pop	eax
	pop	ecx
	cmp	ecx, eax
	jne	near $_i3
; CALL
	call	$prints
; TRASH
	add	esp, 0
; JMP
	jmp	dword $_i4
; LABEL
$_i3:
; CALL
	call	$prints
; TRASH
	add	esp, 0
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
