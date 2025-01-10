/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_settings.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppontet <ppontet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 16:55:13 by ppontet           #+#    #+#             */
/*   Updated: 2025/01/10 17:15:04 by ppontet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "keys.h"
#include "mlx.h"
#include "so_long.h"
#include <stddef.h>

//@TODO REMOVE
#include <stdio.h>
#include <stdlib.h>

int	handle_keypress_settings(int keycode, void *param)
{
	(void)param;
	printf("keycode: %d\n", keycode);
	return (keycode);
}

void	*ft_settings(void *mlx_ptr)
{
	int		img_width;
	int		img_height;
	void	*img_ptr;
	void	*win_ptr;

	img_ptr = mlx_xpm_file_to_image(mlx_ptr, "img/settings.xpm", &img_width,
			&img_height);
	win_ptr = mlx_new_window(mlx_ptr, 500, 500, "Settings");
	if (win_ptr == NULL)
	{
		free(mlx_ptr);
		return (NULL);
	}
	if (img_ptr == NULL)
	{
		free(mlx_ptr);
		return (NULL);
	}
	mlx_put_image_to_window(mlx_ptr, win_ptr, img_ptr, 0, 0);
	ft_draw_rectangle(mlx_ptr, win_ptr, \
		(t_element){100, 100, 50, 50, 0xFFAA00});
	mlx_hook(win_ptr, KeyPress, KeyPressMask, handle_keypress_settings, NULL);
	mlx_hook(win_ptr, 17, 0, close_window, NULL);
	return (win_ptr);
}

int	ft_screen_size(void *mlx_ptr)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	mlx_get_screen_size(mlx_ptr, &x, &y);
	mlx_new_window(mlx_ptr, x, y, "So_long");
	return (0);
}
