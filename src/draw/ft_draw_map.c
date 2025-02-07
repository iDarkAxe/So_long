/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppontet <ppontet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 14:41:25 by ppontet           #+#    #+#             */
/*   Updated: 2025/01/18 19:02:17 by ppontet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "so_long.h"

static void	ft_draw_map_specials(t_map *map, t_mlx *mlx, size_t count,
				size_t count2);

void	ft_draw_map(t_mlx *mlx, t_map *map)
{
	size_t	count;
	size_t	count2;

	count = 0;
	count2 = 0;
	while (count < map->width)
	{
		count2 = 0;
		while (count2 < map->height + 1)
		{
			if (map->map[count2][count] == '1')
				mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr,
					map->textures.wall.ptr, (int)count * 64, (int)count2 * 64);
			else if (map->map[count2][count] == '0')
				mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr,
					map->textures.floor.ptr, (int)count * 64, (int)count2 * 64);
			else
				ft_draw_map_specials(map, mlx, count, count2);
			count2++;
		}
		count++;
	}
	return ;
}

static void	ft_draw_map_specials(t_map *map, t_mlx *mlx, size_t count,
		size_t count2)
{
	if (map->map[count2][count] == 'C')
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr,
			map->textures.collectible.ptr, (int)count * 64, (int)count2 * 64);
	else if (map->map[count2][count] == 'E')
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr,
			map->textures.exit_off.ptr, (int)count * 64, (int)count2 * 64);
}
