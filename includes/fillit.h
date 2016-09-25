/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ada-cunh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/14 14:40:13 by ada-cunh          #+#    #+#             */
/*   Updated: 2016/09/15 14:49:05 by ada-cunh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct  s_coord
{
	int			x;
	int			y;
}				t_coord;

typedef struct 	s_tetris
{
//	int			t_x;
//	int			t_y;
	char 		**pos;
}				t_tetris;

/* ft_check_tetri1 */
int				square(char *s);
int    			bar_hor(char *s);
int    			bar_ver(char *s);
int    			l1(char *s);
int    			l2(char *s);
/* ft_check_tetri2 */ 
int				l3(char *s);
int				l4(char *s);
int				l5(char *s);
int				l6(char *s);
int				l7(char *s);
/* ft_check_tetri3 */
int				l8(char *s);
int				strairs(char *s);
int				stairs2(char *s);
int				stairs3(char *s);
int				stairs4(char *s);
/* ft_check_tetri4 */
int				cross(char *s);
int				cross2(char *s);
int				cross3(char *s);
int				cross4(char *s);
void			ft_check_piece(char *s, t_coord *min, t_coord *max);
t_tetris		*ft_get_tetri(char *s);
t_coord			*ft_new_point(int width, int height);
int				ft_check_contact(char *s);
int 			ft_check_tetri(char *s, int count);
//t_list			ft_read(int fd);

#endif
