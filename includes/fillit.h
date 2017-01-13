/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ada-cunh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/14 14:40:13 by ada-cunh          #+#    #+#             */
/*   Updated: 2017/01/13 02:08:58 by nboste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

#include "ft_list.h"
#include "types.h"

# define	BUFF_SIZE 20
# define	MAP_W 10

typedef struct	s_2ipair
{
	int	x;
	int	y;
}				t_2ipair;

int				superpose_check(list *tetrs, char **map);

int				ft_check_contact(char *s);

int 			ft_check_tetri(char *buf);

void			ft_error(int e);

list			*ft_read(char *path);

char			*get_tetr_map(char *buffer, char letter);

void			fillit_solve(list *l);

void			update_sol(int *area, char **sol, char **map);

void			update_map(char *tetr, t_2ipair pos, t_2ipair anchor, char **map);

int				add_tetr_map(char *tetr, t_2ipair pos, t_2ipair anchor, char **map);

void			rm_tetr_map(char *tetr, t_2ipair pos, t_2ipair anchor, char **map);

void			backtrack(list *tetrs, char **map, char **sol);

int				get_area(char **map);

double			get_top_ratio(char **map);

int				get_max_width(char **map);

#endif
