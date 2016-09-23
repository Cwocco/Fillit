/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_tetri3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ada-cunh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/15 16:35:02 by ada-cunh          #+#    #+#             */
/*   Updated: 2016/09/15 16:35:06 by ada-cunh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"

/* no 4, check la piece suivante
	  #
	###
*/

int		l8(char *s)
{
	int i;

	i = 0;
	while (i < 20)
	{
		while (s[i] != '#')
				i++;
		if (s[i] == '#' && s[i + 3] == '#' && s[i + 5] == '#')
			return (1);
		else
			return (2);
	}
	return (0);
}

/* no 5, check la piece suivante 
	##
   ##
*/

int		stairs(char *s)
{
	int i;

	i = 0;
	while (i < 20)
	{
		while (s[i] != '#')
				i++;
		if (s[i] == '#' && s[i + 1] == '#' && s[i + 4] == '#' 
			&& s[i + 5] == '#')
			return (1);
		else
			return (2);
	}
	return (0);
}

/* no 6 check la piece suivante
	#
	##
	 #
*/

int		strairs2(char *s)
{
	int i;

	i = 0;
	while (i < 20)
	{
		while (s[i] != '#')
				i++;
		if (s[i] == '#' && s[i + 5] == '#' && s[i + 6] == '#' 
			&& s[i + 11] == '#')
			return (1);
		else
			return (2);
	}
	return (0);
}

/* no 7, check la piece suivante
	##
	 ##
*/

int		stairs3(char *s)
{
	int i;

	i = 0;
	while (i < 20)
	{
		while (s[i] != '#')
				i++;
		if (s[i] == '#' && s[i + 2] == '#' && s[i + 6] == '#' 
			&& s[i + 7] == '#')
			return (1);
		else
			return (2);
	}
	return (0);
}


/* no 8, check la piece suivante
	#
   ##
   #
*/

int		strairs4(char *s)
{
	int i;

	i = 0;
	while (i < 20)
	{
		while (s[i] != '#')
				i++;
		if (s[i] == '#' && s[i + 4] == '#' && s[i + 5] == '#'
			&& s[i + 9] == '#')
			return (1);
		else
			return (2);
	}
	return (0);
}