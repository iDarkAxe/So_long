/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppontet <ppontet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 16:46:13 by ppontet           #+#    #+#             */
/*   Updated: 2025/01/15 13:39:58 by ppontet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdlib.h>
#include "mlx.h"

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
	if (map->textures.player.ptr != NULL)
	{
		mlx_destroy_image(mlx->mlx_ptr, map->textures.player.ptr);
		map->textures.player.ptr = NULL;
	}
	free_map(map, map->height);
}
