/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ada-cunh <ada-cunh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/12 12:56:04 by ada-cunh          #+#    #+#             */
/*   Updated: 2016/04/14 11:11:15 by ada-cunh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char			*ret;
	unsigned long	i;

	if (s && f)
	{
		i = 0;
		if ((ret = (char*)malloc(ft_strlen((char*)s) + 1)) == NULL)
			return (NULL);
		while (s[i])
		{
			ret[i] = (*f)(s[i]);
			++i;
		}
		ret[i] = 0;
		return (ret);
	}
	return (NULL);
}
