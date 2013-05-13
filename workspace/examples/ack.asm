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
; TEXT
segment	.text
; ALIGN
align	4
; GLOBL
global	$atoi:function
; LABEL
$atoi:
; ENTER
	push	ebp
	mov	ebp, esp
	sub	esp, 0
; LEAVE
	leave
; RET
	ret
; DATA
segment	.data
; ALIGN
align	4
; LABEL
$cnt:
; INTEGER
	dd	1
; TEXT
segment	.text
; TEXT
segment	.text
; ALIGN
align	4
; GLOBL
global	$ackermann:function
; LABEL
$ackermann:
; ENTER
	push	ebp
	mov	ebp, esp
	sub	esp, 0
; ADDRV
	push	dword [$cnt]
; ADDRV
	push	dword [$cnt]
; IMM
	push	dword 1
; ADD
	pop	eax
	add	dword [esp], eax
; COPY
	push	dword [esp]
; ADDR
	push	dword $cnt
; STORE
	pop	ecx
	pop	eax
	mov	[ecx], eax
; ADDRV
	push	dword [$m]
; IMM
	push	dword 0
; JNE
	pop	eax
	pop	ecx
	cmp	ecx, eax
	jne	near $_i3
; ADDRV
	push	dword [$ackermann]
; ADDRV
	push	dword [$n]
; IMM
	push	dword 1
; ADD
	pop	eax
	add	dword [esp], eax
; COPY
	push	dword [esp]
; ADDR
	push	dword $ackermann
; STORE
	pop	ecx
	pop	eax
	mov	[ecx], eax
; JMP
	jmp	dword $_i4
; LABEL
$_i3:
; ADDRV
	push	dword [$n]
; IMM
	push	dword 0
; JNE
	pop	eax
	pop	ecx
	cmp	ecx, eax
	jne	near $_i1
; ADDRV
	push	dword [$ackermann]
; ADDRV
	push	dword [$m]
; IMM
	push	dword 1
; SUB
	pop	eax
	sub	dword [esp], eax
; IMM
	push	dword 1
; CALL
	call	$ackermann
; TRASH
	add	esp, 0
; COPY
	push	dword [esp]
; ADDR
	push	dword $ackermann
; STORE
	pop	ecx
	pop	eax
	mov	[ecx], eax
; JMP
	jmp	dword $_i2
; LABEL
$_i1:
; ADDRV
	push	dword [$ackermann]
; ADDRV
	push	dword [$m]
; IMM
	push	dword 1
; SUB
	pop	eax
	sub	dword [esp], eax
; ADDRV
	push	dword [$m]
; ADDRV
	push	dword [$n]
; IMM
	push	dword 1
; SUB
	pop	eax
	sub	dword [esp], eax
; CALL
	call	$ackermann
; TRASH
	add	esp, 0
; CALL
	call	$ackermann
; TRASH
	add	esp, 0
; COPY
	push	dword [esp]
; ADDR
	push	dword $ackermann
; STORE
	pop	ecx
	pop	eax
	mov	[ecx], eax
; LABEL
$_i2:
; LABEL
$_i4:
; LEAVE
	leave
; RET
	ret
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
	push	dword [$argc]
; IMM
	push	dword 2
; JLE
	pop	eax
	pop	ecx
	cmp	ecx, eax
	jle	near $_i5
; ADDRV
	push	dword [$argv]
; CALL
	call	$atoi
; TRASH
	add	esp, 0
; ADDRV
	push	dword [$argv]
; CALL
	call	$atoi
; TRASH
	add	esp, 0
; CALL
	call	$ackermann
; TRASH
	add	esp, 0
; CALL
	call	$printi
; TRASH
	add	esp, 0
; CALL
	call	$prints
; TRASH
	add	esp, 0
; ADDRV
	push	dword [$cnt]
; CALL
	call	$printi
; TRASH
	add	esp, 0
; CALL
	call	$println
; TRASH
	add	esp, 0
; LABEL
$_i5:
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
