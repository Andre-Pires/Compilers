; EXTRN
extern	$prints
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
	sub	esp, 8
; LEAVE
	leave
; RET
	ret
