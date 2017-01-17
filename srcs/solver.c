/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solver.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboste <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 20:45:34 by nboste            #+#    #+#             */
/*   Updated: 2017/01/17 23:33:35 by nboste           ###   ########.fr       */
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
	t_2ipair		pos;
	int				a;

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
			if (add_tetr_map((t_tetr *)tetrs->content, pos, map))
			{
				a = get_max_width(map);
				a *= a;
				n_score += c * (pos.x + 5 * pos.y);
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
				n_score -= c * (pos.x + 5 * pos.y);
				update_map((t_tetr *)tetrs->content, pos, map, 1);
			}
			pos.y++;
		}
		pos.x++;
	}
}
