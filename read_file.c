/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalama <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/26 19:24:42 by asalama           #+#    #+#             */
/*   Updated: 2016/02/24 12:50:50 by asalama          ###   ########.fr       */
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

t_tab		*parse(int fd, char *line, t_tab *tab)
{
	int		tmp;
	char	**tab_char;

	tmp = 0;
	while (tab->i < tab->size_ver)
	{
		get_next_line(fd, &line);
		tab->j = 0;
		if (!check_line(line))
			return (NULL);
		tab_char = ft_strsplit(line, ' ');
		while (tab_char[tab->size_hor])
			tab->size_hor++;
		tab->tab_int[tab->i] = (int*)malloc(sizeof(int) * tab->size_hor + 1);
		if (tab->i > 0 && tmp != tab->size_hor)
			return (NULL);
		tmp = tab->size_hor;
		while (tab->j < tab->size_hor)
		{
			tab->tab_int[tab->i][tab->j] = ft_atoi(tab_char[tab->j]);
			tab->j++;
		}
		tab->i++;
	}
	return (tab);
}

t_tab		*double_tab_int(int fd, char *argv)
{
	t_tab	*tab;
	char	*line;

	if ((tab = (t_tab*)malloc(sizeof(t_tab))) == NULL)
		return (NULL);
	tab->size_hor = 0;
	tab->size_ver = 0;
	while (get_next_line(fd, &line) > 0)
		tab->size_ver++;
	if (close(fd) == -1)
		ft_error("close error");
	if (!(tab->tab_int = (int**)malloc(sizeof(int*) * tab->size_ver + 1)))
		return (NULL);
	tab->i = 0;
	fd = open(argv, O_RDONLY);
	tab = parse(fd, line, tab);
	close(fd);
	return (tab);
}

int			print_tab_int(t_tab *tab)
{
	int		i;
	int		j;

	i = tab->i;
	j = tab->j;
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
		ft_error("fd error");
	if (!(tab = double_tab_int(fd, argv)))
		return (0);
	print_tab_int(tab);
	return (tab);
}
