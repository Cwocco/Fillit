/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_read.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ada-cunh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/14 14:44:03 by ada-cunh          #+#    #+#             */
/*   Updated: 2017/01/16 03:58:26 by nboste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int			ft_check_contact(char *s)
{
	int i;
	int	contact;

	i = 0;
	contact = 0;
	while (i < 20)
	{
		if (s[i] == '#')
		{
			if ((i + 1) < 20 && (s[i + 1] == '#'))
				contact++;
			if ((i + 5) < 20 && (s[i + 5] == '#'))
				contact++;
			if ((i - 1) >= 0 && (s[i - 1] == '#'))
				contact++;
			if ((i - 5) >= 0 && (s[i - 5] == '#'))
				contact++;
		}
		i++;
	}
	return (contact == 6 || contact == 8);
}

int ft_check_tetri(char *buf)
{
	int i;

	i = 0;
	while (i < 20)
	{
		if ((i % 5) == 4 && buf[i] != '\n')
			return (1);
		if ((i % 5) < 4 && buf[i] != '.' && buf[i] != '#')
			return (1);
		i++;
	}
	if (!(ft_check_contact(buf)))
		return (1);
	return (0);
}

t_list		*ft_read(char *path)
{
	int		fd;
	char	buffer[20];
	t_list	*tetrs;
	char	letter;

	if ((fd = open(path, O_RDONLY)) == -1)
		ft_error(2);
	tetrs = NULL;
	letter = 'A';
	while (read(fd, (void *)buffer, 20) > 0)
	{
		path = 0;
		if (letter > 'Z' || ft_check_tetri(buffer))
			ft_error(2);
		ft_lst_push_back(&tetrs, (void *)get_tetr_map(buffer, letter++), 16);
		if (read(fd, (void *)buffer, 1) == 1)
		{
			if (buffer[0] != '\n')
				ft_error(2);
			path = (char *)1;
		}
	}
	if (path || !tetrs)
		ft_error(2);
	return (tetrs);
}

char		*get_tetr_map(char *buffer, char letter)
{
	char	*map;
	int		i;
	int		j;

	if(!(map = (char *)malloc(sizeof(char) * (16))))
		ft_error(2);
	i = 0;
	j = 0;
	while (i < 20)
	{
		if (j != 4 && j != 9 && j != 14)
		{
			if (buffer[j] == '#')
				map[i] = letter;
			else
				map[i] = 0;
			i++;
		}
		j++;
	}
	return (map);
}
