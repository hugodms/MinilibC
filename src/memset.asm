global memset
memset:
    mov rcx, 0

.loop:
    cmp rcx, rdx                ;index != arg[2]
    jz .end
    mov byte [rdi+rcx], sil     ;replace arg[0][index] = arg[1]
    inc rcx
    jmp .loop

.end:                           ;retur modif
    mov rax, rdi
    ret
