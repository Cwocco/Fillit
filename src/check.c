/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ada-cunh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 05:02:08 by ada-cunh          #+#    #+#             */
/*   Updated: 2017/01/12 00:46:08 by nboste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
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
			map[tmp.x + pos.x - anchor.x][tmp.y + pos.y - anchor.y] = tetr[tmp.x + 4 * tmp.y];
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
			if (tetr[tmp.x + 4 * tmp.y] &&
				(tmp.x + pos.x - anchor.x < 0 ||
				 tmp.x + pos.x - anchor.x >= MAP_W ||
				 tmp.y + pos.y - anchor.y < 0 ||
				 tmp.y + pos.y - anchor.y >= MAP_W ||
				 map[tmp.x + pos.x - anchor.x][tmp.y + pos.y - anchor.y]))
				return (0);
			tmp.y++;
		}
		tmp.x++;
	}
	update_map(tetr, pos, anchor, map);
	return (1);
}

void			update_sol(int *area, char ***sol, char **map)
{
	t_2ipair	tmp;
	t_2ipair	max;

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
	if (max.x * max.y < *area)
	{
		*area = max.x * max.y;
		*sol = (char **)malloc(sizeof(char) * MAP_W);
		tmp.x = 0;
		while (tmp.x < MAP_W)
			*sol[tmp.x++] = (char *)malloc(sizeof(char) * MAP_W);
		tmp.x = 0;
		tmp.y = 0;
		while (tmp.x < MAP_W)
		{
			while (tmp.y < MAP_W)
			{
				*sol[tmp.x][tmp.y] = map[tmp.x][tmp.y];
				tmp.y++;
			}
			tmp.x++;
		}
	}
}
