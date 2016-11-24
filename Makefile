#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ada-cunh <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/07/28 15:28:26 by ada-cunh          #+#    #+#              #
#    Updated: 2016/11/24 23:24:34 by ada-cunh         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME =	fillit

INC =	-I./includes 

LIB =	-L./libft

SRC =	t_read.c \
		map.c \

OBJ =	$(SRC:.c=.o)

CC =	gcc

FLG	=	-Wall -Werror -Wextra	

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft/
	gcc -O3 $(FLG) -I libft/ -c $(SRC)
	gcc -g -o $(NAME) $(OBJ) -L./libft/

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re