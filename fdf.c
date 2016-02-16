/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalama <asalama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/10 18:06:13 by asalama           #+#    #+#             */
/*   Updated: 2016/02/16 20:36:24 by asalama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		put_pixel(t_env *env, int x, int y)
{
	x *= 4;
	env->addr[y * env->size_line + ++x] = 255;
}

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

void		draw_line(t_env *env, t_coord *coord, t_tab *tab)
{
	double 		a;
	double 		b;
	int			x;
	int			y;

	a = 0;
			printf("x1: %i\n", coord->x1);
			printf("x2: %i\n", coord->x2);
			printf("y1: %i\n", coord->y1);
			printf("y2: %i\n", coord->y2);
	if (coord->x2 != coord->x1)
	{
		a = (double)(coord->y1 - coord->y2) / (double)(coord->x1 - coord->x2);
	}
		b = coord->y1 - a * coord->x1;
	printf("y = %f * x  + %f\n", a, b);
	x = coord->x1;
	while (x < coord->x2)
	{
		y = a * x + b;
		put_pixel(env, x, y);
		x++;
	}
}
/*
void		calcul(t_coord *coord, t_tab *tab, int i, int j, int x, int y, t_env *env)
{
	coord->x1 = (x * RX) + (y * RY) + (tab->tab_int[j][i] * RZ);
	coord->y1 = (x * IX) + (y * IY) + (tab->tab_int[j][i] * IZ);
	coord->x2 = ((x + env->space) * RX) + ((y + env->space) * RY) + (tab->tab_int[j][i + 1] * RZ);
	coord->y2 = ((x + env->space) * IX) + ((y + env->space) * IY) + (tab->tab_int[j][i + 1] * IZ);
}

void		calcul2(t_coord *coord, t_tab *tab, int i, int j, int x, int y, t_env *env)
{
	coord->x2 = ((x + env->space) * RX) + ((y + env->space) * RY) + (tab->tab_int[j + 1][i] * RZ);
	coord->y2 = ((x + env->space) * IX) + ((y + env->space) * IY) + (tab->tab_int[j + 1][i] * IZ);
}
*/

void		calcul(t_coord *coord, t_tab *tab, t_env *env, int i, int j, int x, int y)
{
	float	a = M_PI * 20 / 180;
	float	b = M_PI * 220 / 180;

	coord->x1 = 100 + env->space * (cos(a) * i + sin(a) * j);
	coord->y1 = 300 + env->space * (sin(b) * (sin(a) * i - cos(a) * j) + cos(b) * tab->tab_int[j][i]);
	coord->x2 = 100 + env->space * (cos(a) * (i + 1) + sin(a) * j);
	coord->y2 = 300 + env->space * (sin(b) * (sin(a) * (i + 1) - cos(a) * j) + cos(b) * tab->tab_int[j][i + 1]);
}

void		calcul2(t_coord *coord, t_tab *tab, t_env *env, int i, int j, int x, int y)
{
	float	a = M_PI * 20 / 180;
	float	b = M_PI * 220 / 180;

	coord->x1 = 100 + env->space * (cos(a) * i + sin(a) * j);
	coord->y1 = 300 + env->space * (sin(b) * (sin(a) * i - cos(a) * j) + cos(b) * tab->tab_int[j][i]);
	coord->x2 = 100 + env->space * (cos(a) * (i) + sin(a) * (j + 1));
	coord->y2 = 300 + env->space * (sin(b) * (sin(a) * (i) - cos(a) * (j + 1)) + cos(b) * tab->tab_int[j + 1][i]);
}


void		tabtab(t_tab *tab, t_env *env)
{
	int			i;
	int			j;
	int			x;
	int			y;
	t_coord		coord;

	y = 100;
	j = 0;
//	printf("PTR = %p && size_ver = %d\n", tab, tab->size_ver);
	while (j < tab->size_ver)
	{
		x = 50;
		i = 0;
		while (i < tab->size_hor)
		{
			calcul(&coord, tab, env, i, j, x, y);
//			coord.x1 = x;
//			coord.y1 = y - (tab->tab_int[j][i] * env->z);
//				printf("Z:%i\n", env->z);
			if (i + 1 < tab->size_hor)
			{
//				coord.x2 = x + env->space;
//				coord.y2 = y - (tab->tab_int[j][i + 1] * env->z);
				draw_line(env, &coord, tab);
			}
			if (j + 1 < tab->size_ver)
			{	
				calcul2(&coord, tab, env, i, j, x, y);
//				draw_ver(env, x, y);
				draw_line(env, &coord, tab);
			}
			x += env->space;
			i++;
		}
		y += env->space;
		j++;
	}
}
