/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hooks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppontet <ppontet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 16:59:19 by ppontet           #+#    #+#             */
/*   Updated: 2025/01/13 18:34:10 by ppontet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "keys.h"
#include "so_long.h"
#include <unistd.h>
#include "ft_print.h"

//@TODO REMOVE
#include "so_long.h"
#include <stdio.h>
#include <stdlib.h>

int	close_window(void *param)
{
	(void)param;
	write(1, "Fermeture de la fenêtre.\n", 26);
	exit(0);
}

int	handle_keypress(int keycode, void *param)
{
	(void)param;
	write(1, "Key pressed: ", 13);
	ft_putnbr_fd(keycode, 1);
	write(1, "\n", 1);
	if (keycode == 53)
		exit(0);
	if (keycode == KEY_ESCAPE)
		exit(0);
	return (keycode);
}

int	handle_mouse_motion(int x, int y, void *param)
{
	(void)param;
	ft_print_position(x, y);
	return (0);
}
