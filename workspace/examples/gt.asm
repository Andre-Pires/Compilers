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
	sub	esp, 0
; CALL
	call	$prints
; TRASH
	add	esp, 0
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
; ADDRV
	push	dword [$a]
; ADDRV
	push	dword [$b]
; GT
	pop	eax
	xor	ecx, ecx
	cmp	[esp], eax
	setg	cl
	mov	[esp], ecx
; CALL
	call	$printi
; TRASH
	add	esp, 0
; CALL
	call	$println
; TRASH
	add	esp, 0
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
