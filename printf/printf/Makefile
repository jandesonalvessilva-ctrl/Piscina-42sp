# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaalves- <jaalves-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/06/17 12:51:39 by jaalves-          #+#    #+#              #
#    Updated: 2026/06/17 12:51:45 by jaalves-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= libftprintf.a

CC				= cc
CFLAGS			= -Wall -Wextra -Werror

SRCS			= ft_printf.c ft_printf_utils.c
OBJS			= $(SRCS:.c=.o)
HEADER			= ft_printf.h
AR				= ar rsc

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
