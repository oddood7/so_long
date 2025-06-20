# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rmarecar <rmarecar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/28 13:31:36 by rmarecar          #+#    #+#              #
#    Updated: 2023/01/09 14:13:17 by rmarecar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libftprintf.a
CC		= gcc
CFLAGS	= -c -Wall -Wextra -Werror
RM		= /bin/rm -f

SRCS	= ft_split.c get_next_line.c get_next_line_utils.c utils.c ft_printf.c ft_putnbr_base.c ft_putnbr.c ft_putnbrunsigned.c ft_putstr.c ft_putchar.c
OBJS 	= $(SRCS:.c=.o)

$(NAME): $(OBJS)
		$(CC) $(CFLAGS) $(SRCS)
		ar -rcs $(NAME) $(OBJS)
all:	$(NAME)
clean:
		rm -f $(OBJS)
fclean: clean
	rm -f $(NAME)
re: fclean all
