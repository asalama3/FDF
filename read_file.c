/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalama <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/26 19:24:42 by asalama           #+#    #+#             */
/*   Updated: 2016/02/05 14:22:56 by asalama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			check_line(char *line)
{
	int		i;

	i = 0;
	while (line[i] != '\0')
	{
		if ((!ft_isdigit(line[i]) && line[i] != ' ') || line[i] == '-')
			return (-1);
		i++;
	}
	return (1);
}

int			**double_tab_int(int fd, char **line, char **argv)
{
	int		i;
	int		size;
	char	**tab_char;
	int		**tab_int;
	int		j;

	size = 0;
	while (get_next_line(fd, line) > 0)
		size++;
	close(fd);
	if (!(tab_int = (int**)malloc(sizeof(int*) * size + 1)))
		return (NULL);
	tab_int[size + 1] = NULL;
	i = 0;
	fd = open(argv[1], O_RDONLY);
	while (tab_int[i] != NULL)
	{
		get_next_line(fd, line);
		size = 0;
		j = 1;
		if (!check_line(*line))
			return (NULL);
		tab_char = ft_strsplit(*line, ' ');
		while (tab_char[size] != NULL)
			size++;
		tab_int[i] = (int*)malloc(sizeof(int) * size + 1);
		tab_int[i][0] = size;
		while (tab_char[j] != NULL)
		{
			tab_int[i][j] = ft_atoi(tab_char[i]);
			j++;
		}
		i++;
	}
	return (tab_int);
}

/*compte le nombre de ligne dans mon fichier
int		count_tab(char **tmp)
{
	int		i;

	i = 0;
	while (tmp[i] != NULL)
		i++;
	return (i);
}
*/

int			read_file(char **argv)
{
	int		fd;
	char	**line;
	int		**tab;

	line = NULL;
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (-1);
	tab = double_tab_int(fd, line, argv);
	close(fd);
	return (1);
}
