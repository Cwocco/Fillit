/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ada-cunh <ada-cunh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 17:29:34 by ada-cunh          #+#    #+#             */
/*   Updated: 2015/05/14 14:28:16 by ada-cunh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	int i;
	int j;

	if (ft_strlen(s1) == 0 && ft_strlen(s2) == 0)
		return ((char *)s1);
	i = 0;
	while (s1[i] != '\0')
	{
		j = 0;
		while (s1[i + j] != '\0' && s2[j] != '\0' && s1[i + j] == s2[j])
		{
			j++;
		}
		if (s2[j] == '\0')
			return ((char*)s1 + i);
		i++;
		if (s1[i] == '\0')
			return (NULL);
	}
	return (NULL);
}
