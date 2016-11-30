/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboste <nboste@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/13 10:07:45 by nboste            #+#    #+#             */
/*   Updated: 2016/11/30 02:15:45 by ada-cunh         ###   ########.fr       */
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
		*begin_list = elem;
	else
	{
		//Ici pas compris pk tu need tmp, tu alloues
		while (tmp->next != NULL)
			tmp = tmp->next;
		(tmp)->next = elem;
	}
}
