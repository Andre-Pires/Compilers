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
; DATA
segment	.data
; ALIGN
align	4
; LABEL
$x:
; STR
	db	'x', 0
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
; LEAVE
	leave
; RET
	ret
