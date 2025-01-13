/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppontet <ppontet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 17:05:47 by ppontet           #+#    #+#             */
/*   Updated: 2025/01/12 14:25:39 by ppontet          ###   ########lyon.fr   */
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
	int	y;
	int	x;

	y = -element.radius;
	x = -element.radius;
	while (y <= element.radius)
	{
		while (x <= element.radius)
		{
			if (x * x + y * y <= element.radius * element.radius)
				mlx_pixel_put(mlx_ptr, win_ptr, element.x + x,
					element.y + y, element.color);
			x++;
		}
		y++;
	}
}
