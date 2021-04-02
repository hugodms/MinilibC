global rindex

rindex:
    mov rcx, 0

.loop:
    cmp byte [rdi+rcx], 0
    je .ifNull                  ;if not finish
    cmp byte [rdi+rcx], sil     ;check arg[0][idx] == arg[1]
    je .register
    jmp .next

.register:
    mov r8, rcx                 ;register last ocurance

.next:
    inc rcx
    jmp .loop

.ifNull:
    cmp r8, 0
    je .endNull
    jmp .end

.endNull:
    mov rax, 0x0                ;return NULL
    ret

.end:
    mov rax, rdi                ;return good
    add rax, r8
    ret
