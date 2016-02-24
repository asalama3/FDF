/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalama <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/24 12:29:40 by asalama           #+#    #+#             */
/*   Updated: 2016/02/24 13:33:48 by asalama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			key_hook_2(int keycode, t_env *env)
{
	if (keycode == 124)
		move_right(env);
	if (keycode == 123)
		move_left(env);
	if (keycode == 126)
		move_up(env);
	if (keycode == 125)
		move_down(env);
}

int				key_hook(int keycode, t_env *env)
{
	if (keycode == 53)
		exit(-1);
	key_hook_2(keycode, env);
	if (keycode == 69)
		zoom_in(env, env->tab, env->angle);
	if (keycode == 78)
		zoom_out(env, env->tab, env->angle);
	if (keycode == 32)
		relief_z_up(env, env->tab, env->angle);
	if (keycode == 2)
		relief_z_down(env, env->tab, env->angle);
	if (keycode == 15)
		rotate_1(env, env->tab, env->angle);
	if (keycode == 17)
		rotate_2(env, env->tab, env->angle);
	if (keycode == 34)
		iso(env, env->tab, env->angle);
	if (keycode == 31)
		ortho(env, env->tab, env->angle);
	return (0);
}
