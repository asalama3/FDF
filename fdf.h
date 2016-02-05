/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalama <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/28 13:09:21 by asalama           #+#    #+#             */
/*   Updated: 2016/02/05 14:22:50 by asalama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H


#include "libft/libft.h"
#include <fcntl.h>
#include <mlx.h>
#include <stdlib.h>
#include <math.h>

typedef struct		s_env
{
	void			*mlx;
	void			*win;
	char			*addr;
	void			*img;
	int				*size_line;
	int				*endian;
	int				*bits_per_pixel;
	int				x1;
	int				y1;
	int				x2;
	int				y2;
}					t_env;


/*typedef struct		s_tab
{
	int				fd;
	char			**line;
	char			**tab;
}					t_tab;
*/

/*
** READ
*/

int					read_file(char **argv);

#endif

