section .text
%define EXIT_CODE 60
%define WRITE_CODE 1

 
; Принимает код возврата и завершает текущий процесс
exit:
    mov  rax, 60 ;code 60 =exit
    xor  rdi, rdi
    syscall

; Принимает указатель на нуль-терминированную строку, возвращает её длину
string_length:
    xor rax, rax
  .loop:
    cmp byte[rdi+rax], 0
    je .end
    inc rax
    jmp .loop
  .end:
    ret

; Принимает указатель на нуль-терминированную строку, выводит её в stdout
print_string:
    xor rax, rax
    call string_length
    

    mov  rsi, rdi
    mov  rdi, 1
    mov  rdx, rax
    mov  rax, WRITE_CODE; code 1 = write
    syscall
    ret

; Принимает код символа и выводит его в stdout
print_char:
    xor rax, rax
    push rdi        ;   rdi -> stack, so rsp addressing to memory, that contains char_code
    mov rsi, rsp    ; rsp -> rsi, so rdi addressing to memory, that contains char_code

    mov rdx, 1  ; 1 -> rdx (char = 1 byte)
    mov rax, WRITE_CODE  ; code 1 for write
    mov rdi, 1  ; 1 -> rdi, descriptor (stdout)
    syscall
    pop rdi         ; pop increase rsp, but not clear the char_code
    ret

; Переводит строку (выводит символ с кодом 0xA)
print_newline:
    mov rdi, 0xa      ; move the new line character to rax
    call print_char
    ret

; Выводит беззнаковое 8-байтовое число в десятичном формате 
; Совет: выделите место в стеке и храните там результаты деления
; Не забудьте перевести цифры в их ASCII коды.
print_uint:
    xor rax, rax    
    mov rax, rdi; rax - number
    xor rcx, rcx
    dec rsp; sdvig sp
    mov r8, 10; r8 = 10 CONST
    .calc_loop:
    xor rdx, rdx
    div r8; rax = rax / r8; rdx = rdx % r8
    add rdx, '0'
    dec rsp; sdvig sp
    mov [rsp], dl ;saving dl - lower byte rdx
    inc rcx; rcx - length
    test rax, rax
    jne .calc_loop; jump if 0
    mov rdi, rsp; take last byte
    push rcx
    call print_string
    pop rcx
    inc rsp
    add rsp, rcx
    ret

; Выводит знаковое 8-байтовое число в десятичном формате 
print_int:
    xor rax, rax
    cmp rdi, 0
    jl .neg; jump if rdi < 0
    jmp print_uint

    .neg:
    push rdi
    mov rdi, 45
    call print_char; print '-'
    pop rdi
    neg rdi; rdi
    call print_uint
    ret

; Принимает два указателя на нуль-терминированные строки, возвращает 1 если они равны, 0 иначе
string_equals:
    xor rcx, rcx
    xor rax, rax
.loop:
    mov al, byte[rdi+rcx]
    cmp al, byte[rsi+rcx]
    jne .neq
    inc rcx
    test al, al
    jnz .loop
.yet:
    mov rax, 1
    ret
.neq:
    xor rax, rax
    ret

; Читает один символ из stdin и возвращает его. Возвращает 0 если достигнут конец потока
read_char:
    xor rdi, rdi ; stdin
    xor rax, rax ; sys_read
    mov rdx, 1   ; len
    
    push 0
    mov rsi, rsp ; buf
    syscall
    pop rax
    ret 

; Принимает: адрес начала буфера, размер буфера
; Читает в буфер слово из stdin, пропуская пробельные символы в начале, .
; Пробельные символы это пробел 0x20, табуляция 0x9 и перевод строки 0xA.
; Останавливается и возвращает 0 если слово слишком большое для буфера
; При успехе возвращает адрес буфера в rax, длину слова в rdx.
; При неудаче возвращает 0 в rax
; Эта функция должна дописывать к слову нуль-терминатор

read_word:
    xor rcx, rcx
    .loop:
        push rdi
        push rsi
        push rcx
        call read_char
        pop rcx
        pop rsi
        pop rdi
        test rax, rax 
        jz .exit
        cmp rcx, rsi
        jz .end
        test rcx, rcx
        jz .first
    .char:
        test rax, rax
        jz .loop
        cmp rax, 0x20 ; if rax = ' ' -> goto exit
        jz .exit
        cmp rax, 0x10 ; if rax = /n -> goto exit
        jz .exit
        cmp rax, 0x9    ; if rax = /t -> goto exit
        jz .exit
        mov [rdi+rcx], rax
        inc rcx
        jmp .loop
    .first:
        test rax, rax
        jz .loop
        cmp rax, ' ' ; if rax = ' ' -> goto exit
        jz .loop
        cmp rax, '\n' ; if rax = /n -> goto exit
        jz .loop
        cmp rax, 0x9 ; if rax = /t -> goto exit
        jz .loop
        jmp .char
    .exit: ; if string is good
        mov byte[rdi+rcx], 0
        mov rax, rdi
        mov rdx, rcx
        ret
    .end: ; bufer overflow
        xor rax, rax
        ret 
 

; Принимает указатель на строку, пытается
; прочитать из её начала беззнаковое число.
; Возвращает в rax: число, rdx : его длину в символах
; rdx = 0 если число прочитать не удалось
parse_uint:

  xor rax, rax
  xor rcx, rcx
  xor rdx, rdx

.loop:
  mov dl, byte[rdi + rcx]
  cmp dl, 48 ; goto if dl <48
  jb .end
  cmp dl, 58 ; goto if dl > 58
  ja .end

  sub rdx, 48
  imul rax, 10
  add rax, rdx
  inc rcx
  jmp .loop
.end:

  mov rdx, rcx
  ret


parse_int:
    xor rax, rax
    cmp byte [rdi], 45 ;check for -  fors symbol
    jnz .positive
    inc rdi
    call parse_uint
    neg rax
    inc rdx
    ret
    .positive:
    call parse_uint
    ret

; Принимает указатель на строку, указатель на буфер и длину буфера
; Копирует строку в буфер
; Возвращает длину строки если она умещается в буфер, иначе 0
string_copy:
    xor rcx, rcx
    call string_length
    cmp rax, rdx; if len string>len buffer - invalid 
    jae .invalid
    push rax
.loop:
    mov al, byte[rdi + rcx] ; byte to rl
    mov byte[rsi + rcx], al ; add to rsi byte
    inc rcx
    cmp al, 0 ; check if end
    je .end
    jmp .loop
.invalid:
    xor rax, rax
    ret
.end:
    pop rax
    ret
