/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalama <asalama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/10 18:06:13 by asalama           #+#    #+#             */
/*   Updated: 2016/02/23 12:43:16 by asalama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		put_pixel(t_env *env, int x, int y, t_tab *tab, int i, int j)
{

  //  printf("z:%d", i);
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

void		draw_line(t_env *env, t_coord *coord, t_tab *tab, int i, int j)
{
	double 		a;
	double		x;
	double		y;
    double      dx;
    double      dy;
    int         k;

    k = 0;
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
printf("%d\n", i);
    while (k < a)
    {
        put_pixel(env, x, y, tab, i , j);
        x += dx;
        y += dy;
        k++;
	}
}

void		tabtab(t_tab *tab, t_env *env, t_angle *angle)
{
	int			i;
	int			j;
//	int			x;
//	int			y;
	t_coord		coord;

	j = 0;
//	printf("PTR = %p && size_ver = %d\n", tab, tab->size_ver);
	while (j < tab->size_ver)
	{
		i = 0;
		while (i < tab->size_hor)
		{
			if (env->pro == 1)
                ortho_hor(&coord, tab, env, i, j, angle);
            else
                iso_hor(&coord, tab, env, i, j);
			if (i + 1 < tab->size_hor)
			{
				draw_line(env, &coord, tab, i, j);
                printf("%i\n", i);
			}
			if (j + 1 < tab->size_ver)
			{	
                if (env->pro == 1)
                ortho_ver(&coord, tab, env, i, j, angle);
            else
                iso_ver(&coord, tab, env, i, j);
				draw_line(env, &coord, tab, i, j);
			}
//			x += env->space;
			i++;
		}
//		y += env->space;
		j++;
	}
}
