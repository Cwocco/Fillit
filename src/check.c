/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ada-cunh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 05:02:08 by ada-cunh          #+#    #+#             */
/*   Updated: 2016/12/14 05:22:09 by ada-cunh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int superpose_check(list *tetrs, char **map)
{
	// i = x, j = y;
	int x;
	int y;
	int i;
	int j;
	
	x = (tetrs->coord.x - tetrs->anchor.x);
	y = (tetrs->coord.y - tetrs->anchor.y);
	while (y < ((tetrs->coord.y - tetrs->anchor.y) + 3)
	{
		while (x < ((tetrs->coord.x - tetrs->anchor.x) + 3)
		{
			if (Les coordonnées du tetriminos et 
			si les coordonnee de lendroit ou je veux poser mon tetri sur la map sont = et
			que sur ces meme coordonnee sur la map sont != 0 -> erreur)
			// Maybe c'est caif ((tetrs->coord.y - tetrs->anchor.y) + 3 && map[y][x] = 0)
				return (1);
			x++;
		}
		y++;
	}
	return (0);
}

/*
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
*/
//Est ce que je peux faire tetrs->pos[tetrs->x + tetrs-> y] pour pouvoir changer de pos
// et etre sur la pos suivante d'un diese du tetrs
