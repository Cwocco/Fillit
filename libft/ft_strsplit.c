/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ada-cunh <ada-cunh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/27 13:36:11 by ada-cunh          #+#    #+#             */
/*   Updated: 2016/04/14 11:47:30 by ada-cunh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_add_word(char *s, char c, size_t j)
{
	size_t	len;
	char	*str;

	len = 0;
	str = NULL;
	while (s[j + len] && s[j + len] != c)
		++len;
	if ((str = (char *)malloc(sizeof(char *) * (len + 1))) == NULL)
		return (NULL);
	len = 0;
	while (s[j + len] && s[j + len] != c)
	{
		str[len] = s[j + len];
		++len;
	}
	str[len] = '\0';
	return (str);
}

static size_t	ft_spliter(char **str, char *s, char c, size_t words)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (i < words)
	{
		while (s[j] && s[j] == c)
			++j;
		if ((str[i] = ft_add_word(s, c, j)) == NULL)
			return (0);
		while (s[j] && s[j] != c)
			++j;
		++i;
	}
	str[i] = 0;
	return (1);
}

static size_t	ft_count_words(char *s, char c)
{
	size_t	len;
	size_t	i;

	len = 0;
	i = 0;
	while (s[i] && s[i] == c)
		++i;
	while (s[i])
	{
		while (s[i] && s[i] != c)
			++i;
		while (s[i] && s[i] == c)
			++i;
		++len;
	}
	return (len);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**str;
	size_t	len;

	str = NULL;
	if (s)
	{
		len = ft_count_words((char *)s, c);
		if ((str = (char **)malloc(sizeof(char *) * (len + 1))))
		{
			if (ft_spliter(str, (char *)s, c, len))
				return (str);
			else
			{
				free(str);
				return (NULL);
			}
		}
		else
			return (NULL);
	}
	return (str);
}
