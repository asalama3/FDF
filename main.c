/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalama <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/27 13:39:43 by asalama           #+#    #+#             */
/*   Updated: 2016/02/09 20:10:13 by asalama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "fdf.h"
#include <stdio.h>

int		key_hook(int keycode, t_env env)
{
	if (keycode == 53)
		exit(-1);
	printf("keycode %d\n", keycode);
	return (0);
}

int		draw_square(t_env *env)
{
	env->y = 0;
	while (env->y < 25)
	{
		env->x = 0;
		while (env->x < 25)
		{
			env->addr[env->y * env->size_line + env->x] = 255;
			env->x = env->x + 4;
		}
		env->y++;
	}
	return (0);
}

int		main(int argc, char **argv)
{
	t_env	env;
	t_env	*coord;
	int		fd;
	char	**tab_int;

	if (argc == 2)
	{
		if (!read_file(argv[1]))
			return (-1);
		env.mlx = mlx_init();
		env.win = mlx_new_window(env.mlx, 1000, 1000, "42");
		env.img = mlx_new_image(env.mlx, 50, 50);
		env.addr = mlx_get_data_addr(&env.img, &env.bits_per_pixel, &env.size_line, &env.endian);
		printf("SL : %i\n", env.size_line);
		printf("BPP : %i\n", env.bits_per_pixel);
		printf("ENDIAN : %i\n", env.endian);
		draw_square(&env);
		mlx_put_image_to_window(env.mlx, env.win, env.img, 10, 10);
		mlx_key_hook(env.win, key_hook, &env);
		mlx_loop(env.mlx); // afficher la fenetre
	}
	return (0);
}
