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
global	$entry:function
; LABEL
$entry:
; ENTER
	push	ebp
	mov	ebp, esp
	sub	esp, 0
; CALL
	call	$prints
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
