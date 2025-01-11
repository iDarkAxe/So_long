/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppontet <ppontet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 13:03:55 by ppontet           #+#    #+#             */
/*   Updated: 2025/01/11 12:48:25 by ppontet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "keys.h"
#include "mlx.h"
#include "so_long.h"
#include <stddef.h>
#include <stdlib.h>

void	*ft_settings(t_mlx *mlx_ptr);

int	so_long(void)
{
	t_mlx	mlx;

	mlx.mlx_ptr = mlx_init();
	if (mlx.mlx_ptr == NULL)
		return (1);
	mlx.win_settings_ptr = ft_settings(&mlx);
	if (mlx.win_ptr == NULL)
		return (1);
	mlx.win_ptr = mlx_new_window(mlx.mlx_ptr, 1000, 1000, "So_long");
	if (mlx.win_ptr == NULL)
		return (free(mlx.mlx_ptr), 1);
	mlx_hook(mlx.win_ptr, KeyPress, KeyPressMask, handle_keypress, NULL);
	mlx_hook(mlx.win_ptr, 17, 0, close_window, NULL);
	mlx_hook(mlx.win_ptr, MotionNotify, PointerMotionMask, \
		handle_mouse_motion, &mlx);
	mlx_loop(mlx.mlx_ptr);
	mlx_destroy_window(mlx.mlx_ptr, mlx.win_ptr);
	free(mlx.mlx_ptr);
	return (0);
}
