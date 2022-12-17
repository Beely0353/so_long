/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baroun <baroun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 13:51:36 by baroun            #+#    #+#             */
/*   Updated: 2022/05/27 12:08:08 by baroun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define ESC 53
# define W_KEY 13
# define A_KEY 0
# define S_KEY 1
# define D_KEY 2
# define PXL 32

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <mlx.h>
# include <fcntl.h>
# include "../libft/libft.h"
# include <string.h>

typedef struct s_solong
{
	char	*player_right;
	char	*player_down;
	char	*player_left;
	char	*collectible;
	char	*player_up;
	char	*ground;
	char	*wall;
	char	*exit;
	char	**tab;

	void	*is_collectible;
	void	*is_ground;
	void	*is_player;
	void	*is_exit;
	void	*is_wall;
	void	*win;
	void	*mlx;

	int		screen_height;
	int		screen_width;
	int		line_max;
	int		count_line;
	int		nbr_collect;
	int		nbr_player;
	int		nbr_exit;
	int		move;
	int		nbr_x;
	int		nbr_y;
	int		x;
	int		y;
}	t_solong;

static void	check_move_right(t_solong *map);
static void	check_move_down(t_solong *map);
static void	check_move_left(t_solong *map);
static void	check_move_up(t_solong *map);
static void	texture_init(t_solong *map);

void		aff_map(t_solong *map, int y, int x);
void		return_error(int c, t_solong *map);
void		add_map(t_solong *map, char *av);
void		add_tab(t_solong *map, char *av);
void		move_and_collect(t_solong *map);
void		position_player(t_solong *map);
void		player_right(t_solong *map);
void		player_down(t_solong *map);
void		player_left(t_solong *map);
void		aff_ground(t_solong *map);
void		map_error(t_solong *map);
void		player_up(t_solong *map);
void		pars_map(t_solong *map);
void		map_init(t_solong *map);
void		free_tab(t_solong *map);
void		check_ext(char *av);
void		co_ex(t_solong *map);
void		file_error(int c);

int			check_move(t_solong *map, int x, int y);
int			key_assign(int key, t_solong *map);
int			exit_game(void);
#endif
