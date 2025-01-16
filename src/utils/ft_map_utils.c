/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppontet <ppontet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 16:46:13 by ppontet           #+#    #+#             */
/*   Updated: 2025/01/16 17:50:37 by ppontet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdlib.h>
#include "mlx.h"

static void	free_map_textures_player(t_mlx *mlx, t_map *map);

int	find_max_collectibles(t_map *map)
{
	int		collectibles;
	size_t	x;
	size_t	y;

	collectibles = 0;
	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (map->map[y][x] == 'C')
				collectibles++;
			x++;
		}
		y++;
	}
	return (collectibles);
}

t_coordinates	find_position(t_map *map, char character)
{
	t_coordinates	player;

	player.y = 0;
	while (player.y < map->height && map->map[player.y] != NULL)
	{
		player.x = 0;
		while (player.x < map->width && map->map[player.y][player.x] != '\0')
		{
			if (map->map[player.y][player.x] == character)
				break ;
			player.x++;
		}
		if (map->map[player.y][player.x] == character)
			break ;
		player.y++;
	}
	return (player);
}

void	free_map(t_map *map, size_t len)
{
	size_t	i;

	i = 0;
	if (map == NULL)
		return ;
	while (i < (len + 1) && i < (map->height + 1))
	{
		if (map->map[i])
		{
			free(map->map[i]);
			map->map[i] = NULL;
		}
		i++;
	}
	if (map->map != NULL)
	{
		free(map->map);
		map->map = NULL;
	}
	free(map);
	map = NULL;
}

void	free_map_textures(t_mlx *mlx, t_map *map)
{
	if (map == NULL)
		return ;
	if (map->textures.collectible.ptr != NULL)
	{
		mlx_destroy_image(mlx->mlx_ptr, map->textures.collectible.ptr);
		map->textures.collectible.ptr = NULL;
	}
	if (map->textures.floor.ptr != NULL)
	{
		mlx_destroy_image(mlx->mlx_ptr, map->textures.floor.ptr);
		map->textures.floor.ptr = NULL;
	}
	if (map->textures.wall.ptr != NULL)
	{
		mlx_destroy_image(mlx->mlx_ptr, map->textures.wall.ptr);
		map->textures.wall.ptr = NULL;
	}
	free_map_textures_player(mlx, map);
	free_map(map, map->height);
}

static void	free_map_textures_player(t_mlx *mlx, t_map *map)
{
	if (map->textures.player_fr.ptr != NULL)
	{
		mlx_destroy_image(mlx->mlx_ptr, map->textures.player_fr.ptr);
		map->textures.player_fr.ptr = NULL;
	}
	if (map->textures.player_fl.ptr != NULL)
	{
		mlx_destroy_image(mlx->mlx_ptr, map->textures.player_fl.ptr);
		map->textures.player_fl.ptr = NULL;
	}
}
