/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_tetri2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ada-cunh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/15 14:51:53 by ada-cunh          #+#    #+#             */
/*   Updated: 2016/09/15 14:52:06 by ada-cunh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"

/* no 10, check la piece suivante
   #
   ###
*/

int 	l3(char *s)
{
	int i;

	i = 0;
	while (i < 20)
	{
		if (s[i] == '#' && s[i + 5] == '#' && s[i + 7] == '#')
			return (1);
		else 
			return (0);
		i++;
	}
}

/* no 9, check la piece suviante
   #
   #
   ##
*/

int 	l4(char *s)
{
	int i;

	i = 0;
	while (i < 20)
	{
		if (s[i] == '#' && s[i + 9] == '#' && s[i + 10] == '#')
			return (1);
		else
			return (0);
		i++;
	}
}










