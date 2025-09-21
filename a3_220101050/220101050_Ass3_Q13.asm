;Author: Kashish Aggarwal
;Assignment 3
;Question Number: 13

;Sorting the array using QuickSort in Descending Order



section .data
    input_n: db "Enter number of elements (max 10): ", 0
    scan_n: db "%d", 0
    input_prompt: db "Enter number %d: ", 0
    scan_float: db "%lf", 0           
    print_array: db "Sorted array (Descending Order): ", 0
    print_0: db "Made last element as pivot: ", 0
    print_element: db "%.2lf ", 0     
    newline: db 10, 0

section .bss
    n: resd 1
    tempo: resd 1        
    array: resq 10   
    pivot: resq 1
    swapped: resq 1

section .text
    extern printf
    extern scanf
    global main

main:
    push ebp
    mov ebp, esp
    sub esp, 8      
    add esp,4
    sub esp,4

; Input number of elements(<=10)
    push input_n
    call printf
    add esp, 4
    add esp,4
    sub esp,4

    push n
    push scan_n
    call scanf
    add esp, 8
    add esp,4
    sub esp,4

; Validating the input if it is <=10 and >=0
; Code will end if not within bounds
    mov eax, [n]
    cmp eax, 10
    jg .done        
    cmp eax, 0
    jle .done       


; Input the array
    add esp,4
    sub esp,4
    mov esi,0    
.input_loop:
    cmp esi, [n]      
    jge .sort_prep     
    add esp,4
    sub esp,4

    push esi
    push input_prompt
    call printf
    add esp, 4
    add esp, 4

    lea eax, [array + esi*8]  
    push eax
    push scan_float
    call scanf
    add esp, 4
    add esp, 4
    add esp,4
    sub esp,4

    add esi,1
    jmp .input_loop
    add esp,4
    sub esp,4

.sort_prep:
    mov ecx, [n]                   
    sub ecx, 1
    add esp,4
    sub esp,4

; Marking the last element as pivot

.last_element_pivot:
    test ecx, ecx
    jz .print_prep                 
    add esp,4
    sub esp,4
    mov esi,0           


; recursion on the remaining array, right and left part
.rec_on_rem:
    mov eax, [n]
    sub eax,1
    cmp esi, eax
    ;recursion on right side of the pivot 
    jge .rec_on_right
    add esp,4
    sub esp,4

; putting the pivot element at the correct place


    fld qword [array + esi*8]        
    fld qword [array + esi*8 + 8]    
    fcomip st0, st1                  
    fstp st0          

;recursion on the left part and on the right part          
;Swapping the pivot    
    ;recursion on left part
    jbe .rec_on_left                    

    fld qword [array + esi*8]
    fld qword [array + esi*8 + 8]
    fstp qword [array + esi*8]
    fstp qword [array + esi*8 + 8]

    add esp,4
    sub esp,4

.rec_on_left:
    inc esi
    jmp .rec_on_rem
    add esp,4
    sub esp,4

.rec_on_right:
    dec ecx
    jmp .last_element_pivot
    add esp,4
    sub esp,4

.print_prep:
    push print_array
    call printf
    add esp, 4

    mov esi,0         
    add esp,4
    sub esp,4  

;printing the array
.print_loop:
    cmp esi, [n]
    jge .done

    fld qword [array + esi*8]
    sub esp, 8
    fstp qword [esp]               
    push print_element
    call printf
    add esp, 8
    add esp, 4
    add esp,4
    sub esp,4

    add esi,1 
    jmp .print_loop


.done:
    add esp,4
    sub esp,4
    mov esp, ebp
    pop ebp
    ret