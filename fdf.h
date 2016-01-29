/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalama <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/28 13:09:21 by asalama           #+#    #+#             */
/*   Updated: 2016/01/29 17:11:55 by asalama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H


#include <fcntl.h>
#include <mlx.h>
#include "libft/libft.h"

/*typedef struct		s_tab
{
	int				fd;
	char			**line;
	char			**tab;
}					t_tab;
*/

/*
** READ
*/

int					read_file(char **argv);

#endif

