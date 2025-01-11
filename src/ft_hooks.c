/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hooks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppontet <ppontet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 16:59:19 by ppontet           #+#    #+#             */
/*   Updated: 2025/01/11 12:42:32 by ppontet          ###   ########lyon.fr   */
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
	if (keycode == KEY_ESCAPE)
		exit(0);
	return (keycode);
}

int	handle_mouse_motion(int x, int y, void *param)
{
	(void)param;
	printf("Pos: x,y(%d,%d)\n", x, y);
	return (0);
}
