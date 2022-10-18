section .data
message: db  'hello, world!', 10, 0

section .text
global _start

exit:
    mov  rax, 60
    xor  rdi, rdi
    syscall

string_length:
  mov rax, 0
    .loop:
      xor rax, rax
    .count:
      cmp byte [rdi+rax], 0
      je .end
      inc rax
      jmp .count
    .end:
      ret

print_string:
    call string_length
    mov  rdx, rax
    mov  rsi, rdi
    mov  rax, 1
    mov  rdi, 1
    syscall
    ret

_start:
    mov  rdi, message
    call print_string
    call exit
