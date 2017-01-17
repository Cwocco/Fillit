/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solver.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboste <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 20:45:34 by nboste            #+#    #+#             */
/*   Updated: 2017/01/17 23:14:05 by nboste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"

void	fillit_solve(t_list *tetrs)
{
	char	**map;
	char	**sol;
	int		i;

	map = (char **)ft_memalloc(sizeof(char *) * MAP_W);
	sol = (char **)ft_memalloc(sizeof(char *) * MAP_W);
	i = 0;
	while (i < MAP_W)
	{
		map[i] = (char *)ft_memalloc(sizeof(char) * MAP_W);
		sol[i] = (char *)ft_memalloc(sizeof(char) * MAP_W);
		i++;
	}
	backtrack(tetrs, map, sol, 2600);
	print_sol(sol);
}

void	backtrack(t_list *tetrs, char **map, char **sol, double c)
{
	static int		area;
	static double	score;
	static double	n_score;
	t_2ipair	pos;
	t_2ipair	anchor;

	if (!area)
	{
		area = 0x7fffffff;
		score = 0x7fffffff;
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
						if (add_tetr_map((char *)tetrs->content, pos, anchor, map))
						{
							int a = get_max_width(map);
							a *= a;
							n_score += c * (pos.x + 5 * pos.y - anchor.x - 5 * anchor.y);
							if (a < area || (a == area &&  n_score < score))
							{
								if (tetrs->next != NULL)
									backtrack(tetrs->next, map, sol, c / 10);
								else
								{
									update_sol(&area, sol, map);
									score = n_score;
								}
							}
							n_score -= c * (pos.x + 5 * pos.y - anchor.x - 5 * anchor.y);
							update_map((char *)tetrs->content, pos, anchor, map, 1);
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
