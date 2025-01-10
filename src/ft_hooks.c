/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hooks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppontet <ppontet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 16:59:19 by ppontet           #+#    #+#             */
/*   Updated: 2025/01/10 17:48:40 by ppontet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "keys.h"
#include "so_long.h"

//@TODO REMOVE
#include "so_long.h"
#include <stdio.h>
#include <stdlib.h>

int	close_window(void *param)
{
	(void)param;
	printf("Fermeture de la fenêtre.\n");
	exit(0);
}

int	handle_keypress(int keycode, void *param)
{
	(void)param;
	printf("keycode here: %d\n", keycode);
	if (keycode == 53)
		exit(0);
	return (keycode);
}

int	handle_mouse_motion(int x, int y, void *param)
{
	(void)param;
	printf("Position du curseur : x = %d, y = %d\n", x, y);
	ft_draw_rectangle(((t_mlx *)param)->mlx_ptr, ((t_mlx *)param)->win_ptr,
		(t_element){100, 100, 50, 50, 0xFFAA00});
	return (0);
}
