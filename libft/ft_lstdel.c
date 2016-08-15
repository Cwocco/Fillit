/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ada-cunh <ada-cunh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/23 09:55:43 by ada-cunh          #+#    #+#             */
/*   Updated: 2015/05/02 09:48:38 by ada-cunh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstdel(t_list **alst, void (*del)(void*, size_t))
{
	t_list	*tmp;
	t_list	*nxt;

	if (alst != NULL)
	{
		nxt = *alst;
		while (nxt != NULL)
		{
			if (del != NULL)
				(*del)(nxt->content, (*nxt).content_size);
			tmp = nxt->next;
			free(nxt);
			nxt = tmp;
		}
		*alst = NULL;
	}
}
