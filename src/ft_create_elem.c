/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_elem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboste <nboste@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/13 10:01:18 by nboste            #+#    #+#             */
/*   Updated: 2016/11/28 22:06:04 by nboste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_list.h"

list	*ft_create_elem(void *data)
{
	list *elem;

	elem = malloc(sizeof(list));
	elem->next = NULL;
	elem->data = data;
	return (elem);
}
