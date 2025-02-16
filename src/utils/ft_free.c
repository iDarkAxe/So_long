/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppontet <ppontet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 18:09:09 by ppontet           #+#    #+#             */
/*   Updated: 2025/01/20 12:15:47 by ppontet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdlib.h>
#include "mlx.h"

static void	free_map_textures_exit(t_mlx *mlx, t_map *map);
static void	free_map_textures_player(t_mlx *mlx, t_map *map);

void	free_map(t_map *map, char **map_to_delete, size_t len)
{
	size_t	i;

	i = 0;
	if (map == NULL)
		return ;
	while (i < (len + 1) && i < (map->height + 1))
	{
		if (map_to_delete[i])
		{
			free(map_to_delete[i]);
			map_to_delete[i] = NULL;
		}
		i++;
	}
	if (map_to_delete != NULL)
	{
		free(map_to_delete);
		map_to_delete = NULL;
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
	free_map_textures_exit(mlx, map);
	free_map(map, map->map, map->height);
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

static void	free_map_textures_exit(t_mlx *mlx, t_map *map)
{
	if (map->textures.exit_on.ptr != NULL)
	{
		mlx_destroy_image(mlx->mlx_ptr, map->textures.exit_on.ptr);
		map->textures.exit_on.ptr = NULL;
	}
	if (map->textures.exit_off.ptr != NULL)
	{
		mlx_destroy_image(mlx->mlx_ptr, map->textures.exit_off.ptr);
		map->textures.exit_off.ptr = NULL;
	}
	if (map->textures.exit_off_fl.ptr != NULL)
	{
		mlx_destroy_image(mlx->mlx_ptr, map->textures.exit_off_fl.ptr);
		map->textures.exit_off_fl.ptr = NULL;
	}
	if (map->textures.exit_off_fr.ptr != NULL)
	{
		mlx_destroy_image(mlx->mlx_ptr, map->textures.exit_off_fr.ptr);
		map->textures.exit_off_fr.ptr = NULL;
	}
}
