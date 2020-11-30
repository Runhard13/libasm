; size_t ft_strlen (const char* str)

; rdi = str, rax = counter && return value

; The length of a C string is determined by the terminating null-character: A C string is as long as the number of
; characters between the beginning of the string and the terminating null character (without including the terminating
; null character itself).

global _ft_strlen

section .text

_ft_strlen:
    xor         rax, rax                ; set return value to 0
    jmp         loop                    ; start loop for len

increment:
    inc         rax                     ; len++;

loop:
    cmp         byte [rdi + rax], 0     ; compare str[len] and 0
    jne         increment               ; len++ if not equal

return:
    ret