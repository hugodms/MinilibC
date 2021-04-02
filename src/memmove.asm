global memmove
memmove:
    mov rcx, 0

.loop:
    cmp rcx, rdx                ;index to arg[2]
    jz .end
    mov byte al, [rsi+rcx]
    mov byte [rdi+rcx], al      ;replace
    inc rcx
    jmp .loop

.end:                           ;return good str
    mov rax, rdi
    ret
