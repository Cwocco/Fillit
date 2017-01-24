/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solver.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboste <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 20:45:34 by nboste            #+#    #+#             */
/*   Updated: 2017/01/23 23:00:53 by nboste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"

static void		init_static_v(t_static_backtrack *v)
{
	v->area = 0x7fffffff;
	v->score = 0x7fffffff;
}

static void		updt_static_value(t_static_backtrack *v, t_map *map, double val)
{
	v->n_area = get_max_width(map);
	v->n_area *= v->n_area;
	v->n_score += val;
}

void			fillit_solve(t_list *tetrs)
{
	char	**map;
	char	**sol;
	int		i;
	t_map	m;

	m.size = 4 * get_list_size(tetrs);
	map = (char **)ft_memalloc(sizeof(char *) * m.size);
	sol = (char **)ft_memalloc(sizeof(char *) * m.size);
	i = 0;
	while (i < m.size)
	{
		map[i] = (char *)ft_memalloc(sizeof(char) * m.size);
		sol[i] = (char *)ft_memalloc(sizeof(char) * m.size);
		i++;
	}
	m.map = map;
	backtrack(tetrs, &m, sol, 2600);
	m.map = sol;
	print_sol(sol, get_max_width(&m));
}

void			backtrack(t_list *tetrs, t_map *map, char **sol, double c)
{
	static t_static_backtrack	v;
	t_2ipair					pos;

	if (!v.area)
		init_static_v(&v);
	pos.y = -1;
	while (++pos.y < map->size)
	{
		pos.x = -1;
		while (++pos.x < map->size)
			if (add_tetr_map((t_tetr *)tetrs->content, pos, map))
			{
				updt_static_value(&v, map, c * (2 * pos.x + 15 * pos.y));
				if (v.n_area < v.area
						|| (v.n_area == v.area && v.n_score < v.score))
				{
					if (tetrs->next != NULL)
						backtrack(tetrs->next, map, sol, c / 10);
					else
						update_sol(&v, sol, map);
				}
				v.n_score -= c * (2 * pos.x + 15 * pos.y);
				update_map((t_tetr *)tetrs->content, pos, map, 1);
			}
	}
}

int				get_list_size(t_list *l)
{
	int		i;

	i = 0;
	while (l)
	{
		l = l->next;
		i++;
	}
	return (i);
}
