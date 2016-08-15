/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ada-cunh <ada-cunh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 10:47:30 by ada-cunh          #+#    #+#             */
/*   Updated: 2015/05/14 14:13:25 by ada-cunh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *s1, const char *s2)
{
	int i;
	int len_dest;

	i = 0;
	len_dest = ft_strlen(s1);
	while (s2[i] != '\0')
	{
		s1[len_dest + i] = (char)s2[i];
		i++;
	}
	s1[len_dest + i] = '\0';
	return (s1);
}
