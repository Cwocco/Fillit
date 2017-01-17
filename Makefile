#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ada-cunh <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/07/28 15:28:26 by ada-cunh          #+#    #+#              #
#*   Updated: 2017/01/16 02:51:01 by nboste           ###   ########.fr       *#
#                                                                              #
#******************************************************************************#

NAME =	fillit

INC =	-I./includes \
		-I./libft/includes \

LIB =	-L./libft \

SRC =	srcs/main.c \
		srcs/read.c \
		srcs/error.c \
		srcs/solver.c \
		srcs/utility.c \

OBJ =	$(SRC:srcs/%.c=obj/%.o)

CC =	gcc

FLG	=	-Wall -Werror -Wextra	

all: $(NAME)

$(NAME):
	make -C libft
	$(CC) $(FLG) $(LIB) $(INC) $(SRC) -lft -o $(NAME) -O3

clean:
	make -C libft clean
	rm -f $(OBJ)

fclean: clean
	rm -f libft/libft.a
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
