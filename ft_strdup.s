; char *ft_strdup(const char *s)

; s = rdi, return = rax

section .text

global _ft_strdup
extern _malloc                              ; rdi - size, return rax
extern _ft_strlen                           ; rdi - str, return rax


_ft_strdup:
    push            rdi                     ; save s
    call            _ft_strlen              ; rax = len of s
    inc             rax                     ; +1 for '\0'
    mov             rdi, rax                ; make rdi = len + 1 for malloc call
    call            _malloc                 ; rax - pointer to allocated memory now
    cmp             rax, 0                  ; check malloc error
    pop             rdi                     ; get s back
    jz              ret_null                ; return null if malloc fails

prepare_copy:
    xor             rcx, rcx                ; counter = 0
    xor             rdx, rdx                ; tmp = 0
    jmp             copy

increment:
    inc             rcx                     ; i++

copy:
    mov             dl, byte[rdi + rcx]     ; tmp = s[i]
    mov             byte[rax + rcx], dl     ; ret[i] = tmp
    cmp             dl, 0
    jnz             increment               ; if (!(tmp == '\0')) i++
    jmp             return                  ; tmp == '\0', return

ret_null:
    xor             rax, rax                ; return (0)
    ret
return:
    ret