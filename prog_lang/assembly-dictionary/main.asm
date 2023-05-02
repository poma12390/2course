%define BUFFER_SIZE 256
%define SHIFT 8

section .rodata
start_msg:
    db 'Enter the key: ', 0
err_msg: 
    db 'Error, when reading', 10, 0
not_found_msg: 
    db 'cannot found the key', 10, 0
found_msg: 
    db 'Value: ', 0


section .data
%include "word.inc"


section .text
extern find_word
extern print_dict
%include "lib.inc"

global _start
_start:

    mov rdi, start_msg
    mov rsi, 1
    call print_string
    mov rsi, BUFFER_SIZE ;проверка на overflow
    mov rdi, rsp
    call read_word
    test rax, rax ;проверка на ошибку
    jz .err_read ;ошибка ввода
    mov rsi, NEXT_ELEM ;в rsi перове совпадение 
    mov rdi, rax ;в rdi введенное слово
    call find_word 
    cmp rax, 0  ;if rax==0 -> .not_found
    je .not_found

    .found:
        add rax, SHIFT ;смещение к адресу начала ключа
        push rax
        mov rsi, 1
        mov rdi, found_msg
        call print_string ;выводим сообщение о том что найдена строка, дальше нужно саму строку вывести
        ;пара состоит из key_string \0 value_string \0
        ;нам нужна value_string
        pop rax ;в rax - адрес ключа
        mov rdi, rax
        call string_length
        inc rax
        add rdi, rax ;rdi = addr + key_len + 1(нуль терминатор)
        mov rsi, 1
        jmp .end

    .err_read:
        mov rdi, err_msg
        mov rsi, 2 ;ошибка ввода
        jmp .end

    .not_found:
        mov rdi, not_found_msg
        mov rsi, 2 ;слово не найдено
        

    .end:
        call print_string
        call print_newline
        add rsp, BUFFER_SIZE ;восстанавливаем указатель стека и уходим в закат
        call exit
	
