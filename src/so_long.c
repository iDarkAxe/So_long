/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppontet <ppontet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 13:03:55 by ppontet           #+#    #+#             */
/*   Updated: 2025/01/18 19:18:44 by ppontet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "keys.h"
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
		return ((void)write(1, "Error at check_borders\n", 23), -1);
	mlx.mlx_ptr = mlx_init();
	if (mlx.mlx_ptr == NULL)
		return (1);
	if (ft_store_textures(&mlx, map) == NULL)
		return ((void)free_map_textures(&mlx, map), -1);
	mlx.win_ptr = mlx_new_window(mlx.mlx_ptr, map->textures.wall.width
			* (int)map->width, map->textures.wall.width * ((int)map->height
				+ 1), "So_long");
	if (mlx.win_ptr == NULL)
		return ((void)ft_exit(mlx, map), -1);
	mlx_hook(mlx.win_ptr, DestroyNotify, StructureNotifyMask, close_window,
		(void *)&((t_store){&mlx, map}));
	mlx_hook(mlx.win_ptr, KeyPress, KeyPressMask, handle_keypress,
		(void *)&((t_store){&mlx, map}));
	ft_draw_map(&mlx, map);
	ft_draw_tile(&mlx, map->textures.player_fr, find_position(map, 'P'));
	mlx_loop(mlx.mlx_ptr);
	return ((void)ft_exit(mlx, map), 0);
}
