/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppontet <ppontet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 13:03:55 by ppontet           #+#    #+#             */
/*   Updated: 2025/04/06 13:25:12 by ppontet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_keys.h"
#include "mlx.h"
#include "so_long.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * @brief Main function of the so_long project
 *
 * @param argc number of arguments
 * @param argv array of string arguments
 * @return int 0 if the program ends correctly, -1 otherwise
 */
int	so_long(int argc, char **argv)
{
	t_map	*map;
	t_mlx	mlx;

	(void)argc;
	map = check_borders(dimensions_verif(argv[1]));
	if (map == NULL || map->map == NULL || map->error == -1)
		return ((void)write(2, "Error\nAt check_borders\n", 23), -1);
	mlx.mlx_ptr = mlx_init();
	if (mlx.mlx_ptr == NULL)
		return (ft_exit(mlx, map), (void)write(2, "Error\nInit MLX\n", 14), -1);
	if (ft_store_textures(&mlx, map) == NULL)
		return ((void)free_map_textures(&mlx, map), -1);
	mlx.win_ptr = mlx_new_window(mlx.mlx_ptr, map->textures.wall.width
			* (int)map->width, map->textures.wall.width * ((int)map->height
				+ 1), "So_long");
	if (mlx.win_ptr == NULL)
		return ((void)write(2, "Error\n", 7), (void)ft_exit(mlx, map), -1);
	mlx_hook(mlx.win_ptr, DestroyNotify, StructureNotifyMask, close_window,
		(void *)&mlx);
	mlx_hook(mlx.win_ptr, KeyPress, KeyPressMask, handle_keypress,
		(void *)&((t_store){&mlx, map}));
	ft_draw_map(&mlx, map);
	ft_draw_tile(&mlx, map->textures.player_fr, find_position(map, 'P'));
	mlx_loop(mlx.mlx_ptr);
	return ((void)ft_exit(mlx, map), 0);
}
