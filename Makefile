NAME = libftprintf.a
LIBFT = libft/libft.a

CFLAGS = -Wall -Wextra -Werror
INCLUDE = .
CC = cc
RM = rm -f
AR = ar -rc

OBJ = ft_printf.o ft_printf_functions.o

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all
