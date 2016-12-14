/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ada-cunh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/14 14:40:13 by ada-cunh          #+#    #+#             */
/*   Updated: 2016/12/14 05:23:04 by ada-cunh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

#include "ft_list.h"
#include "types.h"

# define	BUFF_SIZE 20
# define	MAP_W 104


int superpose_check(list *tetrs, char **map,);

int				ft_check_contact(char *s);

int 			ft_check_tetri(char *buf);

void			ft_error(int e);

list			*ft_read(char *path);

char			*get_tetr_map(char *buffer, char letter);

void			fillit_solve(list *l);

void			reset_map(char **map);

#endif
