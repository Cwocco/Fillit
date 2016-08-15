/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ada-cunh <ada-cunh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/14 13:39:52 by ada-cunh          #+#    #+#             */
/*   Updated: 2016/02/19 15:07:32 by ada-cunh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(const char *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*str_temp;

	i = 0;
	if (s == NULL)
		return (NULL);
	if ((str_temp = (char *)malloc(sizeof(*str_temp) * (len + 1))))
	{
		while (i < len)
		{
			str_temp[i] = s[i + start];
			i++;
		}
		str_temp[i] = '\0';
		return (str_temp);
	}
	return (NULL);
}
