# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abkhairi <abkhairi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/09 12:57:30 by abkhairi          #+#    #+#              #
#    Updated: 2023/10/03 09:45:42 by abkhairi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
SRCS = so_long.c check_map.c  function_helper.c read_map.c check_valid_path.c draw.c move_player.c

OBJS = $(SRCS:.c=.o)
COMPILER = cc
CFLAGS = -Wall -Werror -Wextra

all: extern $(NAME)

extern:
	make -C libftpush/
	make -C finalprintf/
	make -C get_next_line/

bonus : extern
		make -C bonus/

$(NAME): $(OBJS)
	$(COMPILER) -o $(NAME) $(OBJS) \
	libftpush/libft.a finalprintf/libftprintf.a \
	get_next_line/libft_getnextline.a \
	-lmlx -framework OpenGL -framework AppKit

%.o: %.c so_long.h
	$(COMPILER) $(CFLAGS) -c $<

clean:
	make clean -C libftpush/
	make clean -C finalprintf/
	make clean -C get_next_line/
	make clean -C bonus/
	rm -rf $(OBJS)

fclean: clean
	rm -rf libftpush/libft.a
	rm -rf finalprintf/libftprintf.a
	rm -rf get_next_line/libft_getnextline.a
	rm -rf bonus_src/$(NAME)
	rm -rf $(NAME)

re: fclean all

.PHONY: all extern clean fclean re