#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ada-cunh <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/07/28 15:28:26 by ada-cunh          #+#    #+#              #
#*   Updated: 2016/12/01 21:40:09 by nboste           ###   ########.fr       *#
#                                                                              #
#******************************************************************************#

NAME =	fillit

INC =	./includes

LIB =	./libft

SRC =	src/main.c \
		src/t_read.c \
		src/ft_create_elem.c \
		src/ft_list_push_back.c \
		src/ft_error.c \
		src/ft_solver.c \
		src/check.c \

OBJ =	$(SRC:src/%.c=%.o)

CC =	gcc

FLG	=	-Wall -Werror -Wextra	

all: $(NAME)

$(NAME):
	gcc $(FLG) -c $(SRC) -I $(INC) -I $(LIB)
	gcc -g -o $(NAME) $(OBJ) ./libft/libft.a

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
