/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalama <asalama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/10 18:06:13 by asalama           #+#    #+#             */
/*   Updated: 2016/02/23 18:49:42 by asalama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		ortho_hor(t_coord *coord, t_tab *tab, t_env *env, t_angle *angle)
{
    int     i;
    int     j;

    i = tab->i;
    j = tab->j;
	coord->x1 = 100 + env->space * (cos(angle->b) * i + sin(angle->b) * j);
	coord->y1 = 300 + env->space * (sin(angle->a) * (sin(angle->b) * i - cos(angle->b) * j) + cos(angle->a) * tab->tab_int[j][i]);
	coord->x2 = 100 + env->space * (cos(angle->b) * (i + 1) + sin(angle->b) * j);
	coord->y2 = 300 + env->space * (sin(angle->a) * (sin(angle->b) * (i + 1) - cos(angle->b) * j) + cos(angle->a) * tab->tab_int[j][i + 1]);
}

void		ortho_ver(t_coord *coord, t_tab *tab, t_env *env, t_angle *angle)
{
    int     i;
    int     j;

    i = tab->i;
    j = tab->j;
	coord->x1 = 100 + env->space * (cos(angle->b) * i + sin(angle->b) * j);
	coord->y1 = 300 + env->space * (sin(angle->a) * (sin(angle->b) * i - cos(angle->b) * j) + cos(angle->a) * tab->tab_int[j][i]);
	coord->x2 = 100 + env->space * (cos(angle->b) * (i) + sin(angle->b) * (j + 1));
	coord->y2 = 300 + env->space * (sin(angle->a) * (sin(angle->b) * (i) - cos(angle->b) * (j + 1)) + cos(angle->a) * tab->tab_int[j + 1][i]);
}

void		iso_hor(t_coord *coord, t_tab *tab, t_env *env)
{
    int     i;
    int     j;

    i = tab->i;
    j = tab->j;
	coord->x1 = 200 + env->space * ((sqrtf(2) / 2) * i - ((sqrtf(2) / 2) * j));
	coord->y1 = 300 + env->space * (((1 / sqrtf(6)) * (i + j)) - ((sqrtf(2 / sqrtf(3))) * tab->tab_int[j][i]));
	coord->x2 = 200 + env->space * ((sqrtf(2) / 2) * (i + 1) - ((sqrtf(2) / 2) * j));
	coord->y2 = 300 + env->space * (((1 / sqrtf(6)) * ((i + 1) + j)) - ((sqrtf(2 / sqrtf(3))) * tab->tab_int[j][i + 1]));
}

void		iso_ver(t_coord *coord, t_tab *tab, t_env *env)
{
    int     i;
    int     j;

    i = tab->i;
    j = tab->j;
	coord->x1 = 200 + env->space * ((sqrtf(2) / 2) * i - ((sqrtf(2) / 2) * j));
	coord->y1 = 300 + env->space * (((1 / sqrtf (6)) * (i + j)) - ((sqrtf(2 / sqrtf(3))) * tab->tab_int[j][i]));
	coord->x2 = 200 + env->space * ((sqrtf(2) / 2) * i - ((sqrtf(2) / 2) * (j + 1)));
	coord->y2 = 300 + env->space * (((1 / sqrtf (6)) * (i + (j + 1))) - ((sqrtf(2 / sqrtf(3))) * tab->tab_int[j + 1][i]));
}

