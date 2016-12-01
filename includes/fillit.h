/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ada-cunh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/14 14:40:13 by ada-cunh          #+#    #+#             */
/*   Updated: 2016/12/01 05:04:56 by ada-cunh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

#include "ft_list.h"
#include "types.h"

# define	BUFF_SIZE 20
# define	MAP_W 104


int superpose_check(list *tetrs, char **map, int map_size, int x, int y);

t_coord			*ft_new_point(int width, int height);

int				ft_check_contact(char *s);

int 			ft_check_tetri(char *buf);

void			ft_error(int e);

list			*ft_read(char *path);

int				ft_nb_tetri(char *s);

char			*get_tetr_map(char *buffer, char letter);

void			fillit_solve(list *l);

void			reset_map(char **map);

#endif
