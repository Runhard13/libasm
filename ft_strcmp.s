; int   ft_strcmp(char const *s1, char const *s2)

; rdi = s1, rsi = s2, rcx - counter, r8b - temp for s1[i]

; This function starts comparing the first character of each string.If they are equal to each other, it continues with
; the following pairsuntil the characters differ or until a terminating null-character is reached.

global _ft_strcmp

section .text

_ft_strcmp:
    xor             rcx, rcx                 ; i = 0;
    cmp             rdi, 0                   ; if s1 == null
    jz              null_handle
    cmp             rsi, 0                   ; if s2 == null
    jz              null_handle

take_char:
    mov             r8b, byte[rdi + rcx]     ; tmp = s1[i]
    cmp             r8b, byte[rsi + rcx]
    jne             compare                  ; if tmp != s2[i] -> compare and return
    cmp             r8b, 0
    jz              compare                  ; if tmp == '\0' -> compare and return
    cmp             byte[rsi + rcx], 0       ; if s[2] == '\0' -> compare and return
    jz              compare
    inc             rcx                      ; all other cases i++
    jmp             take_char                ; take another chars

compare:
    sub             r8b, byte[rsi + rcx]     ; tmp - s2[i]
    jz              return_zero              ; s1[i] == s2[i], i++;
    jb              return_minus             ; s1[i] < s2[i], return (-1)
    ja              return_one               ; s1 > s2, return (1)

null_handle:
    cmp             rdi, rsi
    jz              return_zero              ; s1 = s2 = null. Return (0)
    jb              return_minus             ; NULL < s2. Return (-1)
    ja              return_one               ; s1 > NULL. Return (1)

return_zero:
    mov             rax, 0
    ret
return_one:
    mov             rax, 1
    ret
return_minus:
    mov             rax, -1
    ret
