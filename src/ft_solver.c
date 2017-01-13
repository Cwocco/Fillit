/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solver.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboste <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 20:45:34 by nboste            #+#    #+#             */
/*   Updated: 2017/01/13 02:15:28 by nboste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"
#include "ft_list.h"

int		get_max_width(char **map)
{
	t_2ipair	tmp;
	t_2ipair	max;

	max.x = 0;
	max.y = 0;
	tmp.x = 0;
	while (tmp.x < MAP_W)
	{
		tmp.y = 0;
		while (tmp.y < MAP_W)
		{
			if (map[tmp.x][tmp.y])
			{
				max.x = tmp.x > max.x ? tmp.x : max.x;
				max.y = tmp.y > max.y ? tmp.y : max.y;
			}
			tmp.y++;
		}
		tmp.x++;
	}
	max.x += 1;
	max.y += 1;
	return (max.x > max.y ? max.x : max.y);
}

void	fillit_solve(list *tetrs)
{
	char	**map;
	char	**sol;
	int		i;
	t_2ipair tmp;
	t_2ipair max;

	map = (char **)ft_memalloc(sizeof(char *) * MAP_W);
	sol = (char **)ft_memalloc(sizeof(char *) * MAP_W);
	i = 0;
	while (i < MAP_W)
	{
		map[i] = (char *)ft_memalloc(sizeof(char) * MAP_W);
		sol[i] = (char *)ft_memalloc(sizeof(char) * MAP_W);
		i++;
	}
	backtrack(tetrs, map, sol);
	max.x = get_max_width(sol);
	tmp.x = 0;
	while (tmp.x < max.x)
	{
		tmp.y = 0;
		while (tmp.y < max.x)
		{
			if (sol[tmp.x][tmp.y])
				ft_putchar(sol[tmp.x][tmp.y]);
			else
				ft_putchar('.');
			tmp.y++;
		}
		ft_putchar('\n');
		tmp.x++;
	}
}

void	backtrack(list *tetrs, char **map, char **sol)
{
	static int	area;
	static double ratio;
	t_2ipair	pos;
	t_2ipair	anchor;

	if (!area)
	{
		area = 0x7fffffff;
		ratio = 0x7fffffff;
	}
	pos.x = 0;
	while (pos.x < MAP_W)
	{
		pos.y = 0;
		while (pos.y < MAP_W)
		{
				anchor.x = 3;
				while (anchor.x >= 0)
				{
					anchor.y = 3;
					while (anchor.y >= 0)
					{
						if (add_tetr_map((char *)tetrs->data, pos, anchor, map))
						{
					//		if (get_area(map) < area)
					//		{
								if (tetrs->next != NULL)
									backtrack(tetrs->next, map, sol);
								else
									update_sol(&area, sol, map);
					//		}
							rm_tetr_map((char *)tetrs->data, pos, anchor, map);
						}
						anchor.y--;
					}
					anchor.x--;
				}
			pos.y++;
		}
		pos.x++;
	}
}
