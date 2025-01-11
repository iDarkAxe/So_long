/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppontet <ppontet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 17:05:47 by ppontet           #+#    #+#             */
/*   Updated: 2025/01/11 11:55:23 by ppontet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "so_long.h"

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
	for (int y = -element.radius; y <= element.radius; y++)
	{
		for (int x = -element.radius; x <= element.radius; x++)
		{
			if (x * x + y * y <= element.radius * element.radius)
				mlx_pixel_put(mlx_ptr, win_ptr, element.x + x,
					element.y + y, element.color);
		}
	}
}
