/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baroun <baroun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 12:06:56 by baroun            #+#    #+#             */
/*   Updated: 2022/05/27 12:07:00 by baroun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	check_move(t_solong *map, int x, int y)
{
	if (map->tab[x][y] == '0' || map->tab[x][y] == 'P')
		return (1);
	else if (map->tab[x][y] == 'E')
		return (2);
	else if (map->tab[x][y] == 'C')
		return (3);
	return (0);
}

void	move_and_collect(t_solong *map)
{
	write(STDOUT_FILENO, "move :", 6);
	ft_putnbr_fd(map->move, STDOUT_FILENO);
	write(STDOUT_FILENO, "\n", 1);
	write(STDOUT_FILENO, "collectible :", 13);
	ft_putnbr_fd(map->nbr_collect, STDOUT_FILENO);
	write(STDOUT_FILENO, "\n", 1);
}

int	key_assign(int key, t_solong *map)
{
	if (key == ESC)
		exit(0);
	if (key == W_KEY)
		player_up(map);
	if (key == A_KEY)
		player_left(map);
	if (key == S_KEY)
		player_down(map);
	if (key == D_KEY)
		player_right(map);
	return (0);
}
