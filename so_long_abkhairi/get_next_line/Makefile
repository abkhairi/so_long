# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abkhairi <abkhairi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/05 14:26:24 by abkhairi          #+#    #+#              #
#    Updated: 2023/09/05 14:26:29 by abkhairi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft_getnextline.a

CC = cc
CFLAGS = -Wall -Werror -Wextra

SRCS = get_next_line.c get_next_line_utils.c
OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	ar rc $(NAME) $(OBJS)
%.o : %.c get_next_line.h
	$(CC) $(CFLAGS) -c $<
clean :
	rm -rf $(OBJS)
fclean : clean
	rm -rf $(NAME)
re : fclean all