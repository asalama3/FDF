/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalama <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/27 13:39:43 by asalama           #+#    #+#             */
/*   Updated: 2016/02/23 19:11:41 by asalama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

int		key_hook(int keycode, t_env *env)
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
	if (keycode == 14) // e
		zoom_in(env, env->tab, env->angle);
	if (keycode == 15) // r
		zoom_out(env, env->tab, env->angle);
    if (keycode == 12) // a
        relief_z_up(env, env->tab, env->angle);
	if (keycode == 13) // z
		relief_z_down(env, env->tab, env->angle);
	if (keycode == 49) // espace
		rotate_1(env, env->tab, env->angle);
	if (keycode == 6) // z
		rotate_2(env, env->tab, env->angle);
	if (keycode == 34) // i
		iso(env, env->tab, env->angle);
	if (keycode == 31) // o
		ortho(env, env->tab, env->angle);
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
			env->addr[y * env->size_line + x++] = 255; //ROUGE
	    	env->addr[y * env->size_line + x++] = 255; // VERT
			env->addr[y * env->size_line + x++] = 0; //TRANSPARENCE
		}
		y++;
	}
	return (0);
}

void    image(t_env *env, t_tab *tab, t_angle *angle)
{
    ft_putstr("OKAY");
    env->img = mlx_new_image(env->mlx, WIDTH, HEIGHT);
	env->addr = mlx_get_data_addr(env->img, &env->bpp, &env->size_line, &env->endian);
//		printf("SL2 : %i\n", env->size_line);
//		printf("BPP2 : %i\n", env->bpp);
//		printf("ENDIAN2 : %i\n", env->endian);
	tabtab(tab, env, angle);
	mlx_put_image_to_window(env->mlx, env->win, env->img, env->x, env->y);
}


int        key(t_env *env)
{
    mlx_do_key_autorepeaton(env->mlx);
  //  key_hook(env);
    return (0);
}


void    ft_error(char *s)
{
    ft_putendl(s);
    exit(0);
}

int		main(int argc, char **argv)
{
	t_env	env;
	t_tab	*tab;
//	int		fd;
//	char	**tab_int;
    t_angle angle;

	if (argc == 2)
	{
		if (!(tab = read_file(argv[1])))
			return (0);
//		print_tab_int(tab->tab_int);
		env.x = 0;
		env.y = 0;
        angle.a = 220 * M_PI / 180;
        angle.b = 20 * M_PI / 180;
		env.mlx = mlx_init();
		env.space = 20;
        env.pro = 1;
		env.win = mlx_new_window(env.mlx, SIZE_X, SIZE_Y, "42");
		env.img = mlx_new_image(env.mlx, WIDTH, HEIGHT);
		env.addr = mlx_get_data_addr(env.img, &env.bpp, &env.size_line, &env.endian);
		printf("BPP : %i\n", env.bpp);
        printf("SL : %i\n", env.size_line);
		printf("ENDIAN : %i\n", env.endian);
//		draw_square(&env);
		tabtab(tab, &env, &angle);
		mlx_put_image_to_window(env.mlx, env.win, env.img, env.x, env.y);
		env.tab = tab;
        env.angle = &angle;
//		mlx_key_hook(env.win, key_hook, &env);
		//mlx_key_hook(env.win, key, &env);
        mlx_hook(env.win, KEYPRESS, KEYPRESSMASK, key_hook ,&env);
        mlx_loop(env.mlx);
	}
	return (0);
}
