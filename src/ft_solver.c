/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solver.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboste <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 20:45:34 by nboste            #+#    #+#             */
/*   Updated: 2016/12/07 04:19:49 by ada-cunh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"
#include "ft_list.h"

void	fillit_solve(list *tetrs)
{
	char	**map;
	char	*sol;
	int		i;

	i = 0;
	map = malloc(sizeof(char*) * MAP_W);
	while (i < MAP_W)
	{
		map[i] = malloc(sizeof(char) * MAP_W);
		i++;
	}
	reset_map(map);
	sol = backtrack(tetrs, map);
	ft_putstr(sol);
}

void	reset_map(char **map)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < MAP_W)
	{
		while (j < MAP_W)
		{
			map[i][j] = 0;
			j++;
		}
		i++;
	}
}




list *backtrack(list *tetrs, char **map, int map_size)
{
	int x;
	int y;
	
	x = 0;
	y = 0;

	if (!(tetrs && map))
		ft_error(2);
	while (map && (y < map_size))
	{
		while (map && (x < map_size))
		{
			if (add_tetrs(tetrs, map, x, y, map_size))
			{
				backtrack(tetrs->next, map, map_size);
				del_tetrs(tetris, map, x, y, map_size);
			}
			x++;
		}
		y++;
	}
	// Ici j'voudrais faire remplir la map solve pour pouvoir la print
	return (map);
}


// Pour add_map faudra une fonction qui check si quand on add les tetriminos se superposent pas
