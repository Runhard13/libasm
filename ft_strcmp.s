;/* ************************************************************************** */
;/*                                                                            */
;/*                                                        :::      ::::::::   */
;/*   ft_strcmp.s                                        :+:      :+:    :+:   */
;/*                                                    +:+ +:+         +:+     */
;/*   By: cdrennan <cdrennan@student.42.fr>          +#+  +:+       +#+        */
;/*                                                +#+#+#+#+#+   +#+           */
;/*   Created: 2020/11/30 15:03:36 by cdrennan          #+#    #+#             */
;/*   Updated: 2020/11/30 15:03:36 by cdrennan         ###   ########.fr       */
;/*                                                                            */
;/* ************************************************************************** */

global _ft_strcmp

section .text

_ft_strcmp:
    xor rcx, rcx                ; i = 0;
    cmp rdi, 0                  ; if s1 == null
    jz null_handle
    cmp rsi, 0                  ; if s2 == null
    jz null_handle

take_char:
    mov r8b, byte[rdi + rcx]     ; s1[i] = tmp
    cmp r8b, byte[rsi + rcx]
    jne compare                 ; if tmp != s2[i]
    cmp r8b, 0                   ; if s[1] == '\0'
    jz compare
    cmp byte[rsi + rcx], 0      ; if s[2] == '\0'
    jz compare
    inc rcx                     ; i++
    jmp take_char

compare:
    sub r8b, byte[rsi + rcx]     ; tmp - s2[i]
    jz return_zero              ; s1[i] == s2[i], i++;
    jb return_minus             ; s1[i] < s2[i], return (-1)
    ja return_one               ; s1 > s2, return (1)

null_handle:
    cmp rdi, rsi
    jz return_zero              ; s1 = s2 = null. Return (0)
    jb return_minus             ; NULL < s2. Return (-1)
    ja return_one               ; s1 > NULL. Return (1)

return_zero:
    mov rax, 0
    ret
return_one:
    mov rax, 1
    ret
return_minus:
    mov rax, -1
    ret
