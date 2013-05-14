; EXTRN
extern	$prints
; EXTRN
extern	$printi
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
	sub	esp, 8
; LEAVE
	leave
; RET
	ret
