/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppontet <ppontet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 14:41:25 by ppontet           #+#    #+#             */
/*   Updated: 2025/01/14 18:44:32 by ppontet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "so_long.h"
#include <stdio.h>

void	ft_draw_map(t_map *map, t_mlx *mlx)
{
	size_t	count;
	size_t	count2;
	t_img	img;
	t_img	img2;

	img = (t_img){NULL, 0, 0};
	img2 = (t_img){NULL, 0, 0};
	count = 0;
	img.ptr = mlx_xpm_file_to_image(mlx->mlx_ptr, "img/stone_bricks_v2.xpm",
			&img.width, &img.height);
	if (img.ptr == NULL)
		return ;
	img2.ptr = mlx_xpm_file_to_image(mlx->mlx_ptr, "img/stone_bricks.xpm",
			&img2.width, &img2.height);
	if (img2.ptr == NULL)
		return ;
	count2 = 0;
	while (count < map->width)
	{
		count2 = 0;
		while (count2 < map->height)
		{
			mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, img.ptr, (int)count
				* 64, (int)count2 * 64);
			count2++;
		}
		count++;
	}
	return ;
}
