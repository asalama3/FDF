/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalama <asalama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/10 18:06:13 by asalama           #+#    #+#             */
/*   Updated: 2016/02/15 16:55:15 by asalama          ###   ########.fr       */
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

void		tabtab(t_tab *tab, t_env *env)
{
	int			i;
	int			j;
	int			x;
	int			y;
	t_coord		coord;

	y = 100;
	j = 0;
	printf("PTR = %p && size_ver = %d\n", tab, tab->size_ver);
//	ft_putnbr(tab->size_ver);
	while (j < tab->size_ver)
	{
		x = 100;
		i = 0;
		while (i < tab->size_hor)
		{
			coord.x1 = x;
			//ft_putnbr(env->z);
			coord.y1 = y - (tab->tab_int[j][i] * env->z);
				printf("Z:%i\n", env->z);
	//		if (tab->tab_int[j][i] != 0)
	//			printf("%i------%i\n", y, coord.y1);
			if (i + 1 < tab->size_hor)
			{
				coord.x2 = x + env->space;
				coord.y2 = y - (tab->tab_int[j][i + 1] * env->z);
				draw_line(env, &coord, tab);
			}
			if (j + 1 < tab->size_ver)
				draw_ver(env, x, y);
			x += env->space;
			i++;
		}
		y += env->space;
		j++;
	}
}
