/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_store_textures.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppontet <ppontet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 10:39:29 by ppontet           #+#    #+#             */
/*   Updated: 2025/01/16 17:47:55 by ppontet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "so_long.h"

static void	*store_textures_part2(t_mlx *mlx, t_map *map);

void	*ft_store_textures(t_mlx *mlx, t_map *map)
{
	map->textures.wall.ptr = mlx_xpm_file_to_image(mlx->mlx_ptr,
			"img/stone_bricks_v2.xpm", &(map->textures.wall.width),
			&(map->textures.wall.height));
	if (map->textures.wall.ptr == NULL)
		return (NULL);
	map->textures.floor.ptr = mlx_xpm_file_to_image(mlx->mlx_ptr,
			"img/parquet_versailles.xpm", &(map->textures.floor.width),
			&(map->textures.floor.height));
	if (map->textures.floor.ptr == NULL)
		return (NULL);
	map->textures.exit.ptr = mlx_xpm_file_to_image(mlx->mlx_ptr, "img/exit.xpm",
			&(map->textures.exit.width), &(map->textures.exit.height));
	if (map->textures.exit.ptr == NULL)
		return (NULL);
	return (store_textures_part2(mlx, map));
}

static void	*store_textures_part2(t_mlx *mlx, t_map *map)
{
	map->textures.player_fr.ptr = mlx_xpm_file_to_image(mlx->mlx_ptr,
			"img/player_fr.xpm", &(map->textures.player_fr.width),
			&(map->textures.player_fr.height));
	if (map->textures.player_fr.ptr == NULL)
		return (NULL);
	map->textures.player_fl.ptr = mlx_xpm_file_to_image(mlx->mlx_ptr,
			"img/player_fl.xpm", &(map->textures.player_fl.width),
			&(map->textures.player_fl.height));
	if (map->textures.player_fl.ptr == NULL)
		return (NULL);
	return (map);
}
