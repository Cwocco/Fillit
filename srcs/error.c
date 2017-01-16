/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ada-cunh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 23:23:29 by ada-cunh          #+#    #+#             */
/*   Updated: 2016/11/28 22:19:00 by nboste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"

void ft_error(int e)
{
	if (e == 1)
	{
		ft_putstr("usage: ./fillit source_file\n");
		exit(EXIT_FAILURE);
	}
	else if (e == 2)
	{
		ft_putstr("error");
		exit(EXIT_FAILURE);
	}
}
