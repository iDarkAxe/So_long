/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppontet <ppontet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 14:41:25 by ppontet           #+#    #+#             */
/*   Updated: 2025/01/16 17:31:22 by ppontet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "so_long.h"

void	ft_draw_map(t_map *map, t_mlx *mlx)
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
					map->textures.floor.ptr, (int)count * 64, (int)count2
					* 64);
			else if (map->map[count2][count] == 'E')
				mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr,
					map->textures.exit.ptr, (int)count * 64, (int)count2 * 64);
			count2++;
		}
		count++;
	}
	return ;
}
