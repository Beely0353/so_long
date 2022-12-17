/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_right.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baroun <baroun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 12:07:33 by baroun            #+#    #+#             */
/*   Updated: 2022/05/27 12:07:37 by baroun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static void	check_move_right(t_solong *map)
{
	if (check_move(map, map->nbr_y, map->nbr_x) == 3)
	{
		map->nbr_collect--;
		map->tab[map->nbr_y][map->nbr_x] = 'P';
		map->tab[map->nbr_y][map->nbr_x - 1] = '0';
	}
	else if (check_move(map, map->nbr_y, map->nbr_x) == 2 && !map->nbr_collect)
	{
		free_tab(map);
		exit(EXIT_SUCCESS);
	}
	if (map->tab[map->nbr_y][map->nbr_x - 1] != 'E' &&
		map->tab[map->nbr_y][map->nbr_x] != 'E')
	{
		map->tab[map->nbr_y][map->nbr_x] = 'P';
		map->tab[map->nbr_y][map->nbr_x - 1] = '0';
	}
	map->is_player = mlx_xpm_file_to_image(map->mlx, map->player_right,
			&map->screen_width, &map->screen_height);
}

void	player_right(t_solong *map)
{
	map->nbr_x++;
	if (check_move(map, map->nbr_y, map->nbr_x) == 2
		&& map->nbr_collect)
		map->nbr_x--;
	else if (check_move(map, map->nbr_y, map->nbr_x) == 0)
		map->nbr_x--;
	else if (check_move(map, map->nbr_y, map->nbr_x))
	{
		check_move_right(map);
		pars_map(map);
		map->move++;
		move_and_collect(map);
	}
}
