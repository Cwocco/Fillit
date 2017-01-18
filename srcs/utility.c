/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ada-cunh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 05:02:08 by ada-cunh          #+#    #+#             */
/*   Updated: 2017/01/18 04:47:11 by nboste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

void	update_map(t_tetr *tetr, t_2ipair pos, char **map, t_bool mode)
{
	t_2ipair	tmp;
	char		t;

	tmp.x = 0;
	while (tmp.x < tetr->size.y)
	{
		tmp.y = 0;
		while (tmp.y < tetr->size.x)
		{
			if (tmp.x + pos.y < MAP_W && tmp.y + pos.x < MAP_W
					&& tetr->tetr[tmp.y + tetr->size.x * tmp.x])
			{
				if (!mode)
				{
					t = tetr->tetr[tmp.y + tetr->size.x * tmp.x];
					map[tmp.x + pos.y][tmp.y + pos.x] = t;
				}
				else
					map[tmp.x + pos.y][tmp.y + pos.x] = 0;
			}
			tmp.y++;
		}
		tmp.x++;
	}
}

int		add_tetr_map(t_tetr *tetr, t_2ipair pos, char **map)
{
	t_2ipair	tmp;

	tmp.x = 0;
	while (tmp.x < tetr->size.y)
	{
		tmp.y = 0;
		while (tmp.y < tetr->size.x)
		{
			if (tetr->tetr[tmp.y + tetr->size.x * tmp.x]
				&& (tmp.y + pos.x >= MAP_W ||
				tmp.x + pos.y >= MAP_W ||
				map[tmp.x + pos.y][tmp.y + pos.x]))
				return (0);
			tmp.y++;
		}
		tmp.x++;
	}
	update_map(tetr, pos, map, 0);
	return (1);
}

void	update_sol(t_static_backtrack *v, char **sol, char **map)
{
	t_2ipair	tmp;

	v->area = v->n_area;
	v->score = v->n_score;
	tmp.x = 0;
	while (tmp.x < MAP_W)
	{
		tmp.y = 0;
		while (tmp.y < MAP_W)
		{
			sol[tmp.x][tmp.y] = map[tmp.x][tmp.y];
			tmp.y++;
		}
		tmp.x++;
	}
}

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

void	print_sol(char **sol)
{
	t_2ipair	max;
	t_2ipair	tmp;

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
