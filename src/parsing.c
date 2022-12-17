/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baroun <baroun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 12:07:06 by baroun            #+#    #+#             */
/*   Updated: 2022/05/27 12:07:14 by baroun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	co_ex(t_solong *map)
{
	int	a;
	int	b;

	a = 0;
	map->nbr_exit = 0;
	map->nbr_collect = 0;
	while (map->tab[a])
	{
		b = 0;
		while (map->tab[a][b])
		{
			if (map->tab[a][b] == 'C')
				map->nbr_collect++;
			else if (map->tab[a][b] == 'E')
				map->nbr_exit++;
			b++;
		}
		a++;
	}
	if (map->nbr_exit <= 0 || map->nbr_collect <= 0)
		return_error(2, map);
}

void	position_player(t_solong *map)
{
	int	i;
	int	a;

	i = 0;
	map->nbr_x = 0;
	map->nbr_y = 0;
	map->nbr_player = 0;
	while (map->tab[i])
	{
		a = 0;
		while (map->tab[i][a])
		{
			if (map->tab[i][a] == 'P')
			{
				map->nbr_x += a;
				map->nbr_y += i;
				map->nbr_player++;
			}
			a++;
		}
		i++;
	}
	if (map->nbr_player <= 0 || map->nbr_player > 1)
		return_error(1, map);
}
