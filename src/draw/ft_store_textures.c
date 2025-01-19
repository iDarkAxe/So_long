/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_store_textures.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppontet <ppontet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 10:39:29 by ppontet           #+#    #+#             */
/*   Updated: 2025/01/19 17:51:30 by ppontet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "so_long.h"

static void	*store_textures_player(t_mlx *mlx, t_map *map);
static void	*store_textures_exit(t_mlx *mlx, t_map *map);

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
	if (store_textures_exit(mlx, map) == NULL)
		return (NULL);
	map->textures.collectible.ptr = mlx_xpm_file_to_image(mlx->mlx_ptr,
			"img/eye_of_ender.xpm", &(map->textures.collectible.width),
			&(map->textures.collectible.height));
	if (map->textures.collectible.ptr == NULL)
		return (NULL);
	return (store_textures_player(mlx, map));
}

static void	*store_textures_player(t_mlx *mlx, t_map *map)
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

static void	*store_textures_exit(t_mlx *mlx, t_map *map)
{
	map->textures.exit_on.ptr = mlx_xpm_file_to_image(mlx->mlx_ptr,
			"img/end_portal_on.xpm", &(map->textures.exit_on.width),
			&(map->textures.exit_on.height));
	if (map->textures.exit_on.ptr == NULL)
		return (NULL);
	map->textures.exit_off.ptr = mlx_xpm_file_to_image(mlx->mlx_ptr,
			"img/end_portal_off.xpm",
			&(map->textures.exit_off.width),
			&(map->textures.exit_off.height));
	if (map->textures.exit_off.ptr == NULL)
		return (NULL);
	map->textures.exit_off_fl.ptr = mlx_xpm_file_to_image(mlx->mlx_ptr,
			"img/player_fl_end_portal_off.xpm",
			&(map->textures.exit_off_fl.width),
			&(map->textures.exit_off_fl.height));
	if (map->textures.exit_off_fl.ptr == NULL)
		return (NULL);
	map->textures.exit_off_fr.ptr = mlx_xpm_file_to_image(mlx->mlx_ptr,
			"img/player_fr_end_portal_off.xpm",
			&(map->textures.exit_off_fr.width),
			&(map->textures.exit_off_fr.height));
	if (map->textures.exit_off_fr.ptr == NULL)
		return (NULL);
	return (map);
}
