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

int		main()
{
	void	*mlx;
	void	*win;
	int		x;
	int		y;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 1000, 1000, "mlx 42");
	y = 50;
	while (y < 1500)
	{
		x = 50;
		while (x < 1500)
		{
			mlx_pixel_put(mlx, win, x, y, 0x00FFFFFF);
			x++;
		}
		y++;
	}
	mlx_loop(mlx); // donner la main a lensemble du system graphique mac qui se charge d'affichier la fenetre.
}

// 
