/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppontet <ppontet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 13:03:55 by ppontet           #+#    #+#             */
/*   Updated: 2025/01/13 16:50:57 by ppontet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "keys.h"
#include "mlx.h"
#include "so_long.h"
#include <stddef.h>
#include <stdlib.h>

// @TODO TO REMOVE
#include <stdio.h>

int	so_long(int argc, char **argv)
{
	t_map	*map;

	(void)argc;
	map = check_borders(dimensions_verif(argv[1]));
	if (map == NULL || map->map == NULL || map->error == -1)
	{
		printf("Error at check_borders\n");
		return (-1);
	}
	return (0);
}

// int	so_long(void)
// {
// 	t_mlx	mlx;

// 	mlx.mlx_ptr = mlx_init();
// 	if (mlx.mlx_ptr == NULL)
// 		return (1);
// 	mlx.win_settings_ptr = ft_settings(&mlx);
// 	if (mlx.win_settings_ptr == NULL)
// 		return (1);
// 	mlx.win_ptr = mlx_new_window(mlx.mlx_ptr, 1000, 1000, "So_long");
// 	if (mlx.win_ptr == NULL)
// 		return (free(mlx.mlx_ptr), 1);
// 	mlx_hook(mlx.win_ptr, KeyPress, KeyPressMask, handle_keypress, NULL);
// 	mlx_hook(mlx.win_ptr, 17, 0, close_window, NULL);
// 	mlx_hook(mlx.win_ptr, MotionNotify, PointerMotionMask,
// 		handle_mouse_motion, &mlx);
// 	mlx_loop(mlx.mlx_ptr);
// 	mlx_destroy_window(mlx.mlx_ptr, mlx.win_ptr);
// 	free(mlx.mlx_ptr);
// 	return (0);
// }
