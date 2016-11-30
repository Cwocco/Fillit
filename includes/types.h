/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ada-cunh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 22:38:56 by ada-cunh          #+#    #+#             */
/*   Updated: 2016/11/30 02:08:53 by ada-cunh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H

typedef struct	s_coord
{
	int x;
	int y;
}				t_coord;

typedef struct		so_list
{
	struct so_list	*next;
	void			*data;
	t_coord			coord;
	t_coord			anchor;
}					list;

#endif
