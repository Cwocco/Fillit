/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solver.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboste <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 20:45:34 by nboste            #+#    #+#             */
/*   Updated: 2016/11/29 21:33:46 by nboste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"
#include "ft_list.h"

void	fillit_solve(list *l)
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
	sol = backtrack(l, map);
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
