; TEXT
segment	.text
; ALIGN
align	4
; GLOBL
global	$bubble:function
; LABEL
$bubble:
; ENTER
	push	ebp
	mov	ebp, esp
	sub	esp, 12
; LEAVE
	leave
; RET
	ret
