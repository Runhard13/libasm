# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cdrennan <cdrennan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/30 12:49:18 by cdrennan          #+#    #+#              #
#    Updated: 2020/11/30 13:01:05 by cdrennan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libasm.a
CC = nasm
CFLAFS = -f macho64

SOURCES = ft_strlen.s
OBJS = $(SOURCES:.s=.o)


all: $(NAME)

$(NAME):
	ar rc $(NAME) $(OBJS)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

test:
	gcc -Wall -Werror -Wextra -L. -lasm -o main.c


.PHONY: all re clean fclean