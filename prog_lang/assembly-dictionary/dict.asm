section .text
%include "lib.inc"
global find_word
global print_dict
%define SHIFT 8
;в rdi- нужный ключ. в rsi - указатель на первую пару
find_word:
    .loop:
    	push rsi
    	add rsi, SHIFT	; Берем следующий элемент, сравниваем значение 
    	call string_equals ; с строкой ключа
    	pop rsi
    	test rax, rax ; Проверка на соответствие
    	jne .found 
    	mov rsi, [rsi] 	; Переходим к следующему
    	test rsi, rsi 	; если элемента нет,
    	je .not_found ; то завершаем поиск
    	jmp .loop 
    .found:
        mov rax, rsi ; rax = адрес начала вхождения 
        ret
    .not_found:
        xor rax, rax
        ret	

       
print_dict:

    .loop:
        
        mov rsi, r9
        mov rdi, r10            
        add rdi, SHIFT          ; получаем указатель ключа
        call print_string  ; вызываем
        call print_newline
        mov r10, rdi 
        mov r9, rsi                     
        mov rdi, [rdi]      ; указатель следующего элемента
        test rdi, rdi
        jnz .loop           ; повтор цикла, если не достигнут конец словаря
        xor rax, rax        ; возврат 0
    ret   
