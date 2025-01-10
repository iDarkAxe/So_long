/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppontet <ppontet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 13:08:27 by ppontet           #+#    #+#             */
/*   Updated: 2025/01/10 17:41:11 by ppontet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

typedef struct s_element
{
	int	x;
	int	y;
	int	width;
	int	height;
	int	color;
}	t_element;

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
}	t_mlx;

int 	so_long(void);

void 	*ft_settings(void *mlx_ptr);

int 	close_window(void *param);
void 	ft_draw_rectangle(void *mlx_ptr, void *win_ptr, t_element element);
int 	handle_keypress(int keycode, void *param);
int 	handle_mouse_motion(int x, int y, void *param);

#endif
