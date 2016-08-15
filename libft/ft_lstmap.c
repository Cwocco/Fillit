/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ada-cunh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/19 11:14:50 by ada-cunh          #+#    #+#             */
/*   Updated: 2016/02/19 11:22:43 by ada-cunh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *t_lst;
	t_list *prev;
	t_list *ret;

	ret = NULL;
	if (lst && f)
	{
		ret = (*f)(lst);
		prev = ret;
		lst = lst->next;
		while (lst)
		{
			t_lst = (*f)(lst);
			prev->next = t_lst;
			prev = t_lst;
			lst = lst->next;
		}
		prev->next = NULL;
	}
	return (ret);
}
