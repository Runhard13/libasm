;/* ************************************************************************** */
;/*                                                                            */
;/*                                                        :::      ::::::::   */
;/*   ft_strlen.s                                        :+:      :+:    :+:   */
;/*                                                    +:+ +:+         +:+     */
;/*   By: cdrennan <cdrennan@student.42.fr>          +#+  +:+       +#+        */
;/*                                                +#+#+#+#+#+   +#+           */
;/*   Created: 2020/11/30 11:40:55 by cdrennan          #+#    #+#             */
;/*   Updated: 2020/11/30 11:40:55 by cdrennan         ###   ########.fr       */
;/*                                                                            */
;/* ************************************************************************** */

global _ft_strlen

section .text

_ft_strlen:
    xor rax, rax            ; set return value to 0
    jmp _loop                ; start loop for len

_increment:
    inc rax                 ; len++;

_loop:
    cmp byte [rdi + rax], 0 ; compare str[len] and 0
    jne _increment          ; len++ if not equal

_return:
    ret