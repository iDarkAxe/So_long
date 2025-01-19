/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppontet <ppontet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 17:05:47 by ppontet           #+#    #+#             */
/*   Updated: 2025/01/19 18:14:49 by ppontet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "keys.h"
#include "mlx.h"
#include "so_long.h"

__attribute__((deprecated))
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

__attribute__((deprecated))
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

void	ft_draw_tile(t_mlx *mlx, t_img img, t_coordinates coords)
{
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, img.ptr, img.width
		* (int)coords.x, img.height * (int)coords.y);
}

void	ft_draw_player(t_mlx *mlx, t_map *map, int facing,
		t_coordinates old_player_pos)
{
	t_coordinates	new_player_pos;

	new_player_pos = find_position(map, 'P');
	ft_draw_tile(mlx, map->textures.floor, old_player_pos);
	if (old_player_pos.x == map->exit.x && old_player_pos.y == map->exit.y)
		ft_draw_tile(mlx, map->textures.exit_off, old_player_pos);
	if (facing == KEY_RIGHT || facing == KEY_UP)
	{
		if (new_player_pos.x == map->exit.x && new_player_pos.y == map->exit.y)
			ft_draw_tile(mlx, map->textures.exit_off_fr, new_player_pos);
		else
			ft_draw_tile(mlx, map->textures.player_fr, new_player_pos);
	}
	else if (new_player_pos.x == map->exit.x && new_player_pos.y == map->exit.y)
		ft_draw_tile(mlx, map->textures.exit_off_fl, new_player_pos);
	else
		ft_draw_tile(mlx, map->textures.player_fl, new_player_pos);
}
