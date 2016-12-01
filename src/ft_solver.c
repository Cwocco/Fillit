/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solver.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboste <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 20:45:34 by nboste            #+#    #+#             */
/*   Updated: 2016/12/01 05:01:34 by ada-cunh         ###   ########.fr       */
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

/*
char *ft_a_garder(list *lst, char **map)
{
	int i;

	i = 0;
	while (Tant que je suis dans lst et dans ma map)
	{
		if (Si jai bien lu mon tetriminos avec read)
			Placer le tetriminos lu en (1,1) sur la map, ici anchor = 1 (faut surement 
se servir  des struct dans types.h mais cest pas clair dans ma tete
			 if (Jai pu placer mon tetriminos)
              read le prochain tetriminos et le placer de facon a ce que lair de 
              la map soit le plus petit possible
		     if(lair actuelle est plus petite que lair precedente)
            	continuer de read et de placer
			else ()
				 {
					 recursive avc anchor + 1
			des que laire actuelle redeviens plus petite que la precedente continuer de
			 read et de placer (ici jcpa si on re initialise anchor, jpense que ui)
					 chaque fois qu on incremente anchor faut comparer aire actuel a
					 aire precedente et des qu on a la plus petite aire
				 }
		quand ya plus rien a read et si on a la plus petite aire on renvoi la map
	}				
}
*/


list *backtrack(list *tetrs, char **map, int map_size)
{
	int x;
	int y;
	
	x = 0;
	y = 0;

	if (!(tetrs && map))
		ft_error(2);
	while (map && (y < map_size))
	{
		while (map && (x < map_size))
		{
			if (add_tetrs(tetrs, map, anchor, map_size))
			{
				backtrack(tetrs->next, map, map_size);
				del_tetrs(tetris, map, anchor, map_size);
			}
			x++;
		}
		y++;
	}
	// Ici j'voudrais faire remplir la map solve pour pouvor la print
	return (map);
}


// Pour add_map faudra une fonction qui check si quand on add les tetriminos se superposent pas
