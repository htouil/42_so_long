# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: htouil <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/24 19:23:26 by htouil            #+#    #+#              #
#    Updated: 2023/04/24 19:23:27 by htouil           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	= so_long

SRCS 	= so_long.c map_get.c \
		get_next_line/get_next_line.c get_next_line/get_next_line_utils.c \
		libft_utils/ft_itoa.c libft_utils/ft_split.c \
		parser/check_extension.c parser/check_frame.c parser/check_mtx_components.c \
		parser/check_path.c parser/check_tmp_components.c parser/print_errors.c \
		mlx/create_images.c mlx/put_images.c \
		mlx/moves/move_down.c mlx/moves/move_left.c \
		mlx/moves/move_right.c mlx/moves/move_up.c \
		mlx/moves/count_moves.c mlx/moves/keycodes.c

OBJS	= $(SRCS:.c=.o)

CC		= cc

FLAGS	= -Wall -Wextra -Werror

MLX		= -lmlx -framework OpenGL -framework AppKit

.PHONY = all clean fclean re

all: $(NAME)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(MLX) $(OBJS) -o $(NAME)

clean: 
	rm -f $(OBJS)

fclean:	clean
	rm -f $(NAME)

re: fclean all
