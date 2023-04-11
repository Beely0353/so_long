/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_solvable.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biaroun <biaroun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 12:35:58 by biaroun           #+#    #+#             */
/*   Updated: 2023/04/11 11:50:50 by biaroun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

char	**tabdub(char **tab)
{
	int		i;
	int		j;
	char	**dub;

	i = 0;
	while (tab[i])
		i++;
	dub = malloc(sizeof(char *) * (i + 1));
	i = -1;
	while (tab[++i])
	{
		j = -1;
		dub[i] = malloc(sizeof(char) * (ft_strlen(tab[i]) + 1));
		while (tab[i][++j])
			dub[i][j] = tab[i][j];
		dub[i][j] = '\0';
	}
	dub[i] = NULL;
	return (dub);
}

void	create_path2(char **dub, int i, int j)
{
	if (dub[i][j + 1] != '1' && dub[i][j + 1] != 'V')
		dub[i][j + 1] = '*';
	if (dub[i][j - 1] != '1' && dub[i][j - 1] != 'V')
		dub[i][j - 1] = '*';
	if (dub[i + 1][j] != '1' && dub[i + 1][j] != 'V')
		dub[i + 1][j] = '*';
	if (dub[i - 1][j] != '1' && dub[i - 1][j] != 'V')
		dub[i - 1][j] = '*';
}

void	create_path(char **dub)
{
	int	i;
	int	j;

	i = 0;
	while (dub[++i])
	{
		j = 0;
		while (dub[i][++j])
		{
			if (dub[i][j] == 'P' || dub[i][j] == '*')
			{
				dub[i][j] = 'V';
				create_path2(dub, i, j);
				i = 0;
				break ;
			}
		}
	}
}

void	check_is_solvable(char	**dub, char **tab)
{
	int	i;
	int	j;

	i = 0;
	while (dub[++i])
	{
		j = 0;
		while (dub[i][++j])
		{
			if (dub[i][j] == 'E' || dub[i][j] == 'C')
			{
				free_tab(tab);
				free_tab(dub);
				ft_putendl_fd("Map isn't solvable", STDERR_FILENO);
				exit(EXIT_FAILURE);
			}
		}
	}
}

void	is_solvable(t_solong *map)
{
	char	**dub;
	int		i;
	int		j;

	i = -1;
	dub = tabdub(map->tab);
	create_path(dub);
	check_is_solvable(dub, map->tab);
	free_tab(dub);
	while (map->tab[++i])
	{
		j = -1;
		while (map->tab[i][++j])
		{
			if (map->tab[i][j] == 'E')
			{
				map->exit_x = j * PXL;
				map->exit_y = i * PXL;
				return ;
			}
		}
	}
}
