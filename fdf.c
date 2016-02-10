/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalama <asalama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/10 18:06:13 by asalama           #+#    #+#             */
/*   Updated: 2016/02/10 18:18:25 by asalama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		tabtab(t_tab *tab)
{
	// PARCOUR TAB
		//WHILE TAB
			// RECUP X Y Z
				// TRANFORMER EN X Y 
				// APPEL PUT PIXEL AVEC X Y EN PARAM
	
}

void		put_pixel(t_env *env, int x, int y)
{
	x *= 4; // ?? 
	env->addr[y * env->size_line + x] = 255; // PARAM COLOR
}
