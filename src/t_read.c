/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_read.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ada-cunh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/14 14:44:03 by ada-cunh          #+#    #+#             */
/*   Updated: 2016/11/28 03:56:51 by ada-cunh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"


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
		return (NULL);
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
	if (/*index == 21*/ && s[20] != '\n' && s[21] != '\n')
		return (4);
	if (!(ft_check_contact(s)))
		return (5);
	if (!(ft_nb_tetri(s)))
		return (6);
	return (0);
}

char 		*ft_read(int fd)
{
	char *buf;
	int index;
	/*Ici j'hesite a soit malloc les tetriminos un par un (21) et a mettre dans une boucle 
	en fonction du nb de tetri lu (malloc(nb_tetri_lu * 21) ou de malloc 546, vu qu'on sait
	qu'on peut recevoir que 26 tetriminos max (21 * 26 = 546)*/
	//buf = (char *)malloc(sizeof(char *) * (21));
	if (!(buf = (char *)malloc(sizeof(char) * (546))))
		return (NULL);
	if (!(index = read(fd, buf, 546)))
		return (NULL);
	// JSUIS FATIGUÉ JARRIVE PAS A REFLECHIR NIKSAMER
}
