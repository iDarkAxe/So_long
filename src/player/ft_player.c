/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_player.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppontet <ppontet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 17:40:28 by ppontet           #+#    #+#             */
/*   Updated: 2025/01/16 17:52:30 by ppontet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "keys.h"

static int	ft_collectibles_handler(t_map *map, t_coordinates new_pos)
{
	if (map->collectibles == 0 && map->exit.x == new_pos.x
		&& map->exit.y == new_pos.y)
		return (0);
	if (map->map[new_pos.y][new_pos.x] == 'C')
		map->collectibles--;
	map->map[new_pos.y][new_pos.x] = 'P';
	return (1);
}

void	can_player_move(t_map *map, t_mlx *mlx, int direction)
{
	t_coordinates	player;
	t_coordinates	new_pos;

	player = find_position(map, 'P');
	map->map[player.y][player.x] = 'p';
	if (direction == KEY_RIGHT && map->map[player.y][player.x + 1] != '1')
		new_pos = (t_coordinates){player.x + 1, player.y};
	else if (direction == KEY_LEFT && map->map[player.y][player.x - 1] != '1')
		new_pos = (t_coordinates){player.x - 1, player.y};
	else if (direction == KEY_DOWN && map->map[player.y + 1][player.x] != '1')
		new_pos = (t_coordinates){player.x, player.y + 1};
	else if (direction == KEY_UP && map->map[player.y - 1][player.x] != '1')
		new_pos = (t_coordinates){player.x, player.y - 1};
	else
	{
		map->map[player.y][player.x] = 'P';
		return ;
	}
	if (ft_collectibles_handler(map, new_pos) == 0)
		close_window((void *)mlx);
	ft_draw_player(map, mlx, direction);
	map->map[player.y][player.x] = '0';
}
