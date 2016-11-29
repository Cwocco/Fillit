/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboste <nboste@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/13 09:55:14 by nboste            #+#    #+#             */
/*   Updated: 2016/11/29 21:31:14 by nboste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIST_H
# define FT_LIST_H

typedef struct		so_list
{
	struct so_list	*next;
	void			*data;
	t_coord			coord;
	t_coord			anchor;
}					list;

list				*ft_create_elem(void *data);

void				ft_list_push_back(list **begin_list, void *data);

#endif
