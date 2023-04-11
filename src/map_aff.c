/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_aff.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biaroun <biaroun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 12:36:09 by biaroun           #+#    #+#             */
/*   Updated: 2023/04/11 11:51:11 by biaroun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	pars_map(t_solong *map)
{
	int	y;
	int	x;

	y = -1;
	map->y = 0;
	while (map->tab[++y])
	{
		x = -1;
		map->x = 0;
		while (map->tab[y][++x])
		{
			aff_map(map, y, x);
			map->x += PXL;
		}
		map->y += PXL;
	}
	mlx_put_image_to_window(map->mlx, map->win,
		map->is_exit, map->exit_x, map->exit_y);
	mlx_put_image_to_window(map->mlx, map->win,
		map->is_player, map->p_x, map->p_y);
	if (map->tab[map->exit_y / PXL][map->exit_x / PXL] != 'P')
		map->tab[map->exit_y / PXL][map->exit_x / PXL] = 'E';
}

void	aff_map(t_solong *map, int y, int x)
{
	if (map->tab[y][x] == '1')
	{
		mlx_put_image_to_window(map->mlx, map->win,
			map->is_wall, map->x, map->y);
	}
	else if (map->tab[y][x] == '0')
		aff_ground(map);
	else if (map->tab[y][x] == 'P')
	{
		aff_ground(map);
		map->p_x = x * PXL;
		map->p_y = y * PXL;
	}
	else if (map->tab[y][x] == 'C')
	{
		aff_ground(map);
		mlx_put_image_to_window(map->mlx, map->win,
			map->is_collectible, map->x, map->y);
	}
	else if (map->tab[y][x] == 'E')
	{
		aff_ground(map);
		mlx_put_image_to_window(map->mlx, map->win,
			map->is_exit, map->x, map->y);
	}
}

void	aff_ground(t_solong *map)
{
	mlx_put_image_to_window(map->mlx, map->win, map->is_ground, map->x, map->y);
}

void	return_error(int c, t_solong *map)
{
	if (c == 1)
	{
		free(map->tab);
		ft_putendl_fd("player not found or too many players", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	if (c == 2)
	{
		free(map->tab);
		ft_putendl_fd("Need 1 exit and collectible !", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
}
