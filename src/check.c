/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ada-cunh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 05:02:08 by ada-cunh          #+#    #+#             */
/*   Updated: 2016/12/07 04:15:29 by ada-cunh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"


int superpose_check(list *tetrs, char **map, int map_size, int x, int y)
{
	int i;
	int j;
	
	i = 0;
	j = 0;
	while ((j < tetrs->y) && (y < map_size))
	{
		while (i < tetrs->x)
		{
			i++;
		}
		j++;
	}
	return (0);
}

int try_other_way(list *tetrs, char **map, int map_size, int x, int y)
{
	// i = x, j = y
	int i;
	int j;
	int pos;

	i = 0;
	j = 0;
	pos = tetrs->x + (tetrs->y * 4);
	while (tetrs->pos != '\0' && y < map_size)
	{
		if (tetrs->pos == '\n')
			{
				y++;
				pos = pos + 1; 
			}
	}
	
}
