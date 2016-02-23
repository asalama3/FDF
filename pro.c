/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pro.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalama <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 11:57:02 by asalama           #+#    #+#             */
/*   Updated: 2016/02/23 12:33:52 by asalama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void        ortho(t_env *env, t_tab *tab, t_angle *angle)
{
    mlx_clear_window(env->mlx, env->win);
    mlx_destroy_image(env->mlx, env->img);
    env->pro = 1;
    image(env, tab, angle);
}

void        iso(t_env *env, t_tab *tab, t_angle *angle)
{
    mlx_clear_window(env->mlx, env->win);
    mlx_destroy_image(env->mlx, env->img);
    env->pro = 2;
    image(env, tab, angle);
}



