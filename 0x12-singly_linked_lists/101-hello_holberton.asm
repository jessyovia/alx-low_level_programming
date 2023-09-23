section .data
    hello_format db "Hello, Holberton",10,0  

section .text
    global main

    extern printf

main:
    push rbp            
    mov rdi, hello_format  
    call printf        
    pop rbp             

    ; Exit the program
    mov rax, 60        
    xor rdi, rdi        
    syscall
