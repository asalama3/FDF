/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalama <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/24 12:34:36 by asalama           #+#    #+#             */
/*   Updated: 2016/02/24 12:34:41 by asalama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		rotate_1(t_env *env, t_tab *tab, t_angle *angle)
{
	mlx_clear_window(env->mlx, env->win);
	mlx_destroy_image(env->mlx, env->img);
	angle->a += ROTATE_1;
	image(env, tab, angle);
}

void		rotate_2(t_env *env, t_tab *tab, t_angle *angle)
{
	mlx_clear_window(env->mlx, env->win);
	mlx_destroy_image(env->mlx, env->img);
	angle->a -= ROTATE_2;
	image(env, tab, angle);
}
