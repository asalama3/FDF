/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalama <asalama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/10 14:56:17 by asalama           #+#    #+#             */
/*   Updated: 2016/02/16 20:36:18 by asalama          ###   ########.fr       */
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

void		zoom_out(t_env *env, t_tab *tab)	
{
	mlx_clear_window(env->mlx, env->win);
//	mlx_destroy_image(env->mlx, env->img);
	env->space -= 5;
	tabtab(tab, env);
	mlx_put_image_to_window(env->mlx, env->win, env->img, env->x, env->y);
}

void		zoom_in(t_env *env, t_tab *tab)	
{
	mlx_clear_window(env->mlx, env->win);
//	mlx_destroy_image(env->mlx, env->img);
	env->space += 5;
	tabtab(tab, env);
	mlx_put_image_to_window(env->mlx, env->win, env->img, env->x, env->y);
printf("env space:%d\n", env->space);
}

void        relief_z_up(t_env *env, t_tab *tab)
{
	mlx_clear_window(env->mlx, env->win);
	mlx_destroy_image(env->mlx, env->img);
	env->img = mlx_new_image(env->mlx, 1000, 1000);
	env->z += 5;
	tabtab(tab, env);
	mlx_put_image_to_window(env->mlx, env->win, env->img, env->x, env->y);
//printf("z:%d\n", env->z);
}

void        relief_z_down(t_env *env, t_tab *tab)
{
	mlx_clear_window(env->mlx, env->win);
	mlx_destroy_image(env->mlx, env->img);
	env->img = mlx_new_image(env->mlx, 1000, 1000);
	env->z -= 5;
	tabtab(tab, env);
	mlx_put_image_to_window(env->mlx, env->win, env->img, env->x, env->y);
}
