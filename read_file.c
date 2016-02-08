/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalama <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/26 19:24:42 by asalama           #+#    #+#             */
/*   Updated: 2016/02/08 16:45:31 by asalama          ###   ########.fr       */
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

int			**double_tab_int(int fd, char **argv)
{
	int		i;
	int		size;
	char	**tab_char;
	int		**tab_int;
	int		j;
	char	*line;
	int		size2;

	size = 0;
	size2 = 0;
	while (get_next_line(fd, &line) > 0)
		size++;
	close(fd);
	if (!(tab_int = (int**)malloc(sizeof(int*) * size + 1)))
		return (NULL);
//	tab_int[size + 1] = NULL;
	i = 0;
	fd = open(argv[1], O_RDONLY);
	while (i < size)
	{
		get_next_line(fd, &line);
//		size = 0;
		j = 0;
		if (!check_line(line))
			return (NULL);
		tab_char = ft_strsplit(line, ' ');
		while (tab_char[size2])
			size2++;
		tab_int[i] = (int*)malloc(sizeof(int) * size2 + 1);
//		tab_int[i][0] = size2;
		while (j < size2)
		{
			tab_int[i][j] = ft_atoi(tab_char[j]);
			j++;
		}
		i++;
	}
		close(fd);
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

int			print_tab_int(int **tab_int)
{
	int		i;
	int		j;

	j = 0;
	while (j < 11)
	{
		i = 0;
		while (i < 19)
		{
			ft_putnbr(tab_int[j][i]);
			ft_putchar(' ');
			i++;
		}
		ft_putchar('\n');
		j++;
	}
	return (0);
}
int			read_file(char **argv)
{
	int		fd;
	int		**tab;

	if ((fd = open(argv[1], O_RDONLY)) == -1)
		return (-1);
	tab = double_tab_int(fd, argv);
	print_tab_int(tab);
//	close(fd);
	return (1);
}

int		main(int argc, char **argv)
{
	if (argc == 2)
		read_file(argv);
	return (0);
}
