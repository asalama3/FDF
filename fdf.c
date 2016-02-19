/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalama <asalama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/10 18:06:13 by asalama           #+#    #+#             */
/*   Updated: 2016/02/19 14:43:58 by asalama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		put_pixel(t_env *env, int x, int y, t_tab *tab, int i, int j)
{
    x *= 4;
    //	    env->addr[y * env->size_line + x] = 255;
	    if (tab->tab_int[j][i] == 0)
	        env->addr[y * env->size_line + x] = 255;
    //        mlx_pixel_put(env->mlx, env->win, x, y, 0xff0000);
	    else if (tab->tab_int[j][i] > 0)
	        env->addr[y * env->size_line + x++] = 255;
      //      mlx_pixel_put(env->mlx, env->win, x, y, 0x8B0000);
        else
     //       mlx_pixel_put(env->mlx, env->win, x, y, 0x8B0000);
           env->addr[y * env->size_line + x] = 255;
}
/*
void		draw_ver(t_env *env, int x, int y)
{
	int		i;

	i = 0;
	while (i < env->space)
	{
		put_pixel(env, x, y);
		y++;
		i++;
	}
}
*/

void		draw_line(t_env *env, t_coord *coord, t_tab *tab, int i, int j)
{
	double 		a;
	double		x;
	double		y;
    double      dx;
    double      dy;
    int         k;

    i = 0;
    if(abs(coord->x2 - coord->x1) >= abs(coord->y2 - coord->y1))
        a = abs(coord->x2 - coord->x1);
    else
        a = abs(coord->y2 - coord->y1);
    if (a)
    {
        dx = (coord->x2 - coord->x1) / a;
        dy = (coord->y2 - coord->y1) / a;
	}
    x = coord->x1;
    y = coord->y1;

    while (k < a)
    {
        put_pixel(env, x, y, tab, i, j);
        x += dx;
        y += dy;
        k++;
	}
}

void		calcul(t_coord *coord, t_tab *tab, t_env *env, int i, int j, int x, int y, t_angle *angle)
{

	coord->x1 = 100 + env->space * (cos(angle->b) * i + sin(angle->b) * j);
	coord->y1 = 300 + env->space * (sin(angle->a) * (sin(angle->b) * i - cos(angle->b) * j) + cos(angle->a) * tab->tab_int[j][i]);
	coord->x2 = 100 + env->space * (cos(angle->b) * (i + 1) + sin(angle->b) * j);
	coord->y2 = 300 + env->space * (sin(angle->a) * (sin(angle->b) * (i + 1) - cos(angle->b) * j) + cos(angle->a) * tab->tab_int[j][i + 1]);
}

void		calcul2(t_coord *coord, t_tab *tab, t_env *env, int i, int j, int x, int y, t_angle *angle)
{

	coord->x1 = 100 + env->space * (cos(angle->b) * i + sin(angle->b) * j);
	coord->y1 = 300 + env->space * (sin(angle->a) * (sin(angle->b) * i - cos(angle->b) * j) + cos(angle->a) * tab->tab_int[j][i]);
	coord->x2 = 100 + env->space * (cos(angle->b) * (i) + sin(angle->b) * (j + 1));
	coord->y2 = 300 + env->space * (sin(angle->a) * (sin(angle->b) * (i) - cos(angle->b) * (j + 1)) + cos(angle->a) * tab->tab_int[j + 1][i]);
}


void		tabtab(t_tab *tab, t_env *env, t_angle *angle)
{
	int			i;
	int			j;
	int			x;
	int			y;
	t_coord		coord;

	y = 100;
	j = 0;
	printf("PTR = %p && size_ver = %d\n", tab, tab->size_ver);
	while (j < tab->size_ver)
	{
		x = 50;
		i = 0;
		while (i < tab->size_hor)
		{
			calcul(&coord, tab, env, i, j, x, y, angle);
			if (i + 1 < tab->size_hor)
			{
				draw_line(env, &coord, tab, i, j);
			}
			if (j + 1 < tab->size_ver)
			{	
				calcul2(&coord, tab, env, i, j, x, y, angle);
//				draw_ver(env, x, y);
				draw_line(env, &coord, tab, i, j);
			}
			x += env->space;
			i++;
		}
		y += env->space;
		j++;
	}
}
