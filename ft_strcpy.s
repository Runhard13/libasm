; char *ft_strcpy(char *dst, char const *src);

; rdi = dst, rsi = src, rcx - counter, dl - temp for src[i]

; Copies the C string pointed by source into the array pointed by destination, including the terminating null character
; (and stopping at that point).To avoid overflows, the size of the array pointed by destination shall be long enough to
; contain the same C string as source (including the terminating null character), and should not overlap in memory with source.


global _ft_strcpy

section .text

_ft_strcpy:
    xor         rcx, rcx                ; i = 0;
    cmp         rsi, 0
    jz          return                  ; if (!src) -> return
    jmp         copy                    ; start to copy

increment:
    inc         rcx

copy:
    mov         dl, byte [rsi + rcx]   ; tmp = src[i]
    mov         byte [rdi + rcx], dl   ; dst[i] = tmp
    cmp         dl, 0
    jnz         increment              ; while tmp != '\0' i++;

return:
    mov         rax, rdi                ; return(dst)
    ret


