/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_square.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ada-cunh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/06 15:32:35 by ada-cunh          #+#    #+#             */
/*   Updated: 2016/09/15 14:47:45 by ada-cunh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"


/* no 15, check si la piece est un carré */

int square(char *s)
{
	int i;

	i = 0;
	while (i < 20)
	{
			while (s[i] != '#')
				i++;
		if (s[i] == '#' && s[i + 1] == '#' && s[i + 5] == '#' 
			&& s[i + 6] == '#')
			return (1);
		else 
			return (2);
	}
	return (0);
}

/* no 14, check si la piece est une barre horizontale 
check caractere 1 et 4
*/

int bar_hor(char *s)
{
	int i;

	i = 0;
	while (i < 20)
	{
		while (s[i] != '#')
				i++;
		if (s[i] == '#' && s[i + 3] == '#')
			return (1);
		else
			return (2);
	}
	return (0);
}

/* no 13, check si la piece est une barre verticale 
check caractere 1 et 16
*/

int bar_ver(char *s)
{
	int i;

	i = 0;
	while (i < 20)
	{
		while (s[i] != '#')
				i++;
		if (s[i] == '#' && s[i + 15] == '#')
			return (1);
		else
			return (2);
	}
	return (0);
}

/* no 12 , check la piece suivante 
   ###
     #
*/

int l1(char *s)
{
	int i;

	i = 0;
	while (i < 20)
	{
		while (s[i] != '#')
				i++;
		if (s[i] == '#' && s[i + 2] == '#' && s[i + 7] == '#')
			return (1);
		else
			return (2);
	}
	return (0);
}

/* no 11, check la piece suivante 
   ##
   #
   #
*/

int l2(char *s)
{
	int i;

	i = 0;
	while (i < 20)
	{
		while (s[i] != '#')
				i++;
		if (s[i] == '#' && s[i + 1] == '#' && s[i + 10] == '#')
			return (1);
		else
			return (2);
	}
	return (0);
}
