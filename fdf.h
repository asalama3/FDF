/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalama <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/28 13:09:21 by asalama           #+#    #+#             */
/*   Updated: 2016/02/09 20:10:19 by asalama          ###   ########.fr       */
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
	int				size_line;
	int				endian;
	int				bits_per_pixel;
	int				x;
	int				y;
}					t_env;


typedef struct		s_tab
{
	int				**tab_int;
	int				size_hor;
	int				size_ver;

}					t_tab;


/*
** READ
*/

int					read_file(char *argv);

#endif

