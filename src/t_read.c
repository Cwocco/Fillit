/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_read.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ada-cunh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/14 14:44:03 by ada-cunh          #+#    #+#             */
/*   Updated: 2016/11/29 21:30:30 by nboste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "ft_list.h"
#include "libft.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>


/*
   Verifie que les caracteres des tetriminos sont en contact avc un autre block
   Si la fonction return 4 ou 6, le tetriminos est valide
   */

int			ft_check_contact(char *s)
{
	int i;
	int	contact;

	i = 0;
	contact = 0;
	while (i < 20)
	{
		while (s[i] == '#')
		{
			if ((i + 1) < 20 && (s[i + 1] == '#'))
				contact++;
			if ((i + 5) < 20 && (s[i + 5] == '#'))
				contact++;
			if ((i - 1) >= 0 && (s[i - 1] == '#'))
				contact++;
			if ((i - 5) >= 0 && (s[i - 5] == '#'))
				contact++;
		}
		i++;
	}
	return (contact == 6 || contact == 8);
}


/* Compte le nombre de tetriminos */

int ft_nb_tetri(char *s)
{
	int i;
	int count_21;

	i = 0;
	count_21 = 0;
	while (s[i] != '\0')
	{
		if (s[i] == 21)
		{
			count_21++;
			i = 0;
		}
		i++;
	}
	if (count_21 > 26)
		return (0);
	return (count_21);
}

/*
   Verifie qu'un tetriminos est bien composé de 21 caracteres, un \n tout les 5 caracteres, les caracteres sont soit des "#" soit des "."
   Ici je bug brain un peu avc le parametre index, jcpu c'etait quoi mon idée avc, j'crois c'etait pour m'en servir dans le reader...
   */
int			ft_check_tetri(char *s) //(int index)
{
	int	i;

	i = 0;
	while (i < 20)
	{
		//Ici on avait fait des changements mais visiblement ca a pas push ou j'ai fail :)
		if (s[i] != '#' || s[i] != '.')
			return (1);
		//Ici on check qu'on retrouve bien un \n a la fin de chaque ligne
		if ((((i + 1) % 5) == 0) && s[i] != '\n')
			return (2);
		//Ici jcpu nique sa merelaput
		if (s[i] == '#' && (i % 5) < 4)
			return (3);
		i++;
	}
	//Ici index servira dans le read cf commentaire plus haut
	//	if (/*index == 21*/ && s[20] != '\n' && s[21] != '\n')
	//		return (4);
	if (!(ft_check_contact(s)))
		return (5);
	if (!(ft_nb_tetri(s)))
		return (6);
	return (0);
}

list		*ft_read(char *path)
{
	int		fd;
	char	buffer[20];
	list	*tetrs;
	char	letter;

	if((fd = open(path, O_RDONLY)) == -1)
		ft_error(2);
	tetrs = NULL;
	letter = 'A';
	while (read(fd, (void *)buffer, 20) > 0)
	{
		if (ft_check_tetri(buffer))
		{
			ft_list_push_back(&tetrs, (void *)get_tetr_map(buffer, letter));
			if (read(fd, (void *)buffer, 1) == 1 && buffer[0] != '\n')
				ft_error(2);
			letter++;
			if (letter > 'Z')
				ft_error(2);
		}
		else
			ft_error(2);
	}
	return (tetrs);
}

char		*get_tetr_map(char *buffer, char letter)
{
	char	*map;
	int		i;
	int		j;

	if(!(map = (char *)malloc(sizeof(char) * (16))))
		ft_error(2);
	i = 0;
	j = 0;
	while (i < 20)
	{
		if (j != 4 && j != 9 && j != 14)
		{
			if (buffer[j] == '#')
				map[i] = letter;
			else
				map[i] = 0;
			i++;
		}
		j++;
	}
	return (map);
}
