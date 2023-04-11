/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_left.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biaroun <biaroun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 12:36:41 by biaroun           #+#    #+#             */
/*   Updated: 2023/04/06 16:47:37 by biaroun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static void	check_move_left(t_solong *map)
{
	if (check_move(map, map->nbr_y, map->nbr_x) == 3)
	{
		map->nbr_collect--;
		map->tab[map->nbr_y][map->nbr_x] = 'P';
		map->tab[map->nbr_y][map->nbr_x + 1] = '0';
	}
	else if (check_move(map, map->nbr_y, map->nbr_x) == 2 && !map->nbr_collect)
	{
		free_tab(map->tab);
		exit(EXIT_SUCCESS);
	}
	else if (check_move(map, map->nbr_y, map->nbr_x) == 2 && map->nbr_collect)
	{
		map->tab[map->nbr_y][map->nbr_x] = 'P';
		map->tab[map->nbr_y][map->nbr_x + 1] = '0';
	}
	if (map->tab[map->nbr_y][map->nbr_x + 1] != 'E' &&
		map->tab[map->nbr_y][map->nbr_x] != 'E')
	{
		map->tab[map->nbr_y][map->nbr_x] = 'P';
		map->tab[map->nbr_y][map->nbr_x + 1] = '0';
	}
	map->is_player = mlx_xpm_file_to_image(map->mlx, map->player_left,
			&map->screen_width, &map->screen_height);
}

void	player_left(t_solong *map)
{
	map->nbr_x--;
	if (check_move(map, map->nbr_y, map->nbr_x) == 0)
		map->nbr_x++;
	else if (check_move(map, map->nbr_y, map->nbr_x))
	{
		check_move_left(map);
		pars_map(map);
		map->move++;
		move_and_collect(map);
	}
}
