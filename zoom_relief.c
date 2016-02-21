/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalama <asalama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/10 14:56:17 by asalama           #+#    #+#             */
/*   Updated: 2016/02/19 14:44:05 by asalama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		zoom_in(t_env *env, t_tab *tab, t_angle *angle)	
{
	mlx_clear_window(env->mlx, env->win);
	mlx_destroy_image(env->mlx, env->img);
	env->space += ZOOM;
    image(env, tab, angle);
//    printf("env space:%d\n", env->space);
}

void		zoom_out(t_env *env, t_tab *tab, t_angle *angle)	
{
	mlx_clear_window(env->mlx, env->win);
	mlx_destroy_image(env->mlx, env->img);
	env->space -= ZOOM;
	if (env->space < 0)
        env->space = 1;
	image(env, tab, angle);
  //  printf("env->space:%d\n", env->space);
}

void        relief_z_up(t_env *env, t_tab *tab, t_angle *angle)
{
    int     i;
    int     j;

    ft_putstr("OK\n");
	mlx_clear_window(env->mlx, env->win);
	mlx_destroy_image(env->mlx, env->img);
	j = 0;
    while (j < tab->size_ver)
    {
        i = 0;
        while (i < tab->size_hor)
        {
            if (tab->tab_int[j][i] != '\0')
                tab->tab_int[j][i] += RELIEF;
//                printf("%i\n", tab->tab_int[j][i]);
            i++;
        }
        j++;
    }
//    printf("tab:%i\n", tab->tab_int[j][i]);
    image(env, tab, angle);
}

void        relief_z_down(t_env *env, t_tab *tab, t_angle *angle)
{
    int     i;
    int     j;

    ft_putstr("OK\n");
	mlx_clear_window(env->mlx, env->win);
	mlx_destroy_image(env->mlx, env->img);
	j = 0;
    while (j < tab->size_ver)
    {
        i = 0;
        while (i < tab->size_hor)
        {
            if (tab->tab_int[j][i] != '\0')
                tab->tab_int[j][i] -= RELIEF;
  //              printf("%i\n", tab->tab_int[j][i]);
            i++;
        }
        j++;
    }
//    printf("tab:%i\n", tab->tab_int[j][i]);
    image(env, tab, angle);
}
