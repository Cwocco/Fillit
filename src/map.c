/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ada-cunh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 23:21:32 by ada-cunh          #+#    #+#             */
/*   Updated: 2016/11/24 23:21:38 by ada-cunh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		first_map(char **map, int map_size)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < map_size)
	{
		while (j < map_size)
		{
			map[i][j] = '.';
			j++
		}
		map[i][j] = '\0';
		i = 0;
		j++;
	}
}

/* Malloc char**, prend en parametre la taille de la map */

char		**malloc_map(int map_size)
{
	char	**map;
	int 	i;

	i = 0;
	if (!(map = (char **)malloc(sizeof(char *) * map_size) + 1))
		return (NULL);
	while (i < map_size)
	{
		if (!(map = (char *)malloc(sizeof(char) * map_size) + 1))
			return (NULL);
		i++;
	}
	first_map(map, map_size);
	return (map);
}
