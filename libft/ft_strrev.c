/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ada-cunh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/15 17:17:32 by ada-cunh          #+#    #+#             */
/*   Updated: 2016/04/15 17:26:25 by ada-cunh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(const char *s)
{
	size_t	i;
	size_t	len;
	char	*str;

	i = 0;
	len = ft_strlen(s);
	if ((str = (char *)malloc(len + 1)))
	{
		while (i < len)
		{
			str[i] = s[len - i - 1];
			i++;
		}
		str[i] = '\0';
		return (str);
	}
	return (NULL);
}
