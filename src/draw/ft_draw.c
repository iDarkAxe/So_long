/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppontet <ppontet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 17:05:47 by ppontet           #+#    #+#             */
/*   Updated: 2025/01/10 17:20:13 by ppontet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "so_long.h"

void	ft_draw_rectangle(void *mlx_ptr, void *win_ptr, t_element element)
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
