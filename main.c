/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalama <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/27 13:39:43 by asalama           #+#    #+#             */
/*   Updated: 2016/02/24 13:31:15 by asalama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			image(t_env *env, t_tab *tab, t_angle *angle)
{
	env->img = mlx_new_image(env->mlx, WIDTH, HEIGHT);
	env->addr = mlx_get_data_addr(env->img, &env->bpp,
			&env->size_line, &env->endian);
	tabtab(tab, env, angle);
	mlx_put_image_to_window(env->mlx, env->win, env->img, env->x, env->y);
}

void			ft_error(char *s)
{
	ft_putendl(s);
	exit(-1);
}

void			init_var(t_env *env, t_angle *a)
{
	env->x = 0;
	env->y = 0;
	a->a = 220 * M_PI / 180;
	a->b = 20 * M_PI / 180;
	env->space = 20;
	env->pro = 1;
}

int				main(int argc, char **argv)
{
	t_env		env;
	t_angle		a;

	if (argc != 2)
		ft_error("Invalid Number of Arguments");
	else
	{
		if (!(env.tab = read_file(argv[1])))
			ft_error("Invalid File");
		init_var(&env, &a);
		if (!(env.mlx = mlx_init()))
			ft_error("Mlx Error");
		if (!(env.win = mlx_new_window(env.mlx, SIZE_X, SIZE_Y, "MLX")))
			ft_error("Window Error");
		env.img = mlx_new_image(env.mlx, WIDTH, HEIGHT);
		env.addr = mlx_get_data_addr(env.img, &env.bpp,
				&env.size_line, &env.endian);
		tabtab(env.tab, &env, &a);
		mlx_put_image_to_window(env.mlx, env.win, env.img, env.x, env.y);
		env.angle = &a;
		mlx_hook(env.win, KEYPRESS, KEYPRESSMASK, key_hook, &env);
		mlx_loop(env.mlx);
	}
	return (0);
}
