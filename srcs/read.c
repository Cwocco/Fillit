/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_read.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ada-cunh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/14 14:44:03 by ada-cunh          #+#    #+#             */
/*   Updated: 2017/01/18 04:43:51 by nboste           ###   ########.fr       */
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

int			ft_check_tetri(char *buf)
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
		ft_lst_push_back(&tetrs, (void *)get_tetr(buffer, letter++), 16);
		if (read(fd, (void *)buffer, 1) == 1)
			path = (char *)1;
		if (path && buffer[0] != '\n')
			ft_error(2);
		ft_bzero(buffer, 20);
	}
	if (path || !tetrs)
		ft_error(2);
	return (tetrs);
}

t_tetr		*get_tetr(char *buffer, char letter)
{
	t_tetr		*tetr;
	t_2ipair	max;
	t_2ipair	min;
	t_2ipair	tmp;

	get_min_max(buffer, &min, &max);
	tetr = (t_tetr *)malloc(sizeof(t_tetr));
	tetr->size.x = max.x - min.x + 1;
	tetr->size.y = max.y - min.y + 1;
	tetr->tetr = (char *)malloc(sizeof(char) * tetr->size.x * tetr->size.y);
	tmp.y = 0;
	while (tmp.y < tetr->size.y)
	{
		tmp.x = 0;
		while (tmp.x < tetr->size.x)
		{
			if (buffer[tmp.x + min.x + 5 * (tmp.y + min.y)] == '#')
				tetr->tetr[tmp.x + tetr->size.x * tmp.y] = letter;
			else
				tetr->tetr[tmp.x + tetr->size.x * tmp.y] = 0;
			tmp.x++;
		}
		tmp.y++;
	}
	return (tetr);
}

void		get_min_max(char *buffer, t_2ipair *min, t_2ipair *max)
{
	t_2ipair	tmp;

	min->x = 0x7fffffff;
	min->y = 0x7fffffff;
	max->x = 0;
	max->y = 0;
	tmp.y = 0;
	while (tmp.y < 4)
	{
		tmp.x = 0;
		while (tmp.x < 4)
		{
			if (buffer[tmp.x + 5 * tmp.y] == '#')
			{
				max->x = tmp.x > max->x ? tmp.x : max->x;
				max->y = tmp.y > max->y ? tmp.y : max->y;
				min->x = tmp.x < min->x ? tmp.x : min->x;
				min->y = tmp.y < min->y ? tmp.y : min->y;
			}
			tmp.x++;
		}
		tmp.y++;
	}
}
