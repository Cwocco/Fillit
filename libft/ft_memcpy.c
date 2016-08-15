/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ada-cunh <ada-cunh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 14:41:22 by ada-cunh          #+#    #+#             */
/*   Updated: 2015/05/02 08:47:17 by ada-cunh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	int		i;
	char	*str;
	char	*str_dst;

	i = 0;
	str = (char *)src;
	str_dst = (char *)dst;
	while (i < (int)n)
	{
		str_dst[i] = str[i];
		i++;
	}
	dst = (void *)str_dst;
	return (dst);
}
