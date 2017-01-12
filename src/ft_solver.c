/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solver.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboste <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 20:45:34 by nboste            #+#    #+#             */
/*   Updated: 2017/01/12 04:33:17 by nboste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"
#include "ft_list.h"

static int	get_max_width(char **map)
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

	i = 0;
	map = malloc(sizeof(char*) * MAP_W);
	while (i < MAP_W)
	{
		map[i] = malloc(sizeof(char) * MAP_W);
		i++;
	}
	reset_map(map);
	sol = backtrack(tetrs, map);
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

	if (!area)
		area = 0x7fffffff;
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
						if (get_area(map) < area)
						{
							if (tetrs->next)
								backtrack(tetrs->next, map);
							else
								update_sol(&area, &sol, map);
						}
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
	return (sol);
}
