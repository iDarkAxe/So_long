/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppontet <ppontet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 17:05:47 by ppontet           #+#    #+#             */
/*   Updated: 2025/01/16 17:52:08 by ppontet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "so_long.h"
#include "keys.h"

void	ft_draw_rectangle(void *mlx_ptr, void *win_ptr, t_rectangle element)
{
	int	x;
	int	y;

	x = 0;
	while (x < element.width)
	{
		y = 0;
		while (y < element.height)
		{
			mlx_pixel_put(mlx_ptr, win_ptr, element.x + x, element.y + y++,
				element.color);
		}
		x++;
	}
}

void	ft_draw_circle(void *mlx_ptr, void *win_ptr, t_circle element)
{
	int	y;
	int	x;

	y = -element.radius;
	x = -element.radius;
	while (y <= element.radius)
	{
		while (x <= element.radius)
		{
			if (x * x + y * y <= element.radius * element.radius)
				mlx_pixel_put(mlx_ptr, win_ptr, element.x + x, element.y + y,
					element.color);
			x++;
		}
		y++;
	}
}

void	ft_draw_tile(t_mlx *mlx, t_map *map, t_img img, t_coordinates coords)
{
	if (coords.x == map->exit.x && coords.y == map->exit.y)
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr,
			map->textures.exit.ptr, map->textures.exit.width * (int)coords.x,
			map->textures.exit.height * (int)coords.y);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, img.ptr, img.width
		* (int)coords.x, img.height * (int)coords.y);
}

void	ft_draw_player(t_map *map, t_mlx *mlx, int facing)
{
	ft_draw_tile(mlx, map, map->textures.floor, find_position(map, 'p'));
	if (facing == KEY_RIGHT || facing == KEY_UP)
		ft_draw_tile(mlx, map, map->textures.player_fr, find_position(map,
				'P'));
	else
		ft_draw_tile(mlx, map, map->textures.player_fl, find_position(map,
				'P'));
}
