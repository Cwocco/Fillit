/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ada-cunh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 05:02:32 by ada-cunh          #+#    #+#             */
/*   Updated: 2016/11/28 22:21:48 by nboste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"

int main(int argc, char **argv)
{
	if (argc != 2)
		ft_error(1);
	ft_read(argv[1]);
	return (0);
}
