/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_up.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baroun <baroun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 12:05:32 by baroun            #+#    #+#             */
/*   Updated: 2022/05/27 12:10:13 by baroun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static void	check_move_up(t_solong *map)
{
	if (check_move(map, map->nbr_y, map->nbr_x) == 3)
	{
		map->nbr_collect--;
		map->tab[map->nbr_y][map->nbr_x] = 'P';
		map->tab[map->nbr_y + 1][map->nbr_x] = '0';
	}
	else if (check_move(map, map->nbr_y, map->nbr_x) == 2 && !map->nbr_collect)
	{
		free_tab(map);
		exit(EXIT_SUCCESS);
	}
	else if (map->tab[map->nbr_y + 1][map->nbr_x] != 'E' &&
		map->tab[map->nbr_y][map->nbr_x] != 'E')
	{
		map->tab[map->nbr_y][map->nbr_x] = 'P';
		map->tab[map->nbr_y + 1][map->nbr_x] = '0';
	}
	map->is_player = mlx_xpm_file_to_image(map->mlx, map->player_up,
			&map->screen_width, &map->screen_height);
}

void	player_up(t_solong *map)
{
	map->nbr_y--;
	if (check_move(map, map->nbr_y, map->nbr_x) == 2
		&& map->nbr_collect)
		map->nbr_y++;
	else if (check_move(map, map->nbr_y, map->nbr_x) == 0)
		map->nbr_y++;
	else if (check_move(map, map->nbr_y, map->nbr_x))
	{
		check_move_up(map);
		pars_map(map);
		map->move++;
		move_and_collect(map);
	}
}
