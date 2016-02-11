/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalama <asalama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/10 18:06:13 by asalama           #+#    #+#             */
/*   Updated: 2016/02/11 17:39:07 by asalama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		draw_line(t_env *env, t_coord *coord)
{
	double 		a;
	double 		b;
	int			x;
	int			y;
	int			i;

	a = 0;
			printf("COORD \n");
			printf("x1: %i\n", coord->x1);
			printf("x2: %i\n", coord->x2);
			printf("y1: %i\n", coord->y1);
			printf("y2: %i\n", coord->y2);
	if (coord->x2 != coord->x1)
		a = (double)((coord->y2 - coord->y1) / (coord->x2 - coord->x1));
	b = coord->y1 - a * coord->x1;
	printf("y = %f * x  + %f\n", a, b);
	x = coord->tmp1;
	i = 0;
	while (i < 20)
	{
		y = a * i + b;
		put_pixel(env, x, y);
		x++;
		i++;
	}
}

void		tabtab(t_tab *tab, t_env *env)
{
	int			i;
	int			j;
	int			x;
	int			y;
	t_coord		coord;

	y = 0;
	j = 0;
	while (j < tab->size_ver)
	{
		x = 0;
		i = 0;
		while (i < tab->size_hor)
		{
			coord.tmp1 = x;
			coord.tmp2 = y;
			coord.x1 = i;
			coord.y1 = j - tab->tab_int[j][i];
			if (i + 1 < tab->size_hor)
			{
				coord.x2 = i + 1;
				coord.y2 = j - tab->tab_int[j][i + 1];
				draw_line(env, &coord);
			}
	//		put_pixel(env, x, y);
			x += 20;
			i++;
		}
		y += 20;
		j++;
	}
}




void		put_pixel(t_env *env, int x, int y)
{
	x *= 4;
	env->addr[y * env->size_line + x] = 255; // PARAM COLOR
}
