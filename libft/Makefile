#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ada-cunh <ada-cunh@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/03/04 11:23:17 by ada-cunh          #+#    #+#              #
#    Updated: 2016/04/15 17:21:50 by ada-cunh         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

CFLAGS	=-Wall -Wextra -Werror -I$(I) -O3

NAME	=libft.a

I = ./libft.h

SRC		=	ft_putnbr.c \
			ft_putchar.c \
			ft_putstr.c \
			ft_strlen.c \
			ft_strdup.c \
			ft_strcpy.c \
			ft_strncpy.c \
			ft_strcmp.c \
			ft_strncmp.c \
			ft_strstr.c \
			ft_strnstr.c \
			ft_strcat.c \
			ft_strncat.c \
			ft_strlcat.c \
			ft_strrev.c \
			ft_isascii.c \
			ft_isalpha.c \
			ft_isdigit.c \
			ft_isalnum.c \
			ft_isprint.c \
			ft_isspace.c \
			ft_toupper.c \
			ft_tolower.c \
			ft_strchr.c \
			ft_strrchr.c \
			ft_bzero.c \
			ft_atoi.c \
			ft_strdigit.c \
			ft_memset.c \
			ft_memcpy.c \
			ft_memccpy.c \
			ft_memmove.c \
			ft_memchr.c \
			ft_memcmp.c \
			ft_memalloc.c \
			ft_memdel.c \
			ft_strcut.c \
			ft_strnew.c \
			ft_strdel.c \
			ft_strclr.c \
			ft_striter.c \
			ft_striteri.c \
			ft_strmap.c \
			ft_strmapi.c \
			ft_strequ.c \
			ft_strnequ.c \
			ft_strsub.c \
			ft_strjoin.c \
			ft_strtrim.c \
			ft_strsplit.c \
			ft_swap.c \
			ft_itoa.c \
			ft_putendl.c \
			ft_putchar_fd.c \
			ft_putstr_fd.c \
			ft_putendl_fd.c \
			ft_putnbr_fd.c \
			ft_lstadd.c \
			ft_lstiter.c \
			ft_lstdel.c \
			ft_lstdelone.c \
			ft_lstnew.c \
			ft_lstmap.c \
			ft_lstrev.c \
			ft_iseven.c \

H		=./libft.h

OBJET	=$(SRC:.c=.o)

cc		=gcc

all: $(NAME)

$(NAME): $(OBJET)
	ar rc $(NAME) $(OBJET)
	ranlib $(NAME)

clean:
	/bin/rm -f $(OBJET)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re