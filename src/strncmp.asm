global strncmp
strncmp:
    mov rcx, 0

.loop:
    cmp rcx, rdx                ;check index to arg[2]
    je .exitSub
    mov r8b, byte [rdi+rcx]
    mov r9b, byte [rsi+rcx]
    cmp r8b, 0                  ;check no finish
    je .check
    cmp r8b, r9b                ;if egal
    jne .exitSub
    inc rcx
    jmp .loop

.check:
    cmp r9b, 0                  ;check no finish
    je .exitEgal
    jmp .exitSub

.exitEgal:
    mov rax, 0
    ret

.exitSub:
    sub r8b, r9b                ;result
    movsx rax, r8b
    ret
