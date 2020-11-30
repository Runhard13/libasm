; ssize_t ft_read(int fd, void *buf, size_t count)

;read() attempts to read up to count bytes from file descriptor fd into the buffer starting at buf.

; rdi = fd, rsi = buf, rdx = count, rax - return value

section .text

global          _ft_read
extern          ___error

_ft_read:
    mov         rax, 0x2000003      ; call sys_read
    syscall
    jc          error               ; if error occurs, carry flag will be set
    ret
error:
    push        rax                 ; save errno to stack
    call        ___error            ; rax now is *int to errno
    pop         r8                  ; take sys_read return from stack
    mov         [rax], r8           ; *int = errno
    mov         rax, -1             ; set correct return value
    ret                             ; return