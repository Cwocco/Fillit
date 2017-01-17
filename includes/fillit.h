/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ada-cunh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/14 14:40:13 by ada-cunh          #+#    #+#             */
/*   Updated: 2017/01/17 23:12:43 by nboste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft.h"

# define	BUFF_SIZE 20
# define	MAP_W 10

int				ft_check_contact(char *s);

int 			ft_check_tetri(char *buf);

void			ft_error(int e);

t_list			*ft_read(char *path);


char			*get_tetr_map(char *buffer, char letter);

void			update_sol(int *area, char **sol, char **map);

void			update_map(char *tetr, t_2ipair pos, t_2ipair anchor, char **map, t_bool mode);

int				add_tetr_map(char *tetr, t_2ipair pos, t_2ipair anchor, char **map);

int				get_max_width(char **map);

void			print_sol(char **sol);


void			fillit_solve(t_list *l);

void			backtrack(t_list *tetrs, char **map, char **sol, double c);

#endif
