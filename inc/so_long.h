/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppontet <ppontet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 13:08:27 by ppontet           #+#    #+#             */
/*   Updated: 2025/01/13 18:33:40 by ppontet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stddef.h>
# include <unistd.h>

typedef struct s_rectangle
{
	int		x;
	int		y;
	int		width;
	int		height;
	int		color;
}			t_rectangle;

typedef struct s_circle
{
	int		x;
	int		y;
	int		radius;
	int		color;
}			t_circle;

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*win_settings_ptr;
}			t_mlx;

int			so_long(int argc, char **argv);

void		*ft_settings(t_mlx *mlx);

int			close_window(void *param);
void		ft_draw_rectangle(void *mlx_ptr, void *win_ptr,
				t_rectangle element);
void		ft_draw_circle(void *mlx_ptr, void *win_ptr, t_circle element);
int			handle_keypress(int keycode, void *param);
int			handle_mouse_motion(int x, int y, void *param);

// MAP VERIF functions
typedef struct s_map_size
{
	int		fd;
	char	*map_name;
	size_t	line_len;
	size_t	prev_line_len;
	size_t	count_line;
	int		error_occured;
}			t_map_size;

typedef struct s_map
{
	char	**map;
	int		error;
	size_t	width;
	size_t	height;
}			t_map;

t_map_size	dimensions_verif(char *map_name);
t_map		*check_borders(t_map_size map_size);
t_map		*fill_map(t_map_size map_size, t_map *map);
void		free_map(t_map *map, size_t len);

// PRINT functions
ssize_t ft_print_position(int x, int y);

#endif
