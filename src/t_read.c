/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_read.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ada-cunh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/14 14:44:03 by ada-cunh          #+#    #+#             */
/*   Updated: 2016/08/14 18:02:10 by ada-cunh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"

int		ft_check_tetri(char *s)
{
	int i;

	i = 0;
	while (i < 20)
	{
		while (s[i] == '#' && s[i + 1] == '#')
		{
			
		}
	}
}

t_list ft_read(int fd)
{
	char *buf;
	t_list *list;
	int i;

	buf = (char *)malloc(sizeof(char *) * (21));
	if (!(buf = (char *)malloc(sizeof(char *) * (21))))
		return (NULL);
}

