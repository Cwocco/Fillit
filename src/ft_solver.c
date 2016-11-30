/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solver.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboste <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 20:45:34 by nboste            #+#    #+#             */
/*   Updated: 2016/11/30 05:12:51 by ada-cunh         ###   ########.fr       */
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

/* C'etait vraiment pas clair dans ma tete avc les coordonnees de la piece, jvoyais pas
   comment les placer
   jpense c'est un truc genre coord->x; coord->y, je m emmele dans les struc jpense faut jrevois ca, j'ai essaye de faire un truc ecrit du coup, sorry 
efface pas mon code degueu j'ai envie de comparer ce qu'on fera a ce que j'ai ecrit la*/

char * backtrack(list *lst, char **map)
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
