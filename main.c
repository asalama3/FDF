/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalama <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/27 13:39:43 by asalama           #+#    #+#             */
/*   Updated: 2016/01/28 18:07:55 by asalama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "fdf.h"
#include <stdio.h>

//tracer un segment ac 2 points en 2D
//
int		key_hook(int keycode, t_env *env)
{
	if (env)
	{
		if (keycode == 53)
			exit(-1);
	}
	printf("keycode %d\n", keycode);
	return (0):
}

int		draw(t_env *env)
{
	int		x;
	int		y;

	y = 0;
	while (y < 500)
	{
		x = 0;
		while (x < 500)
		{
			mlx_pixel_put(env.mlx, env.win, x, y, 0x00FFFFFF)
			x++;
		}
	y++;
	}
}


int		main()
{
	t_env env;

	env.mlx = mlx_init();
	env.win = mlx_new_window(env.mlx, 1000, 1000, "42");
	env.img = mlx_new_image(env.mlx, 500, 500);
	draw(env);
	env.addr = mlx_get_data_addr(env.img, env.bits_per_pixel, env.size_line, env.endian);
	mlx_put_image_to_window(env.mlx, env.win, env.img, 10, 10);
	mlx_key_hook(env.win, key_hook, &env);
	mlx_loop(env.mlx); // afficher la fenetre
	return (0);
}
