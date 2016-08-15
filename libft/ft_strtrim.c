/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ada-cunh <ada-cunh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/26 11:40:16 by ada-cunh          #+#    #+#             */
/*   Updated: 2016/02/19 13:19:03 by ada-cunh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_strtrim_len(const char *s)
{
	int		i;
	int		len;

	i = 0;
	len = 1;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	if (s[i] == 0)
		return (0);
	while (s[i] != '\0')
	{
		i++;
		len++;
	}
	i--;
	len--;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
	{
		i--;
		len--;
	}
	return (len);
}

char		*ft_strtrim(char const *s)
{
	int		i;
	int		len;
	int		j;
	char	*tmp;

	if (s == NULL)
		return (NULL);
	len = ft_strtrim_len(s);
	if (!(tmp = (char *)ft_memalloc(sizeof(*tmp) * len + 1)))
		return (NULL);
	if (len == 0)
		return (tmp);
	if (tmp == NULL)
		return (NULL);
	i = 0;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	j = 0;
	while (j < len)
	{
		tmp[j] = s[i + j];
		j++;
	}
	tmp[j] = '\0';
	return (tmp);
}
