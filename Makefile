# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cdrennan <cdrennan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/30 12:49:18 by cdrennan          #+#    #+#              #
#    Updated: 2020/11/30 22:49:23 by cdrennan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libasm.a

SOURCES = ft_strlen.s ft_strcpy.s ft_strcmp.s ft_write.s ft_read.s ft_strdup.s
OBJS = $(SOURCES:.s=.o)

%.o:%.s
	nasm -f macho64 $<

all: $(NAME)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

test:
	gcc main.c -Wall -Werror -Wextra -L. -lasm
	./a.out | cat -e



.PHONY: all re clean fclean