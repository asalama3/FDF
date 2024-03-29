/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcul.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalama <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/24 12:34:16 by asalama           #+#    #+#             */
/*   Updated: 2016/02/24 12:34:22 by asalama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		ortho_hor(t_coord *coord, t_tab *tab, t_env *env, t_angle *a)
{
	int		i;
	int		j;

	i = tab->i;
	j = tab->j;
	coord->x1 = 100 + env->space * (cos(a->b) * i + sin(a->b) * j);
	coord->y1 = 300 + env->space * (sin(a->a) * (sin(a->b) *
				i - cos(a->b) * j) + cos(a->a) * tab->tab_int[j][i]);
	coord->x2 = 100 + env->space * (cos(a->b) * (i + 1) + sin(a->b) * j);
	coord->y2 = 300 + env->space * (sin(a->a) * (sin(a->b) * (i + 1) -
				cos(a->b) * j) + cos(a->a) * tab->tab_int[j][i + 1]);
}

void		ortho_ver(t_coord *coord, t_tab *tab, t_env *env, t_angle *a)
{
	int		i;
	int		j;

	i = tab->i;
	j = tab->j;
	coord->x1 = 100 + env->space * (cos(a->b) * i + sin(a->b) * j);
	coord->y1 = 300 + env->space * (sin(a->a) * (sin(a->b) *
				i - cos(a->b) * j) + cos(a->a) * tab->tab_int[j][i]);
	coord->x2 = 100 + env->space * (cos(a->b) * (i) + sin(a->b) * (j + 1));
	coord->y2 = 300 + env->space * (sin(a->a) * (sin(a->b) * (i) -
				cos(a->b) * (j + 1)) + cos(a->a) * tab->tab_int[j + 1][i]);
}

void		iso_hor(t_coord *coord, t_tab *tab, t_env *env)
{
	int		i;
	int		j;

	i = tab->i;
	j = tab->j;
	coord->x1 = 200 + env->space * ((sqrtf(2) / 2) * i - ((sqrtf(2) / 2) * j));
	coord->y1 = 300 + env->space * (((1 / sqrtf(6)) * (i + j)) -
			((sqrtf(2 / sqrtf(3))) * tab->tab_int[j][i]));
	coord->x2 = 200 + env->space * ((sqrtf(2) / 2) * (i + 1) -
			((sqrtf(2) / 2) * j));
	coord->y2 = 300 + env->space * (((1 / sqrtf(6)) * ((i + 1) + j)) -
			((sqrtf(2 / sqrtf(3))) * tab->tab_int[j][i + 1]));
}

void		iso_ver(t_coord *coord, t_tab *tab, t_env *env)
{
	int		i;
	int		j;

	i = tab->i;
	j = tab->j;
	coord->x1 = 200 + env->space * ((sqrtf(2) / 2) * i - ((sqrtf(2) / 2) * j));
	coord->y1 = 300 + env->space * (((1 / sqrtf(6)) * (i + j)) -
			((sqrtf(2 / sqrtf(3))) * tab->tab_int[j][i]));
	coord->x2 = 200 + env->space * ((sqrtf(2) / 2) * i -
			((sqrtf(2) / 2) * (j + 1)));
	coord->y2 = 300 + env->space * (((1 / sqrtf(6)) * (i + (j + 1))) -
			((sqrtf(2 / sqrtf(3))) * tab->tab_int[j + 1][i]));
}
