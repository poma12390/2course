
section .text
global print_err
global exit
global string_length
global print_string
global print_char
global print_newline
global print_uint
global print_int
global string_equals
global read_char
global read_word
global parse_uint
global parse_int
global string_copy
 
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
    mov  rax, 1; code 1 = write
    syscall
    ret

; Принимает код символа и выводит его в stdout
print_char:
    xor rax, rax
    push rdi        ;   rdi -> stack, so rsp addressing to memory, that contains char_code
    mov rsi, rsp    ; rsp -> rsi, so rdi addressing to memory, that contains char_code

    mov rdx, 1  ; 1 -> rdx (char = 1 byte)
    mov rax, 1  ; code 1 for write
    mov rdi, 1  ; 1 -> rdi, descriptor (stdout)
    syscall
    pop rdi         ; pop increase rsp, but not clear the char_code
    ret

; Переводит строку (выводит символ с кодом 0xA)
print_newline:
    mov rdi, 0xa      ; move the new line character to rax
    call print_char
        ;mov [rsp+8], rax  ; put this on the stack
        ;mov rdi, 1      ; file descriptor = stdout
        ;lea rsi, [rsp+8]  ; buffer = address to write to console
        ;mov rdx, 1      ; number of bytes to write
        ;mov rax, 1      ; SYSCALL number for writing to STDOUT
        ;syscall           ; make the syscall
    ret

; Выводит беззнаковое 8-байтовое число в десятичном формате 
; Совет: выделите место в стеке и храните там результаты деления
; Не забудьте перевести цифры в их ASCII коды.
print_uint:
    xor rax, rax    
    mov rax, rdi; rax - number
    xor rcx, rcx
    dec rsp; sdvig sp
    ;mov [rsp], byte 0
    mov r8, 10; r8 = 10 CONST
    .calc_loop:
    xor rdx, rdx
    div r8; rax = rax / r8; rdx = rdx % r8
    add rdx, '0'
    ; saving result
    dec rsp; sdvig sp
    mov [rsp], dl ;saving dl - lower byte rdx
    ; count bytes on stack
    inc rcx; rcx - length
    ; while rax != 0
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
        cmp rax, 0 
        jz .exit
        cmp rcx, rsi
        jz .end
        cmp rcx, 0
        jz .first
    .char:
        cmp rax, 0
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
        cmp rax, 0
        jz .loop
        cmp rax, 0x20 ; if rax = ' ' -> goto exit
        jz .loop
        cmp rax, 0x10 ; if rax = /n -> goto exit
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
  mov rax, 0
  mov rcx, 0
  mov rdx, 0

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



; Принимает указатель на строку, пытается
; прочитать из её начала знаковое число.
; Если есть знак, пробелы между ним и числом не разрешены.
; Возвращает в rax: число, rdx : его длину в символах (включая знак, если он был) 
; rdx = 0 если число прочитать не удалось
;parse_int:
;    cmp byte[rdi], '+'	        ; Если первый символ = '+', то парсим
;	je .parse
;	cmp byte[rdi], '-'          ; Если первый символ не равен '-', то parse_uint, а иначе .parse
;	jne parse_uint
;	.parse:
;	    push rdi                ; Сохраняем указатель в стек
;	    inc rdi		            ; Сдвигаем указать на 1, чтобы убрать +/-
;	    call parse_uint	        ; Вызываем parse_uint
;	    pop rdi                 ; Возвращаем указатель
;	    inc rdx                 ; Увеличиваем длину строки на 1 из-за знака
;	    cmp byte[rdi], '+'	    ; Если знак +, то возврат, а иначе rax = rax * (-1)
;	    je .return
;	    neg rax		            ; rax = rax * (-1)
;	    .return:
;		    ret

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
    mov rcx, 0
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
    mov rax, 0
    ret
.end:
    pop rax
    ret
