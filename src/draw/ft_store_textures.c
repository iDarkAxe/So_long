/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_store_textures.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppontet <ppontet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 10:39:29 by ppontet           #+#    #+#             */
/*   Updated: 2025/01/15 12:02:01 by ppontet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "so_long.h"

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
	return (map);
}
