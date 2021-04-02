global strcmp
strcmp:
    mov rcx, 0

.loop:
    mov bl, byte [rdi+rcx]
    mov dl, byte [rsi+rcx]
    cmp bl, 0                   ;check no finish
    je .check
    cmp bl, dl                  ;if egal
    jne .exitSub
    inc rcx
    jmp .loop

.check:
    cmp dl, 0                   ;check no finish
    je .exitEgal
    jmp .exitSub

.exitEgal:
    mov rax, 0
    ret

.exitSub:
    sub bl, dl                  ;result
    movsx rax, bl
    ret
