/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalama <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/26 19:24:42 by asalama           #+#    #+#             */
/*   Updated: 2016/01/28 19:05:49 by asalama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//read fichier: get_next_line
//appeler la fonction split pour couper et recuperer que les caracteres
//creer un tableau d'int et appeler ft_atoi pour recuperer des int.
//

#include <mlx.h>
#include "fdf.h"

int		check_line(char *line)
{
	int		i;

	i = 0;
	while (line[i] != '\0')
	{
		if (!ft_isdigit(line[i]) && line[i] != ' ' && line[i] = '-')
			return (-1);
		i++;
	}
	return (1);
}

int		double_tab_int(char **tab, int fd, char **line)	
{
	int		i;
	int		size;

	size = 0;
//	while (get_next_line(fd, line) > 0)
//		size++;
	if (!(tab = (int**)ft_memalloc(sizeof(int*) * size)))
		return (NULL);
	tab[size + 1] = NULL;
	return (tab);
}

int		count_tab(char **tmp)
{
	int		i;

	i = 0;
	while (tmp[i] != NULL)
		i++;
	return (i);
}

int		parse_tab(char **tab, int size, char **line)
{
	char	**split;

	if (check_line(line))
	{
		if (split = ft_strsplit(line, ' '))
		{
		}
	}
	return (0);
}

int     read_file(char **argv)
{
	int		fd;
	char	*line;
	int		gnl;
	int		**tab;

	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (-1);
	double...
	while (gnl = get_next_line(fd, line))	
	{
		if (gnl == -1)
			return (-1);
		if (!tab[i] = (int*)ft_memalloc(sizeof(int) * ft_strlen(line)))
			return (NULL);
	}
	close(fd);
	return (1);
}
