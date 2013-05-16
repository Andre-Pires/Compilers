; EXTRN
extern	$printi
; EXTRN
extern	$println
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
; LOCAL
	lea	eax, [ebp+12]
	push	eax
; LOAD
	pop	eax
	push	dword [eax]
; CALL
	call	$fptr
; TRASH
	add	esp, 4
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
; LOCAL
	lea	eax, [ebp+-4]
	push	eax
; LOAD
	pop	eax
	push	dword [eax]
; COPY
	push	dword [esp]
; ADDR
	push	dword $fptr
; STORE
	pop	ecx
	pop	eax
	mov	[ecx], eax
; TRASH
	add	esp, 4
; LOCAL
	lea	eax, [ebp+12]
	push	eax
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
; LOCAL
	lea	eax, [ebp+12]
	push	eax
; LOAD
	pop	eax
	push	dword [eax]
; IMM
	push	dword 1
; SUB
	pop	eax
	sub	dword [esp], eax
; LOCAL
	lea	eax, [ebp+16]
	push	eax
; LOAD
	pop	eax
	push	dword [eax]
; LOCAL
	lea	eax, [ebp+20]
	push	eax
; LOAD
	pop	eax
	push	dword [eax]
; CALL
	call	$fptr
; TRASH
	add	esp, 12
; PUSH
	push	eax
; TRASH
	add	esp, 4
; LABEL
$_i1:
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
