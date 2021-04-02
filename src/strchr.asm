global strchr
strchr:
    mov rcx, 0

.loop:                          ;loop increment
    cmp byte [rdi+rcx], 0       ;last value
    je .isNull
    cmp byte [rdi+rcx], sil     ;str[i] == c first ocurance
    je .goodEnd
    inc rcx
    jmp .loop

.isNull:                        ;return null
    mov rax, 0
    ret

.goodEnd:                       ;return pointer of 1st ocurance
    mov rax, rdi
    add rax, rcx
    ret
