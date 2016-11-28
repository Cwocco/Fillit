/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ada-cunh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 05:02:32 by ada-cunh          #+#    #+#             */
/*   Updated: 2016/11/28 05:03:30 by ada-cunh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"

int main(int argc, char **argv)
{
	int fd;

	if (argc != 2)
		error(1);
	if (!(ft_check_tetri(argv[1]) && ft_read(fd)))
		error(2);
	return (0);
}
