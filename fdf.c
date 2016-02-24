/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalama <asalama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/10 18:06:13 by asalama           #+#    #+#             */
/*   Updated: 2016/02/24 13:17:46 by asalama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			put_pixel(t_env *env, int x, int y, t_tab *tab)
{
	int			i;
	int			j;

	i = tab->i;
	j = tab->j;
	x *= 4;
	if (y >= 0 && y < HEIGHT && x >= 0 && x < (env->size_line))
	{
		if (tab->tab_int[j][i] == 0)
			env->addr[y * env->size_line + x] = 255;
		else if (tab->tab_int[j][i] > 0)
			env->addr[y * env->size_line + ++x] = 255;
		else
			env->addr[y * env->size_line + ++x] = 200;
	}
}

void			draw_line(t_env *env, t_coord *coord, t_tab *tab)
{
	t_double	db;
	int			k;

	k = 0;
	if (abs(coord->x2 - coord->x1) >= abs(coord->y2 - coord->y1))
		db.l = abs(coord->x2 - coord->x1);
	else
		db.l = abs(coord->y2 - coord->y1);
	if (db.l)
	{
		db.dx = (coord->x2 - coord->x1) / db.l;
		db.dy = (coord->y2 - coord->y1) / db.l;
	}
	db.x = coord->x1;
	db.y = coord->y1;
	while (k < db.l)
	{
		put_pixel(env, db.x, db.y, tab);
		db.x += db.dx;
		db.y += db.dy;
		k++;
	}
}

void			tabtab(t_tab *tab, t_env *env, t_angle *angle)
{
	t_coord		coord;

	tab->j = 0;
	while (tab->j < tab->size_ver)
	{
		tab->i = 0;
		while (tab->i < tab->size_hor)
		{
			env->pro == 1 ? ortho_hor(&coord, tab, env, angle) :
				iso_hor(&coord, tab, env);
			if (tab->i + 1 < tab->size_hor)
				draw_line(env, &coord, tab);
			if (tab->j + 1 < tab->size_ver)
			{
				env->pro == 1 ? ortho_ver(&coord, tab, env, angle) :
					iso_ver(&coord, tab, env);
				draw_line(env, &coord, tab);
			}
			tab->i++;
		}
		tab->j++;
	}
}
