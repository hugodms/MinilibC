global strcasecmp

strcasecmp:
    mov rcx, 0

.loop:
    mov bl, byte [rdi+rcx]
    mov dl, byte [rsi+rcx]
    cmp bl, 0                   ;check finish
    je .check
    cmp bl, 97
    jae .change1                ;change a -> A
    jmp .next1

.change1:
    cmp bl, 122
    jbe .sub1
    jmp .next1

.sub1:
    sub bl, 32                  ;calcul for change

.next1:
    cmp dl, 97
    jae .change2                ;change a -> A
    jmp .next2

.change2:
    cmp dl, 122
    jbe .sub2
    jmp .next2

.sub2:
    sub dl, 32                  ;calcul for change

.next2:
    cmp bl, dl
    jne .exitSub
    inc rcx
    jmp .loop

.check:
    cmp dl, 0
    je .exitEgal
    jmp .exitSub

.exitEgal:
    mov rax, 0                  ;result egal
    ret

.exitSub:
    sub bl, dl                  ;result
    movsx rax, bl
    ret

