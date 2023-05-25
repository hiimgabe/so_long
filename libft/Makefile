# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gamoreir <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/12 10:18:50 by gamoreir          #+#    #+#              #
#    Updated: 2023/04/23 17:07:20 by gamoreir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
FLAGS = -Wall -Wextra -Werror
INCLUDE = .
RM = rm -f
AR = ar -rc
NAME = libft.a

OBJ = ft_isalpha.o ft_isdigit.o ft_isalnum.o ft_isascii.o ft_isprint.o ft_strlen.o ft_memset.o ft_bzero.o ft_memmove.o ft_memcpy.o \
      ft_strlcpy.o ft_toupper.o ft_tolower.o ft_strchr.o ft_strrchr.o ft_strncmp.o ft_memchr.o ft_memcmp.o ft_strnstr.o ft_atoi.o \
      ft_calloc.o ft_strdup.o ft_strmapi.o ft_substr.o ft_strlcat.o ft_strjoin.o ft_strtrim.o ft_split.o ft_itoa.o ft_putchar_fd.o \
	  ft_putstr_fd.o ft_putendl_fd.o ft_putnbr_fd.o ft_striteri.o

	BONUS_OBJ = ft_lstnew.o ft_lstadd_front.o ft_lstsize.o ft_lstlast.o ft_lstadd_back.o ft_lstclear.o ft_lstdelone.o ft_lstiter.o ft_lstmap.o

%.o : %.c
	$(CC) $(FLAGS) -c $< -o $@ -I $(INCLUDE)

all: $(NAME)

bonus: $(OBJ) $(BONUS_OBJ)
	$(AR) $(NAME) $^

$(NAME): $(OBJ)
	$(AR) $(NAME) $^

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

#so:
#	$(CC) -nostartfiles -fPIC $(CFLAGS) $(OBJ)
#	gcc -nostartfiles -shared -o libft.so $(OBJ)
