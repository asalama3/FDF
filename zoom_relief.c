/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom_relief.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalama <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/24 12:34:55 by asalama           #+#    #+#             */
/*   Updated: 2016/02/24 12:55:48 by asalama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		zoom_in(t_env *env, t_tab *tab, t_angle *angle)
{
	mlx_clear_window(env->mlx, env->win);
	mlx_destroy_image(env->mlx, env->img);
	env->space += ZOOM;
	image(env, tab, angle);
}

void		zoom_out(t_env *env, t_tab *tab, t_angle *angle)
{
	mlx_clear_window(env->mlx, env->win);
	mlx_destroy_image(env->mlx, env->img);
	env->space -= ZOOM;
	if (env->space < 0)
		env->space = 1;
	image(env, tab, angle);
}

void		relief_z_up(t_env *env, t_tab *tab, t_angle *angle)
{
	int		i;
	int		j;

	mlx_clear_window(env->mlx, env->win);
	mlx_destroy_image(env->mlx, env->img);
	j = 0;
	while (j < tab->size_ver)
	{
		i = 0;
		while (i < tab->size_hor)
		{
			if (tab->tab_int[j][i] != 0)
			{
				tab->tab_int[j][i] += RELIEF;
				if (tab->tab_int[j][i] == 0)
					tab->tab_int[j][i] += RELIEF;
			}
			i++;
		}
		j++;
	}
	image(env, tab, angle);
}

void		relief_z_down(t_env *env, t_tab *tab, t_angle *angle)
{
	int		i;
	int		j;

	mlx_clear_window(env->mlx, env->win);
	mlx_destroy_image(env->mlx, env->img);
	j = 0;
	while (j < tab->size_ver)
	{
		i = 0;
		while (i < tab->size_hor)
		{
			if (tab->tab_int[j][i] != 0)
			{
				tab->tab_int[j][i] -= RELIEF;
				if (tab->tab_int[j][i] == 0)
					tab->tab_int[j][i] -= RELIEF;
			}
			i++;
		}
		j++;
	}
	image(env, tab, angle);
}
