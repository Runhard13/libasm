;/* ************************************************************************** */
;/*                                                                            */
;/*                                                        :::      ::::::::   */
;/*   ft_strcpy.s                                        :+:      :+:    :+:   */
;/*                                                    +:+ +:+         +:+     */
;/*   By: cdrennan <cdrennan@student.42.fr>          +#+  +:+       +#+        */
;/*                                                +#+#+#+#+#+   +#+           */
;/*   Created: 2020/11/30 13:30:27 by cdrennan          #+#    #+#             */
;/*   Updated: 2020/11/30 13:30:27 by cdrennan         ###   ########.fr       */
;/*                                                                            */
;/* ************************************************************************** */


global _ft_strcpy

section .text

_ft_strcpy:
    xor rcx, rcx                ; i = 0;
    xor rdx, rdx                ; tmp = 0;
    cmp rsi, 0                  ; if (!src)
    jz return
    jmp copy

increment:
    inc rcx

copy:
    mov dl, byte [rsi + rcx]   ; tmp = src[i]
    mov byte [rdi + rcx], dl   ; dst[i] = tmp
    cmp rdx, 0
    jnz increment

return:
    mov rax, rdi                ; return(dst)
    ret


