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
	push	dword [$argc]
; CALL
	call	$printi
; TRASH
	add	esp, 0
; CALL
	call	$println
; TRASH
	add	esp, 0
; ADDRV
	push	dword [$argc]
; IMM
	push	dword 1
; JLE
	pop	eax
	pop	ecx
	cmp	ecx, eax
	jle	near $_i1
; CALL
	call	$prints
; TRASH
	add	esp, 0
; ADDRV
	push	dword [$argv]
; CALL
	call	$prints
; TRASH
	add	esp, 0
; CALL
	call	$println
; TRASH
	add	esp, 0
; LABEL
$_i1:
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
