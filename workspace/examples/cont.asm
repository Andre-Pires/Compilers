; EXTRN
extern	$printi
; EXTRN
extern	$println
; EXTRN
extern	$readi
; BSS
segment	.bss
; ALIGN
align	4
; LABEL
$m:
; BYTE
	resb	4
; TEXT
segment	.text
; BSS
segment	.bss
; ALIGN
align	4
; LABEL
$x:
; BYTE
	resb	4
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
