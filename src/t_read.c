/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_read.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ada-cunh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/14 14:44:03 by ada-cunh          #+#    #+#             */
/*   Updated: 2016/08/31 18:14:11 by ada-cunh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"


/* La jdois reussir a lire un tetriminos mais wlh ca mcasse les couilles

*/

void 		ft_check_piece(char *s, t_coord *min, t_coord *max)
{
	int i;
	int 

	i = 0;
	while (i < 20)
		{
			if (s[i] == '.' && s[i + 1] == '#')9
				min->x = i;
			if (s[i] == '#' && s[i + 1] == '.' && s[i])

			i++;

		}
}

/* Recupère un tetriminos ...
....
*/

t_tetris	*ft_get_tetri(char *s)
{
	int 			i;
	t_coord 		*t_y;
	t_coord 		*t_x;
	char			**pos;

	i = 0;
	pos = (char *)malloc(sizeof(char *) * (t_x->y - t_y->y + 1));
	while()
	{

	}
}

/*
	Verifie que les caracteres des tetriminos sont en contact avc un autre block
	Si la fonction return 4 ou 6, le tetriminos est valide
*/

int			ft_check_contact(char *s)
{
	int i;
	int	contact;

	i = 0;
	contact = 0;
	while (i < 20)
	{
		while (s[i] == '#' || s[i] == '\n')
		{
			if (((s[i + 1] < 20) && (s[i + 1] == '#')) || 
					((s[i + 5] < 20) && (s[i + 5] == '#')))
				contact++;
			if (((s[i - 1] >= 0) && (s[i - 1] == '#')) || 
					((s[i - 5] >= 0) && (s[i - 5] == '#')))
				contact++;
		}
		i++;
	}
	return (contact == 4 || contact == 6);
}

/*
	Verifie qu'un tetriminos est bien composé de 21 caracteres, un \n tout les 5 caracteres, les caracteres sont soit des "#" soit des "."
*/
int			ft_check_tetri(char *s, int count)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] != '#' || s[i] != '.')
			return (1);
		if ((((i + 1) % 5) == 0) && s[i] != '\n')
			return (2);
		if (s[i] == '#' && (i % 5) < 4)
			return (3);
		i++
	}
	if (count == 21 && s[20] != '\n')
		return (4);
	if (!(ft_check_contact(s)))
			return (5);
	return (0);
}

t_list 		*ft_read(int fd)
{
	char *buf;
	t_list *list;
	int i;

	buf = (char *)malloc(sizeof(char *) * (21));
	if (!(buf = (char *)malloc(sizeof(char *) * (21))))
		return (NULL);
}
