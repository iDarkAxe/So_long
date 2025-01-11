/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppontet <ppontet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 13:03:55 by ppontet           #+#    #+#             */
/*   Updated: 2025/01/11 22:27:26 by ppontet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "keys.h"
#include "mlx.h"
#include "so_long.h"
#include <stddef.h>
#include <stdlib.h>

void	*ft_settings(t_mlx *mlx_ptr);

typedef struct s_map_size
{
	int	line_len;
	int	prev_line_len;
	int	count_line;
}		t_map_size;

#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int	dimensions_verif(char *map_name)
{
	int			fd;
	char		line[1];
	int			ret;
	t_map_size	map;

	fd = open(map_name, O_RDONLY);
	if (fd == -1)
		return (1);
	map.line_len = 0;
	map.prev_line_len = 0;
	map.count_line = 0;
	while (1)
	{
		ret = read(fd, line, 1);
		if (ret == -1)
			return ((void)printf("Error\n"), -1);
		if (ret == 0)
		{
			if (map.line_len != map.prev_line_len)
				return ((void)printf("Error\n"), -1);
			break ;
		}
		if (line[0] != '\n')
			map.line_len++;
		else if (line[0] == '\n')
		{
			if (map.count_line == 0)
				map.prev_line_len = map.line_len;
			else if (map.line_len != map.prev_line_len)
				return ((void)printf("Error\n"), -1);
			map.line_len = 0;
			map.count_line++;
		}
		printf("%s", line);
	}
	close(fd);
	return (map.count_line);
}

int	so_long(int argc, char **argv)
{
	if (argc != 2)
	{
		if (dimensions_verif("exemple.ber") == -1)
			return (-1);
	}
	else if (dimensions_verif(argv[1]) == -1)
		return (-1);
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
