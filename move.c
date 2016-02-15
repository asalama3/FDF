/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalama <asalama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/10 14:56:17 by asalama           #+#    #+#             */
/*   Updated: 2016/02/12 18:50:22 by asalama          ###   ########.fr       */
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

void		zoom_out(t_env *env)	
{
	mlx_clear_window(env->mlx, env->win);
	env->x -= env->space;
	env->y -= env->space;
	mlx_put_image_to_window(env->mlx, env->win, env->img, env->x, env->y);
}

void		zoom_in(t_env *env, t_tab *tab)	
{
	env->space += 5;
	mlx_clear_window(env->mlx, env->win);
	mlx_put_image_to_window(env->mlx, env->win, env->img, env->x, env->y);
printf("env space:%d\n", env->space);
}

void        relief_z(t_env *env, t_tab *tab)
{
	mlx_clear_window(env->mlx, env->win);
	env->z += 1;@
	mlx_put_image_to_window(env->mlx, env->win, env->img, env->x, env->y);
printf("env space:%d\n", env->z);
printf("env space:%d\n", env->x);
printf("env space:%d\n", env->y);
}
