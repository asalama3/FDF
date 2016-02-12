/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalama <asalama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/10 18:06:13 by asalama           #+#    #+#             */
/*   Updated: 2016/02/12 13:53:04 by asalama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		put_pixel(t_env *env, int x, int y)
{
	x *= 4;
	env->addr[y * env->size_line + ++x] = 255;
}

void		draw_ver(t_tab *tab, t_env *env, t_coord *coord)
{
	int		i;

	i = 0;
	while (i < TARTE)
	{
		put_pixel(env, coord->x1, coord->y1);
		coord->y1++;
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
	//		printf("COORD \n");
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
	draw_ver(tab, env, coord);
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
	while (j < tab->size_ver)
	{
		x = 100;
		i = 0;
		while (i < tab->size_hor)
		{
			coord.x1 = x;
			coord.y1 = y - tab->tab_int[j][i];
			if (tab->tab_int[j][i] != 0)
				printf("%i------%i\n", y, coord.y1);
			if (i + 1 < tab->size_hor)
			{
				coord.x2 = x + 20;
				coord.y2 = y - tab->tab_int[j][i + 1];
				draw_line(env, &coord, tab);
			}
			x += TARTE;
			i++;
		}
		y += TARTE;
		j++;
	}
}
