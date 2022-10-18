	parse_uint:
mov r10, 10    
xor rax, rax   
xor rcx, rcx   
  .A:
xor r8, r8         
mov r8b, byte[rdi] 
cmp r8, '9'        
jg .end
cmp r8, '0'
jl .end
sub r8, '0'        
mul r10            
add rax, r8        
inc rdi            
inc rcx            
jmp .A
	.end:
mov rdx, rcx   
ret
