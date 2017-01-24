/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ada-cunh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/14 14:40:13 by ada-cunh          #+#    #+#             */
/*   Updated: 2017/01/23 23:03:46 by nboste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft.h"

# define BUFF_SIZE 20

typedef struct	s_tetr
{
	t_2ipair	size;
	char		*tetr;
}				t_tetr;

typedef struct	s_static_backtrack
{
	int			area;
	int			n_area;
	double		score;
	double		n_score;
}				t_static_backtrack;

typedef struct	s_map
{
	char	**map;
	int		size;
}				t_map;

int				ft_check_contact(char *s);

int				ft_check_tetri(char *buf);

void			ft_error(int e);

t_list			*ft_read(char *path);

t_tetr			*get_tetr(char *buffer, char letter);

void			update_sol(t_static_backtrack *v, char **sol, t_map *map);

void			update_map(t_tetr *tetr, t_2ipair pos, t_map *map, t_bool mode);

int				add_tetr_map(t_tetr *tetr, t_2ipair pos, t_map *map);

int				get_max_width(t_map *map);

void			print_sol(char **sol, int size);

void			fillit_solve(t_list *l);

void			backtrack(t_list *tetrs, t_map *map, char **sol, double c);

void			get_min_max(char *buffer, t_2ipair *min, t_2ipair *max);

int				get_list_size(t_list *l);

#endif
