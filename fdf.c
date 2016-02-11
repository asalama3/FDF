/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalama <asalama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/10 18:06:13 by asalama           #+#    #+#             */
/*   Updated: 2016/02/11 12:58:29 by asalama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		draw_line(t_env *env, t_tab *tab, t_coord *coord)
{
	double 		a;
	double 		b;

	



	a = (double)(y2 - y1 / x2 - x1);
	b = coord.y1 - a * coord.x1;








void		tabtab(t_tab *tab, t_env *env)
{
	int			i;
	int			j;
	int			x;
	int			y;
	t_coord		coord;

	y = 500;
	j = 0;
	coord.boo = 0;
			printf("VER: %i\n", tab->size_ver);
	while (j < tab->size_ver)
	{
		x = 100;
		i = 0;
			printf("V: %i\n", tab->size_hor);
		while (i < tab->size_hor)
		{
			y = y - tab->tab_int[j][i];
		//	put_pixel(env, x, y);
			x += 5;
			i++;
		}
		y += 5;
		j++;
	}
}

x = 1 y =1;
x = 3 y = 2;	
x= 4 y = 0;
x = 8 y =7;


tmpx = 1 tmpy = 1 || x1 = 1 y1 = 1 |||| x2 = 1 
x2 = 4 y2 =0




void		put_pixel(t_env *env, int x, int y)
{
	x *= 4;
	env->addr[y * env->size_line + x] = 255; // PARAM COLOR
}
