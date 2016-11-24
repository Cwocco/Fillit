/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tetri_mem.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ada-cunh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/30 20:14:35 by ada-cunh          #+#    #+#             */
/*   Updated: 2016/11/14 22:13:44 by ada-cunh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"

t_coord			*ft_new_point(int width, int height)
{
	t_coord 	*point;

	point = (char *)malloc(sizeof(t_coord));
	point->x = width;
	point->y = height;
	return (point);	
}

void			ft_free_tetri(t_tetris *tetri)
{
	int i;

	i = 0;
	while
		
}
