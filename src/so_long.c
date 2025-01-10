/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppontet <ppontet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 13:03:55 by ppontet           #+#    #+#             */
/*   Updated: 2025/01/10 17:48:34 by ppontet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "keys.h"
#include "mlx.h"
#include "so_long.h"
#include <stddef.h>
#include <stdlib.h>

void	*ft_settings(void *mlx_ptr);

int	so_long(void)
{
	void	*mlx_ptr;
	void	*win_ptr;

	mlx_ptr = mlx_init();
	if (mlx_ptr == NULL)
		return (1);
	win_ptr = ft_settings(mlx_ptr);
	if (win_ptr == NULL)
		return (1);
	win_ptr = mlx_new_window(mlx_ptr, 1000, 1000, "So_long");
	if (win_ptr == NULL)
		return (free(mlx_ptr), 1);
	mlx_hook(win_ptr, KeyPress, KeyPressMask, handle_keypress, NULL);
	mlx_hook(win_ptr, 17, 0, close_window, NULL);
	mlx_hook(win_ptr, MotionNotify, PointerMotionMask, \
		handle_mouse_motion, (t_mlx *){mlx_ptr, win_ptr});
	mlx_loop(mlx_ptr);
	mlx_destroy_window(mlx_ptr, win_ptr);
	free(mlx_ptr);
	return (0);
}
