/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baroun <baroun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 11:59:55 by baroun            #+#    #+#             */
/*   Updated: 2022/05/27 12:01:20 by baroun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	exit_game(void)
{
	exit(0);
}

void	file_error(int c)
{
	if (c == 1)
	{
		ft_putendl_fd("Error Directory", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	if (c == 2)
	{
		ft_putendl_fd("Error File", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	if (c == 3)
	{
		ft_putendl_fd("Invalid charactere", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	if (c == 4)
	{
		ft_putendl_fd("Map is not rectangular", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	if (c == 5)
	{
		ft_putendl_fd("Map is not close", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
}

void	free_tab(t_solong *map)
{
	int	i;

	i = 0;
	while (map->tab[i])
	{
		free(map->tab[i]);
		map->tab[i] = NULL;
		i++;
	}
	free(map->tab);
}

void	map_error(t_solong *map)
{
	int	i;
	int	a;

	i = -1;
	while (map->tab[++i])
	{
		a = -1;
		while (map->tab[i][++a])
		{
			if (map->tab[i][a] != 'C' && map->tab[i][a] != 'P' && map->tab[i][a]
				!= 'E' && map->tab[i][a] != '1' && map->tab[i][a] != '0')
				file_error(3);
		}
		if (a != map->line_max)
			file_error(4);
		if (map->tab[i][--a] != '1' || map->tab[i][0] != '1')
			file_error(5);
	}
	i--;
	while (a > 0)
	{
		if (map->tab[i][a] != '1' || map->tab[0][a] != '1')
			file_error(5);
		a--;
	}
}

void	check_ext(char *av)
{
	char	*str;
	char	*ext;

	str = av;
	ext = ".ber";
	if (ft_strlen(str) < 5)
	{
		ft_putendl_fd("Extension Error", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	while (*str)
		str++;
	str -= 4;
	if (ft_strncmp(str, ext, 4))
	{
		ft_putendl_fd("Extension Error", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
}
