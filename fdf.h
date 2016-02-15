/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalama <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/28 13:09:21 by asalama           #+#    #+#             */
/*   Updated: 2016/02/15 13:20:49 by asalama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

#include "libft/libft.h"
#include <fcntl.h>
#include "mlx.h"
#include <stdlib.h>
#include <math.h>
#include <stdio.h>

#define SPACE 20

typedef struct		s_tab
{
	int				**tab_int;
	int				size_hor;
	int				size_ver;

}					t_tab;

typedef struct		s_env
{
	void			*mlx;
	void			*win;
	char			*addr;
	void			*img;
	int				size_line;
	int				endian;
	int				bpp;
	int				x;
	int				y;
    int             z;
	int				space;
	t_tab			*tab;
}					t_env;

typedef struct		s_coord
{
	int				x1;
	int				x2;
	int				y1;
	int				y2;
}					t_coord;


/*
** READ
*/

t_tab				*read_file(char *argv);
void                tabtab(t_tab *tab, t_env *env);
void				put_pixel(t_env *env, int x, int y);
int					print_tab_int(t_tab *tab);
void				move_right(t_env *env);
void				move_left(t_env *env);
void				move_up(t_env *env);
void				move_down(t_env *env);
void				zoom_out(t_env *env);
void				zoom_in(t_env *env, t_tab *tab);
void				relief_z(t_env *env, t_tab *tab);
#endif


