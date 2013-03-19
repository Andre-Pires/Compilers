section .bss
	$buf2	resb	2

section .text
	global _prints, _readb, _exit, _start
	extern _env, _strlen, _main

_prints:
	push	qword [rsp+8]		; pushd 'prints' first argument
	call	_strlen
	mov	rdx, rax	; strlen
	pop	rsi		; string
	mov	edi, 1		; stdout
	mov	eax, 1		; SYS_write
	syscall
	ret

_readb:
	push	rdi
	push	rsi
	push	rdx
	mov	edx, 1			; bytes
	mov	rsi, $buf2		; buffer
	mov	edi, 0			; stdin
	mov	eax, 0			; SYS_read
	syscall
	cmp	rax, 1
	jne	.Lret
	xor	rax, rax
	mov	al, [$buf2]
.Lret:	pop	rdx
	pop	rsi
	pop	rdi
	ret

_start:	
	mov	[$_env], rsp
	mov	rax, [rsp]	; argc
	lea	rbx, [rsp+8]	; argv
	lea	rdx, [rbx+rax*8]; &(argv[argc])
	add	rdx, 8		; envp
	push	qword 0
	mov	rbp, rsp	; init frame pointer
	push	qword rdx
	push	qword rbx
	push	qword rax
	call	_main
	push	rax
	call	_exit

_exit:	mov	rbx, [rsp+8]
.L0:	mov	eax, 60
	syscall
	jmp	.L0
