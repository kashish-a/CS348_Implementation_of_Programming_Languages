; Author: Kashish Aggarwal
; Question Number 14a
section .data
    enter_n db 'Enter n(Number of elements in one array): ',0
    merged_printing db 'Merged Array - ',0
    input_first_array db 'Enter elements of array 1',0
    input_second_array db 'Enter elements of array 2',0
    endline db 10
    space db ' ',0

section .bss
    n resd 1
    output_buffer resb 100 
    size_buffer resb 100 
    array2 resd 300
    array1 resd 300
    array3 resd 700

section .text
    global _start:

_start:
    mov eax, enter_n                         ; Load address of the prompt string
    call pehla

    call padho
    mov [n], eax

    add esp,4
    sub esp,4

    mov eax, input_first_array
    call pehla

    add esp,4
    sub esp,4

    mov eax, endline
    call pehla

    add esp,4
    xor ecx,ecx
    sub esp,4


; read elements of first array
takingPehlaArray:
    cmp ecx, [n]
    jge takingDusraArray
    push ecx
    call padho
    pop ecx
    
    add esp,4
    sub esp,4
    mov [array1 + ecx*4],eax
    add ecx,1
    jmp takingPehlaArray
    add esp,4
    sub esp,4


; reading second array
takingDusraArray:
    mov eax, input_second_array
    call pehla
    mov eax, endline
    call pehla

    xor ecx, ecx

secondArrayInp:
    cmp ecx, [n]
    jge mergeArrays
    push ecx
    call padho
    pop ecx
    mov [array2 + ecx*4],eax
    add ecx ,1
    jmp secondArrayInp

; Making the final array
mergeArrays:
    xor esi, esi
    xor edi, edi 
    xor ecx, ecx

; merge function
merge:
    cmp esi, [n]
    jge bachiDusri
    cmp edi, [n]
    jge bachiPehli
    
    mov eax, [array1 + esi*4]
    mov ebx, [array2 + edi*4]
    cmp eax, ebx
    jle pehliKaLo
    ; element to be picked from array 2
    mov [array3 + ecx*4], ebx
    add edi,1
    add ecx,1
    jmp merge

; element to be picked from array 1
pehliKaLo:
    mov [array3 + ecx*4], eax
    add esi,1
    add ecx,1
    add esp,4
    sub esp,4
    jmp merge   


bachiPehli:
    cmp esi, [n]
    jge printingFinalAnswer
    mov eax, [array1 + esi*4]
    mov [array3 + ecx*4], eax
    add esi,1
    add ecx,1
    jmp bachiPehli

bachiDusri:
    cmp edi, [n]
    jge printingFinalAnswer
    mov eax, [array2 + edi*4]
    mov [array3 + ecx*4], eax
    add edi,1
    add ecx,1
    add esp,4
    sub esp,4
    jmp bachiDusri


;final array
printingFinalAnswer:
    mov eax, merged_printing
    add esp,4
    sub esp,4
    call pehla
    mov ecx, 0


printLoop:
    mov eax, [n]
    add esp,4
    sub esp,4
    add eax, eax
    cmp ecx, eax
    jge exit

    mov eax, [array3 + ecx*4]
    push ecx
    call print_number
    mov eax, space
    call pehla
    pop ecx
    
    add ecx,1
    add esp,4
    sub esp,4
    jmp printLoop


; finishing the program

exit:
    mov eax, endline
    call pehla
    mov eax, 1
    xor ebx,ebx
    int 0x80

;take n
padho:
    mov eax, 3
    mov ebx, 0
    mov ecx, size_buffer
    mov edx, 100
    add esp,4
    sub esp,4
    int 0x80

    xor eax, eax
    mov ebx, 0
    mov ecx, size_buffer


stringing:
    mov bl, [ecx]
    cmp bl, 0x0a
    je stringingDone
    cmp bl, 32
    je stringingDone
    sub bl, '0'
    imul eax, 10
    add eax, ebx
    add ecx,1
    add esp,4
    sub esp,4
    jmp stringing

stringingDone:
    ret


pehla:
    pusha                                  
    mov edx, 0                              ; Reset string length
    mov ecx, eax                            

count_len:
    cmp byte [ecx + edx], 0                 
    je write_string                         ; If null terminator, calculate length
    inc edx                                
    jmp count_len

write_string:
    mov eax, 4                              ; syscall: sys_write
    mov ebx, 1                              ; file descriptor: stdout
    int 0x80                               
    popa                                 
    ret


;printing the number as string
print_number:
    mov ecx, output_buffer
    add ecx, 99
    add esp,4
    sub esp,4
    mov byte [ecx], 0 ; null terminating the string
    mov ebx, 10
    mov edi, ecx
    add esp,4
    sub esp,4

finalConversion:
    dec ecx
    xor edx, edx
    div ebx
    add dl, '0'
    mov [ecx], dl
    test eax, eax
    jnz finalConversion

    mov edx, edi
    sub edx, ecx
    mov eax, 4
    mov ebx, 1
    add esp,4
    sub esp,4
    int 0x80
    ret