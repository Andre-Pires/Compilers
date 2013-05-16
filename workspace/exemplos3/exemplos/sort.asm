; EXTRN
extern	$bubble
; EXTRN
extern	$strcmp
; EXTRN
extern	$strdup
; EXTRN
extern	$readln
; EXTRN
extern	$new
; EXTRN
extern	$free
; EXTRN
extern	$prints
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
	sub	esp, 40
; LEAVE
	leave
; RET
	ret
