/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalama <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/27 13:39:43 by asalama           #+#    #+#             */
/*   Updated: 2016/02/05 14:22:42 by asalama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "fdf.h"
#include <stdio.h>

//tracer un segment ac 2 points en 2D
// afficher un pixel pour chaque point et les relier apres
int		key_hook(int keycode, t_env env)
{
	if (keycode == 53)
		exit(-1);
	printf("keycode %d\n", keycode);
	return (0);
}

int		draw_pixel(t_env env, char **tab_int, int fd)
{
	int		x;
	int		y;

//	while (fd)
	{
		 mlx_pixel_put(env.mlx, env.win, x, y, 0x00FFFFFF);
	}
		return (0);
}

/*
void	draw_line(t_env *coord, t_env env)
{
	int		x;
	int		y;
	
	if (coord->x1 <= coord->x2)
		x = coord->x2 - coord->x1;
	else
		x = coord->x1 - coord->x2;
	if (coord->y1 <= coord->y2)
		y = coord->y2 - coord->y1;
	else
		y = coord->y1 - coord->y2;
	mlx_pixel_put(env.mlx, env.win, x, y, 0x00FFFFFF);
}
*/

int		main(int argc, char **argv)
{
	t_env	env;
	t_env	*coord;
	int		fd;
	char	**tab_int;

	if (argc == 2)
	{
		if (!read_file(&argv[1]))
			return (-1);
		if ((fd = open(argv[1], O_RDONLY)) == -1)
			return (-1);
		env.mlx = mlx_init();
		env.win = mlx_new_window(env.mlx, 1000, 1000, "42");
		env.img = mlx_new_image(env.mlx, 500, 500);
		draw_pixel(env, tab_int, fd);
//	env.addr = mlx_get_data_addr(env.img, env.bits_per_pixel, env.size_line, env.endian);
		mlx_put_image_to_window(env.mlx, env.win, env.img, 10, 10);
		mlx_key_hook(env.win, key_hook, &env);
		mlx_loop(env.mlx); // afficher la fenetre
	}
	return (0);
}
