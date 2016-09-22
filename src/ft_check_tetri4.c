/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_tetri4.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ada-cunh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/22 14:45:29 by ada-cunh          #+#    #+#             */
/*   Updated: 2016/09/22 14:45:41 by ada-cunh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "fillit.h"
#include "libft.h"

/* no 16, check la piece suivante
	#
	##
	#
*/

int		cross(char *s)
{
	int i;

	i = 0;
	while (i  < 20)
	{
		if (s[i] == '#' && s[i + 6] == '#' && s[i + 10] == '#')
			return (1);
		else
			return (0);
		i++;
	}
}

/* no 17, check la piece suivante
	#
   ##
   	#
*/

int		cross2(char *s)
{
	int i;

	i = 0;
	while (i < 20)
	{
		if (s[i] == '#' && s[i + 4] == '#' && s[i + 10] == '#')
			return (1);
		else
			return (0);
		i++;
	}
}

/* no 18, check la piece suivante 
	###
	 #
*/

int		cross3(char *s)
{
	int i;

	i = 0;
	while (i < 20)
	{
		if (s[i] == '#' && s[i + 2] == '#' && s[i + 6] == '#')
			return (1);
		else
			return (0);
		i++;
	}
}

/* no 19, check la piece suivante
	#
   ###
*/

int		cross4(char *s)
{
	int i;

	i = 0;
	while (i < 20)
	{
			if (s[i] == '#' && s[i + 4] == '#' && s[i + 6] == '#')
				return (1);
			else
				return (0);
	}
}

















