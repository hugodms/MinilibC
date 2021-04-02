global strlen
strlen:
    mov rax, 0

.loop:          ;loop for incrementation
    cmp byte [rdi], 0
    jz .end
    inc rdi
    inc rax
    jmp .loop

.end:           ;return result
    ret
