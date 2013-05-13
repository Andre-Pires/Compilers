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
$x:
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
; ADDRV
	push	dword [$x]
; CALL
	call	$readi
; TRASH
	add	esp, 0
; COPY
	push	dword [esp]
; ADDR
	push	dword $x
; STORE
	pop	ecx
	pop	eax
	mov	[ecx], eax
; ADDRV
	push	dword [$x]
; IMM
	push	dword 0
; JLE
	pop	eax
	pop	ecx
	cmp	ecx, eax
	jle	near $_i1
; CALL
	call	$prints
; TRASH
	add	esp, 0
; LABEL
$_i1:
; ADDRV
	push	dword [$x]
; IMM
	push	dword 0
; JGE
	pop	eax
	pop	ecx
	cmp	ecx, eax
	jge	near $_i2
; CALL
	call	$prints
; TRASH
	add	esp, 0
; LABEL
$_i2:
; ADDRV
	push	dword [$x]
; IMM
	push	dword 0
; JNE
	pop	eax
	pop	ecx
	cmp	ecx, eax
	jne	near $_i3
; CALL
	call	$prints
; TRASH
	add	esp, 0
; LABEL
$_i3:
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
