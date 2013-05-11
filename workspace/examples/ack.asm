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
; LEAVE
	leave
; RET
	ret
