/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppontet <ppontet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 13:08:27 by ppontet           #+#    #+#             */
/*   Updated: 2025/01/15 12:01:36 by ppontet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stddef.h>
# include <unistd.h>

// MAIN functions

typedef struct s_img
{
	void	*ptr;
	int		width;
	int		height;
}			t_img;

typedef struct s_textures
{
	t_img	wall;
	t_img	floor;
	t_img	player;
	t_img	collectible;
}			t_textures;
typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*win_settings_ptr;
}			t_mlx;

typedef struct s_map
{
	char		**map;
	int			error;
	size_t		width;
	size_t		height;
	t_textures	textures;
}			t_map;

int			so_long(int argc, char **argv);

void		*ft_settings(t_mlx *mlx);
int			close_window(void *param);
void		free_map_textures(t_mlx mlx, t_map *map);
// DRAW functions
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

void		ft_draw_rectangle(void *mlx_ptr, void *win_ptr,
				t_rectangle element);
void		ft_draw_circle(void *mlx_ptr, void *win_ptr, t_circle element);
void		ft_draw_map(t_map *map, t_mlx *mlx);
void		*ft_store_textures(t_mlx *mlx, t_map *map);

// HOOKS functions
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

t_map_size	dimensions_verif(char *map_name);
t_map		*check_borders(t_map_size map_size);
t_map		*fill_map(t_map_size map_size, t_map *map);
void		free_map(t_map *map, size_t len);

// PRINT functions
ssize_t		ft_print_position(int x, int y);
ssize_t		ft_print_keycode(int keycode);
ssize_t		ft_print_color(int color);
ssize_t		ft_print_map(t_map *map);

// RANDOM functions
int			ft_random(int fd);
int			ft_random_init(void);

#endif
