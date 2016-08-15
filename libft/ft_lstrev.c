/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ada-cunh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 10:52:50 by ada-cunh          #+#    #+#             */
/*   Updated: 2016/04/15 16:44:11 by ada-cunh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstrev(t_list *lst)
{
	t_list *new;
	t_list *next;

	new = NULL;
	while (lst != NULL)
	{
		next = lst->next;
		lst->next = new;
		new = lst;
		lst = next;
	}
	return (new);
}
