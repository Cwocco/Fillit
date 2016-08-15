/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ada-cunh <ada-cunh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 15:08:03 by ada-cunh          #+#    #+#             */
/*   Updated: 2015/05/02 08:42:48 by ada-cunh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t		i;
	char		*str_src;
	char		*str_dst;

	if (n == 0)
		return (0);
	i = 0;
	str_src = (char *)src;
	str_dst = (char *)dst;
	while (i < n)
	{
		str_dst[i] = str_src[i];
		if (str_src[i] == (char)c)
		{
			dst = (void *)str_dst;
			return (dst + i + 1);
		}
		i++;
	}
	return (NULL);
}
