/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalama <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/28 13:09:21 by asalama           #+#    #+#             */
/*   Updated: 2016/02/23 19:01:19 by asalama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft/libft.h"
# include <fcntl.h>
# include "mlx.h"
# include <stdlib.h>
# include <math.h>
# include <stdio.h>

# define WIDTH 2000
# define HEIGHT 2000
# define SIZE_X 1000
# define SIZE_Y 1000

# define SPACE 20
# define RELIEF 4
# define ZOOM 5
# define ROTATE_1 0.1
# define ROTATE_2 0.1

# define KEYPRESS 2
# define KEYPRESSMASK 1

typedef struct		s_tab
{
	int				**tab_int;
	int				size_hor;
	int				size_ver;
	int				i;
	int				j;

}					t_tab;

typedef struct		s_angle
{
	float			a;
	float			b;
}					t_angle;

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
	int				pro;
	int				space;
	t_tab			*tab;
	t_angle			*angle;
}					t_env;

typedef struct		s_coord
{
	int				x1;
	int				x2;
	int				y1;
	int				y2;
}					t_coord;

t_tab				*read_file(char *argv);
void				tabtab(t_tab *tab, t_env *env, t_angle *angle);
void				put_pixel(t_env *env, int x, int y, t_tab *tab);
int					print_tab_int(t_tab *tab);
void				move_right(t_env *env);
void				move_left(t_env *env);
void				move_up(t_env *env);
void				move_down(t_env *env);
void				zoom_out(t_env *env, t_tab *tab, t_angle *angle);
void				zoom_in(t_env *env, t_tab *tab, t_angle *angle);
void				relief_z_up(t_env *env, t_tab *tab, t_angle *angle);
void				relief_z_down(t_env *env, t_tab *tab, t_angle *angle);
void				rotate_1(t_env *env, t_tab *tab, t_angle *angle);
void				rotate_2(t_env *env, t_tab *tab, t_angle *angle);
void				image(t_env *env, t_tab *tab, t_angle *angle);
void				ortho_hor(t_coord *coord, t_tab *tab, t_env *env,
		t_angle *angle);
void				ortho_ver(t_coord *coord, t_tab *tab, t_env *env,
		t_angle *angle);
void				iso_hor(t_coord *coord, t_tab *tab, t_env *env);
void				iso_ver(t_coord *coord, t_tab *tab, t_env *env);
void				ortho(t_env *env, t_tab *tab, t_angle *angle);
void				iso(t_env *env, t_tab *tab, t_angle *angle);
void				ft_error(char *s);

#endif
