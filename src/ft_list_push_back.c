/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboste <nboste@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/13 10:07:45 by nboste            #+#    #+#             */
/*   Updated: 2016/11/28 22:06:34 by nboste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_list.h"

void	ft_list_push_back(list **begin_list, void *data)
{
	list *elem;
	list *tmp;

	elem = ft_create_elem(data);
	tmp = *begin_list;
	if (!(*begin_list))
	{
		*begin_list = elem;
	}
	else
	{
		while (tmp->next != NULL)
		{
			tmp = tmp->next;
		}
		(tmp)->next = elem;
	}
}
