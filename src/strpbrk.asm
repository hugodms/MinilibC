global strpbrk

strpbrk:
    mov rcx, 0

.loop1:         ;rdi loop
    cmp byte [rdi+rcx], 0
    je .isNull
    mov byte r8b, [rdi+rcx]
    mov rdx, 0

.loop2:         ;rsi loop
    cmp byte [rsi+rdx], 0
    je .next
    cmp byte r8b, [rsi+rdx]
    je .register
    inc rdx
    jmp .loop2

.next:
    inc rcx
    jmp .loop1

.isNull:
    mov rax, 0
    ret

.register:      ;good exit
    mov rax, rdi
    add rax, rcx
    ret
