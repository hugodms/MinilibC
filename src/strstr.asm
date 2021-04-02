global strstr

strstr:
    mov rcx, 0

.loop:
    cmp byte [rdi+rcx], 0       ;verif last
    je .isNull
    mov rdx, 0
    cmp byte [rdi+rdx], 0       ;verif arg[1] != NULL
    je .all
    mov r9, rcx

.checkloop:
    cmp byte [rsi+rdx], 0       ;loop verif for cherhce the good one
    je .end
    mov byte r8b, [rsi+rdx]
    cmp byte [rdi+r9], r8b      ;equal ?
    jne .next
    inc rdx
    inc r9
    jmp .checkloop

.next:
    inc rcx
    jmp .loop

.isNull:
    mov rax, 0                  ;return NULL
    ret

.all:
    mov rax, rdi                ;return all
    ret

.end:
    mov rax, rdi                ;return a part
    add rax, rcx
    ret
