/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppontet <ppontet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 13:08:27 by ppontet           #+#    #+#             */
/*   Updated: 2025/01/11 12:15:43 by ppontet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

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
	void *win_settings_ptr;
} t_mlx;

int		so_long(void);

void	*ft_settings(t_mlx *mlx);

int		close_window(void *param);
void	ft_draw_rectangle(void *mlx_ptr, void *win_ptr, t_rectangle element);
void	ft_draw_circle(void *mlx_ptr, void *win_ptr, t_circle element);
int		handle_keypress(int keycode, void *param);
int		handle_mouse_motion(int x, int y, void *param);

#endif
