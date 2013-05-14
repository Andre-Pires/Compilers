; EXTRN
extern	$prints
; EXTRN
extern	$printd
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
	sub	esp, 20
; LEAVE
	leave
; RET
	ret
