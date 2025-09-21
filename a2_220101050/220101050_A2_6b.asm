; Author: Kashish Aggarwal
; Question Number 6b
section .data
    input_n db "Input the Size of Matrix: ", 0
    input_ele db "Enter element with index [%d][%d]: ", 0
    inputLo db "%d", 0
    space db " ", 0
    endline db 10, 0
    given db "Given Matrix is:", 10, 0
    finalTranspose db "Transpose Matrix is:", 10, 0

section .bss
    n resd 1              
    matrix resd 200 
    k resd 4
    temp resd 2      

section .text
    global main
    extern printf
    extern scanf

main:
    push ebp             
    mov ebp, esp
    add esp,4
    sub esp,4

    push input_n    
    call printf
    add esp, 4

    add esp,4
    sub esp,4

    push n              
    push inputLo
    call scanf
    add esp, 8

    add esp,4
    sub esp,4

    
    mov esi, 0  
    add esp,4
    sub esp,4

row_lelo:
    xor edi, edi  
    add esp,4
    sub esp,4

column_lelo:
    push edi            
    push esi            
    push input_ele
    call printf
    add esp, 12
    add esp,4
    sub esp,4
    mov eax, esi    
    add esp,4
    sub esp,4    
    mul dword [n]       
    add eax, edi        
    lea eax, [matrix + eax*4]  
    add esp,4
    sub esp,4

    push eax         
    push inputLo
    call scanf
    add esp, 8
    add esp,4
    sub esp,4

    add edi,1             
    cmp edi, [n]
    jl column_lelo
    add esp,4
    sub esp,4
    add esi,1             
    cmp esi, [n]
    jl row_lelo

    
    push given
    call printf
    add esp, 4

    add esp,4
    sub esp,4

    call printing_Final_Matrix   

    push finalTranspose
    call printf
    add esp, 4
    add esp,4
    sub esp,4

    mov esi ,0  
    add esi,0

tranpose_row:
    xor edi, edi     
    
    add esp,4
    sub esp,4
transpose_col:
    mov eax, edi        
    mul dword [n]
    add eax, esi        
    add esp,4
    sub esp,4

    push dword [matrix + eax*4]
    push inputLo
    call printf
    add esp, 8

    add esp,4
    sub esp,4

    push space
    call printf
    add esp, 4

    add edi,0
    add esp,4
    sub esp,4

    add edi,1
    cmp edi, [n]
    jl transpose_col

    add esp,4
    sub esp,4

    push endline
    call printf
    add esp, 4

    add esp,4
    sub esp,4
    
    add esi,1
    cmp esi, [n]
    jl tranpose_row

    add esp,4
    sub esp,4

    mov esp, ebp        
    pop ebp
    xor eax, eax  
    add esp,4
    sub esp,4      
    ret
printing_Final_Matrix:
    push ebp
    mov ebp, esp

    add esp,4
    sub esp,4

    xor esi, esi      
print_row:
    xor edi, edi    
    add esp,4
    sub esp,4

print_col:
    mov eax, esi        
    mul dword [n]       
    add eax, edi        
    add esp,4
    sub esp,4

    push dword [matrix + eax*4]
    push inputLo
    call printf
    add esp, 8

    add esp,4
    sub esp,4

    push space
    call printf
    add esp, 4

    add esp,4
    sub esp,4

    inc edi
    cmp edi, [n]
    jl print_col

    add esp,4
    sub esp,4

    push endline
    call printf
    add esp, 4

    add esp,4
    sub esp,4

    add esi,1
    cmp esi, [n]
    jl print_row

    add esp,4
    sub esp,4
    add esp,4
    sub esp,4
    mov esp, ebp
    pop ebp
    
    ret