/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ada-cunh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/14 14:40:13 by ada-cunh          #+#    #+#             */
/*   Updated: 2016/11/24 23:27:25 by ada-cunh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

//# include	"libft.h"
# include	<stdlib.h>
# include	<unistd.h>
# include	<fcntl.h>
# define	BUFF_SIZE 20 	

t_coord			*ft_new_point(int width, int height);
int				ft_check_contact(char *s);
int 			ft_check_tetri(char *s, int count);
t_list			ft_read(int fd);

#endif
