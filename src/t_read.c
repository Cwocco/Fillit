/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_read.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ada-cunh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/14 14:44:03 by ada-cunh          #+#    #+#             */
/*   Updated: 2016/08/16 01:31:18 by ada-cunh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"

/*
Verifie que les caracteres des tetriminos sont en contact avc un autre block
Si la fonction return 4 ou 6, le tetriminos est valide
*/

int		ft_check_contact(char *s)
{
	int i;
	int	contact;

	i = 0;
	tetri = 0;
	while (i < 20)
	{
		while (s[i] == '#')
		{
			if (((s[i + 1] < 20) && (s[i + 1] == '#')) || ((s[i + 5] < 20) && (s[i + 5] == '#')))
				contact++;
			if (((s[i - 1] >= 0) && (s[i - 1] == '#')) || ((s[i - 5] >= 0) && (s[i - 5] == '#')))
				contact++;
			i++;
		}
		return (contact == 4 || contact == 6);
	}
}

int		ft_check_tetri(char *s, int )
{
	int	i;

	i = 0;

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
