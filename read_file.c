/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalama <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/26 19:24:42 by asalama           #+#    #+#             */
/*   Updated: 2016/02/16 14:13:24 by asalama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			check_line(char *line)
{
	int		i;

	i = 0;
	while (line[i] != '\0')
	{
		if ((!ft_isdigit(line[i]) && line[i] != ' ') && line[i] != '-')
			return (0);
		i++;
	}
	return (1);
}

t_tab			*double_tab_int(int fd, char *argv)
{
	int		i;
	t_tab	*tab;
	char	**tab_char;
	int		j;
	char	*line;

	if ((tab = (t_tab*)malloc(sizeof(t_tab))) == NULL)
		return (NULL);
	tab->size_hor = 0;
	tab->size_ver = 0;
	while (get_next_line(fd, &line) > 0)
		tab->size_ver++;
	close(fd);
	if (!(tab->tab_int = (int**)malloc(sizeof(int*) * tab->size_ver + 1)))
		return (NULL);
//	tab_int[size + 1] = NULL;
	i = 0;
	fd = open(argv, O_RDONLY);
	while (i < tab->size_ver)
	{
		get_next_line(fd, &line);
//		size = 0;
		j = 0;
		if (!check_line(line))
			return (NULL);
		tab_char = ft_strsplit(line, ' ');
		while (tab_char[tab->size_hor])
			tab->size_hor++;
		tab->tab_int[i] = (int*)malloc(sizeof(int) * tab->size_hor + 1);
//		tab_int[i][0] = size2;
		while (j < tab->size_hor)
		{
			tab->tab_int[i][j] = ft_atoi(tab_char[j]);
			printf("---------------------------\n%i\n", tab->tab_int[i][j]);
			printf("%i\n", ft_atoi(tab_char[j]));
			j++;
		}
		i++;
	}
		close(fd);
	return (tab);
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

int			print_tab_int(t_tab *tab)
{
	int		i;
	int		j;

	j = 0;
	while (j < tab->size_ver)
	{
		i = 0;
		while (i < tab->size_hor)
		{
			ft_putnbr(tab->tab_int[j][i]);
			ft_putchar(' ');
			i++;
		}
		ft_putchar('\n');
		j++;
	}
	return (0);
}

t_tab		*read_file(char *argv)
{
	int		fd;
	t_tab	*tab;
	
	if ((fd = open(argv, O_RDONLY)) == -1)
		return (0);
	if (!(tab = double_tab_int(fd, argv)))
		return (0);
//	double_tab_int(fd, argv, tab);
	print_tab_int(tab);
//	close(fd);
	return (tab);
}
/*
int		main(int argc, char **argv)
{
	if (argc == 2)
		read_file(argv[1]);
	return (0);
}*/
