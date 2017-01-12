/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ada-cunh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 05:02:08 by ada-cunh          #+#    #+#             */
/*   Updated: 2017/01/12 04:12:17 by nboste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"
#include <stdlib.h>

void	update_map(char *tetr, t_2ipair pos, t_2ipair anchor, char **map)
{
	t_2ipair	tmp;

	tmp.x = 0;
	while (tmp.x < 4)
	{
		tmp.y = 0;
		while (tmp.y < 4)
		{
			if (tmp.x + pos.y - anchor.y >= 0
					&& tmp.y + pos.x - anchor.x >= 0
					&& tmp.x + pos.y - anchor.y < MAP_W
					&& tmp.y + pos.x - anchor.x < MAP_W
					&& !map[tmp.x + pos.y - anchor.y][tmp.y + pos.x - anchor.x])
				map[tmp.x + pos.y - anchor.y][tmp.y + pos.x - anchor.x] = tetr[tmp.y + 4 * tmp.x];
			tmp.y++;
		}
		tmp.x++;
	}
}

int		add_tetr_map(char *tetr, t_2ipair pos, t_2ipair anchor, char **map)
{
	t_2ipair	tmp;

	tmp.x = 0;
	while (tmp.x < 4)
	{
		tmp.y = 0;
		while (tmp.y < 4)
		{
			if (tetr[tmp.y + 4 * tmp.x] &&
				(tmp.y + pos.x - anchor.x < 0 ||
				 tmp.y + pos.x - anchor.x >= MAP_W ||
				 tmp.x + pos.y - anchor.y < 0 ||
				 tmp.x + pos.y - anchor.y >= MAP_W ||
				 map[tmp.x + pos.y - anchor.y][tmp.y + pos.x - anchor.x]))
				return (0);
			tmp.y++;
		}
		tmp.x++;
	}
	update_map(tetr, pos, anchor, map);
	return (1);
}

void	rm_tetr_map(char *tetr, t_2ipair pos, t_2ipair anchor, char **map)
{
	t_2ipair	tmp;

	tmp.x = 0;
	while (tmp.x < 4)
	{
		tmp.y = 0;
		while (tmp.y < 4)
		{
			if (tetr[tmp.y + 4 * tmp.x] &&
				(tmp.y + pos.x - anchor.x < 0 ||
				 tmp.y + pos.x - anchor.x >= MAP_W ||
				 tmp.x + pos.y - anchor.y < 0 ||
				 tmp.x + pos.y - anchor.y >= MAP_W ||
				 map[tmp.x + pos.y - anchor.y][tmp.y + pos.x - anchor.x]))

			map[tmp.x + pos.y - anchor.y][tmp.y + pos.x - anchor.x] = 0;
			tmp.y++;
		}
		tmp.x++;
	}
}

void			update_sol(int *area, char ***sol, char **map)
{
	t_2ipair	tmp;
	int			n_area;

	n_area = get_area(map);
	if (n_area < *area)
	{
		*area = n_area;;
		*sol = (char **)malloc(sizeof(char *) * MAP_W);
		tmp.x = 0;
		while (tmp.x < MAP_W)
			(*sol)[tmp.x++] = (char *)malloc(sizeof(char) * MAP_W);
		tmp.x = 0;
		while (tmp.x < MAP_W)
		{
			tmp.y = 0;
			while (tmp.y < MAP_W)
			{
				(*sol)[tmp.x][tmp.y] = map[tmp.x][tmp.y];
				tmp.y++;
			}
			tmp.x++;
		}
	}
}

int		get_area(char **map)
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
	return (max.x * max.y);
}
