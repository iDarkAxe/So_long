/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppontet <ppontet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 14:37:50 by ppontet           #+#    #+#             */
/*   Updated: 2025/01/15 14:48:19 by ppontet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx.h"
#include <stdlib.h>

void	ft_exit(t_mlx mlx, t_map *map)
{
	free_map_textures(&mlx, map);
	if (mlx.mlx_ptr != NULL && mlx.win_ptr != NULL)
		mlx_destroy_window(mlx.mlx_ptr, mlx.win_ptr);
	mlx.win_ptr = NULL;
	if (mlx.mlx_ptr != NULL)
		mlx_destroy_display(mlx.mlx_ptr);
	free(mlx.mlx_ptr);
	mlx.win_ptr = NULL;
}
