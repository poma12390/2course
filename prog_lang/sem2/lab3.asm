section .data
newline_char: db 10
message: db '123456789abcdef'
section .text
global _start
read_uint:
	.A:
	   xor r8, r8
	   mov r8b, byte[rdi]
	   cmp r8, '1'
	   jl .end
	   cmp r8, '9'
	   jg .end
	   inc rdx
	   add r8, rax
	   jmp .B
 	.B
	   xor r8, r8
	   mov r8b, byte[rdi]
	   cmp r8, '1'
	   jl .end
	   cmp r8, '9'
	   jg .end
	   inc rdx
	   jmp .B
	   
	.end
	   ret

_start: 
	xor rdx, rdx
	xor rax, rax
	mov rdi, message
	call read_uint
