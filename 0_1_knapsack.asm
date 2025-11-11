section .data
    input_format db "%d", 0
    output_format db "%d", 10, 0
    
section .bss
    n resd 1
    total_w resd 1
    weights resd 100    ; Max 100 items
    values resd 100
    
section .text
    global main
    extern scanf
    extern printf
    extern malloc
    
; knapsack(n, weights*, values*, total_W)
; Arguments: rdi=n, rsi=weights*, rdx=values*, rcx=total_W
; Returns: rax = max value
knapsack:
    push rbp
    mov rbp, rsp
    sub rsp, 48             ; Local variables space
    
    ; Save arguments on stack
    mov [rbp-8], rdi        ; n
    mov [rbp-16], rsi       ; weights*
    mov [rbp-24], rdx       ; values*
    mov [rbp-32], rcx       ; total_W
    
    ; Base case: if n < 0 or total_W == 0
    cmp rdi, 0
    jl .return_zero
    cmp rcx, 0
    je .return_zero
    
    ; Calculate weights[n] address
    mov rax, rdi
    sal rax, 2              ; n * 4 (sizeof int)
    add rax, rsi            ; weights + (n*4)
    mov r8d, [rax]          ; r8d = weights[n]
    
    ; if weights[n] <= total_W
    cmp r8d, ecx
    jg .not_selected_only
    
    ; Calculate selected case: knapsack(n-1, weights, values, total_W - weights[n]) + values[n]
    push rcx                ; Save total_W
    push r8                 ; Save weights[n]
    
    ; Prepare arguments for recursive call
    dec rdi                 ; n-1
    sub ecx, r8d            ; total_W - weights[n]
    call knapsack
    
    pop r8                  ; Restore weights[n]
    pop rcx                 ; Restore total_W
    
    ; Add values[n] to result
    mov r9, [rbp-8]         ; n
    sal r9, 2               ; n * 4
    add r9, [rbp-24]        ; values + (n*4)
    add eax, [r9]           ; selected = result + values[n]
    
    push rax                ; Save selected result
    
    ; Calculate not_selected case: knapsack(n-1, weights, values, total_W)
    mov rdi, [rbp-8]
    dec rdi                 ; n-1
    mov rsi, [rbp-16]       ; weights
    mov rdx, [rbp-24]       ; values
    mov rcx, [rbp-32]       ; total_W
    call knapsack
    
    pop r8                  ; Restore selected result
    
    ; Return max(selected, not_selected)
    cmp r8d, eax
    cmovg eax, r8d
    jmp .return
    
.not_selected_only:
    ; Only not_selected case
    dec rdi                 ; n-1
    call knapsack
    jmp .return
    
.return_zero:
    xor eax, eax
    
.return:
    mov rsp, rbp
    pop rbp
    ret

main:
    push rbp
    mov rbp, rsp
    
    ; Read n
    lea rdi, [rel input_format]
    lea rsi, [rel n]
    xor eax, eax
    call scanf
    
    ; Read weights
    xor r12, r12            ; counter
    movsxd r13, dword [rel n]
.read_weights_loop:
    cmp r12, r13
    jge .read_values_start
    
    lea rdi, [rel input_format]
    lea rsi, [rel weights]
    lea rsi, [rsi + r12*4]
    xor eax, eax
    call scanf
    
    inc r12
    jmp .read_weights_loop
    
.read_values_start:
    ; Read values
    xor r12, r12
.read_values_loop:
    cmp r12, r13
    jge .read_total_w
    
    lea rdi, [rel input_format]
    lea rsi, [rel values]
    lea rsi, [rsi + r12*4]
    xor eax, eax
    call scanf
    
    inc r12
    jmp .read_values_loop
    
.read_total_w:
    ; Read total_W
    lea rdi, [rel input_format]
    lea rsi, [rel total_w]
    xor eax, eax
    call scanf
    
    ; Call knapsack(n-1, weights, values, total_W)
    mov edi, [rel n]
    dec edi
    lea rsi, [rel weights]
    lea rdx, [rel values]
    mov ecx, [rel total_w]
    call knapsack
    
    ; Print result
    mov esi, eax
    lea rdi, [rel output_format]
    xor eax, eax
    call printf
    
    xor eax, eax
    pop rbp
    ret