/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hooks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppontet <ppontet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 16:59:19 by ppontet           #+#    #+#             */
/*   Updated: 2025/01/14 11:33:17 by ppontet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "keys.h"
#include "so_long.h"
#include <unistd.h>
#include "ft_print.h"

//@TODO REMOVE OR FIND ALTERNATIVE ?
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
	ft_print_keycode(keycode);
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
