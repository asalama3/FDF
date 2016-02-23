/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalama <asalama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/10 14:56:17 by asalama           #+#    #+#             */
/*   Updated: 2016/02/23 19:26:04 by asalama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		move_right(t_env *env)
{
	mlx_clear_window(env->mlx, env->win);
	env->x += env->space;
	mlx_put_image_to_window(env->mlx, env->win, env->img, env->x, env->y);
}

void		move_left(t_env *env)
{
	mlx_clear_window(env->mlx, env->win);
	env->x -= env->space;
	mlx_put_image_to_window(env->mlx, env->win, env->img, env->x, env->y);
}

void		move_up(t_env *env)
{
	mlx_clear_window(env->mlx, env->win);
	env->y -= env->space;
	mlx_put_image_to_window(env->mlx, env->win, env->img, env->x, env->y);
}

void		move_down(t_env *env)
{
	mlx_clear_window(env->mlx, env->win);
	env->y += env->space;
	mlx_put_image_to_window(env->mlx, env->win, env->img, env->x, env->y);
}
