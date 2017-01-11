/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solver.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboste <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 20:45:34 by nboste            #+#    #+#             */
/*   Updated: 2017/01/12 00:45:42 by nboste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"
#include "ft_list.h"

void	fillit_solve(list *tetrs)
{
	char	**map;
	char	**sol;
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
	ft_putstr("END.\n");
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

char		**backtrack(list *tetrs, char **map)
{
	static int	area;
	static char	**sol;
	t_2ipair	pos;
	t_2ipair	anchor;
	char		*z;

	pos.x = 0;
	z = (char *)ft_memalloc(sizeof(char) * 16);
	while (pos.x < MAP_W)
	{
		pos.y = 0;
		while (pos.y < MAP_W)
		{
			anchor.x = 0;
			while (anchor.x < 4)
			{
				anchor.y = 0;
				while (anchor.y < 4)
				{
					if (add_tetr_map((char *)tetrs->data, pos, anchor, map))
					{
						if (tetrs->next)
							backtrack(tetrs->next, map);
						else
							update_sol(&area, &sol, map);
						update_map(z, pos, anchor, map);
					}
					anchor.y++;
				}
				anchor.x++;
			}
			pos.y++;
		}
		pos.x++;
	}
	return (sol);
}
