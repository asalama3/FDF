/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalama <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/27 13:39:43 by asalama           #+#    #+#             */
/*   Updated: 2016/02/15 16:55:11 by asalama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

int		key_hook(int keycode, t_env *env, t_tab *tab)
{
	if (keycode == 53)
		exit(-1);
	if (keycode == 124)
		move_right(env);
	if (keycode == 123)
		move_left(env);
	if (keycode == 126)
		move_up(env);
	if (keycode == 125)
		move_down(env);
	if (keycode == 78)
		zoom_out(env);
	if (keycode == 69)
		zoom_in(env, tab);
    if (keycode == 15)
        relief_z(env, env->tab);
	if (keycode == 17)
		relief_z2(env, env->tab);
	printf("keycode %d\n", keycode);
	return (0);
}

int		draw_square(t_env *env)
{
	int		x;
	int		y;

	y = 0;
	while (y < 500)
	{
		x = 0;
		while (x < 500)
		{
			// ENDIAN A 0 DONC LECTURE (alpha | RGB)<-
	    	env->addr[y * env->size_line + x++] = 255; // BLEU
			env->addr[y * env->size_line + x++] = 100; //ROUGE
	    	env->addr[y * env->size_line + x++] = 0; // VERT
			env->addr[y * env->size_line + x++] = 200; //TRANSPARENCE
		}
		y++;
	}
	return (0);
}

int		main(int argc, char **argv)
{
	t_env	env;
	t_tab	*tab;
	int		fd;
	char	**tab_int;

	if (argc == 2)
	{
		if (!(tab = read_file(argv[1])))
			return (-1);
//		print_tab_int(tab->tab_int);
		env.x = 0;
		env.y = 0;
		env.mlx = mlx_init();
		env.space = 20;
   		env.z = 1;
		env.win = mlx_new_window(env.mlx, 1000, 1000, "42");
		env.img = mlx_new_image(env.mlx, 1000, 1000);
		env.addr = mlx_get_data_addr(env.img, &env.bpp, &env.size_line, &env.endian);
		printf("SL : %i\n", env.size_line);
		printf("BPP : %i\n", env.bpp);
		printf("ENDIAN : %i\n", env.endian);
//		draw_square(&env);
		tabtab(tab, &env);
		mlx_put_image_to_window(env.mlx, env.win, env.img, env.x, env.y);
		env.tab = tab;
		mlx_key_hook(env.win, key_hook, &env);
		mlx_loop(env.mlx);
	}
	return (0);
}
