NAME = so_long
NAME_BONUS = so_long_bonus

SRC = src/main.c src/map.c src/utils.c src/clear.c src/movement.c src/init.c src/check.c \
		src/sprites.c src/check_map.c

SRC_BONUS = src_bonus/main.c src_bonus/map.c src_bonus/utils.c src_bonus/clear.c src_bonus/movement.c src_bonus/init.c \
			src_bonus/animations.c src_bonus/enemy.c src_bonus/check.c src_bonus/coin.c src_bonus/sprites.c src_bonus/check_map.c

OBJ = ${SRC:.c=.o}

OBJ_BONUS = ${SRC_BONUS:.c=.o}

CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror -g
INCLUDE = -I include
MAKE = make -C
LIBFT_PATH = libft
MLX_PATH = mlx
LIBFT = -L ${LIBFT_PATH} -lft
MLX = -L ${MLX_PATH} -lmlx -Ilmlx -lXext -lX11 -lm

GREEN		= \033[38;5;47m
YELLOW		= \033[38;5;226m
RED			= \033[38;5;196m
END 		= \033[0m

.c.o:
	@${CC} ${CFLAGS} ${INCLUDE} -c $< -o ${<:.c=.o}
	@echo "[$(GREEN)compiling$(END)]: $<"

$(NAME): ${OBJ}
	@${MAKE} ${LIBFT_PATH}
	@${MAKE} ${MLX_PATH}
	@${CC} ${OBJ} ${LIBFT} ${MLX} -o ${NAME}
	@echo "$(GREEN)$(NAME) created$(END)"

$(NAME_BONUS): ${OBJ_BONUS}
	@${MAKE} ${LIBFT_PATH}
	@${MAKE} ${MLX_PATH}
	@${CC} ${OBJ_BONUS} ${LIBFT} ${MLX} -o ${NAME_BONUS}
	@echo "$(GREEN)$(NAME_BONUS) created$(END)"

all: ${NAME}

bonus: ${NAME_BONUS}

clean:
	@${MAKE} ${LIBFT_PATH} clean
	@${MAKE} ${MLX_PATH} clean
	@${RM} ${OBJ}
	@${RM} ${OBJ_BONUS}
	@echo "$(RED)cleaning objects$(END)"

fclean: clean
	@${MAKE} ${LIBFT_PATH} fclean
	@${RM} ${NAME}
	@${RM} ${NAME_BONUS}
	@echo "$(RED)$(NAME) deleted$(END)"
	@echo "$(RED)$(NAME_BONUS) deleted$(END)"

re: fclean all

re_bonus: fclean bonus

.PHONY: all clean fclean re
