; ssize_t		ft_write(int fd, void const *buf, size_t nbyte)

; rdi = fd, rsi = buf, rdx = nbyte, rax - return value

section .text

global _ft_write
extern ___error

_ft_write:
    mov         rax, 0x2000004
    syscall
    jc          error              ; carry flag will be set if error occurs
    ret
error:
    push        rax                ; save errno to stack
    call        ___error           ; rax become pointer to errno
    pop         r8                 ; take errno value from the stack
    mov         [rax], r8          ; pointer to errno points to errno value now
    mov         rax, -1            ; return -1
    ret