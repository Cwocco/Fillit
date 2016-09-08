/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_square.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ada-cunh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/06 15:32:35 by ada-cunh          #+#    #+#             */
/*   Updated: 2016/09/06 15:32:45 by ada-cunh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"


/* no 15 */

int ft_check_square(char *s)
{
	int i;

	i = 0;
	while (i < 20)
	{
		if (s[i] == '#' && s[i + 1] == '#' && s[i + 5] == '#' 
			&& s[i + 6] == '#')
			return (1);
		i++;
	}
	return (0);
}

/* no 14 */

int ft_check_bar_hor(char *s)
{
	int i;

	i = 0;
	while (i < 20)
	{
		if (s[i] == '#' && s[i + 4] == '#')
			return (1);
		i++;
	}
	return (0);
}

/* no 13 */

int ft_check_bar_ver(char *s)
{
	int i;

	i = 0;
	while (i < 20)
	{
		if (s[i] == '#' && s[i + 15] == '#')
			return (1);
		i++;
	}
	return (0);
}

int ft_L1(char *s)
{
	
}