# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gamoreir <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/26 10:17:06 by gamoreir          #+#    #+#              #
#    Updated: 2023/05/31 15:00:03 by gamoreir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRC = src/main.c src/map.c src/utils.c src/clear.c src/movement.c

OBJ = ${SRC:.c=.o}

CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror -g
INCLUDE = -I include
MAKE = make -C
LIBFT_PATH = libft
MLX_PATH = mlx
LIBFT = -L ${LIBFT_PATH} -lft
MLX = -L ${MLX_PATH} -lmlx -Ilmlx -lXext -lX11 -lm

.c.o:
	${CC} ${CFLAGS} ${INCLUDE} -c $< -o ${<:.c=.o}

$(NAME): ${OBJ}
	${MAKE} ${LIBFT_PATH}
	${MAKE} ${MLX_PATH}
	${CC} ${OBJ} ${LIBFT} ${MLX} -o ${NAME}

all: ${NAME}

clean:
	${MAKE} ${LIBFT_PATH} clean
	${MAKE} ${MLX_PATH} clean
	${RM} ${OBJ}

fclean: clean
	${MAKE} ${LIBFT_PATH} fclean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re
