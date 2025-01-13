/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppontet <ppontet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 16:46:13 by ppontet           #+#    #+#             */
/*   Updated: 2025/01/13 18:03:36 by ppontet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdlib.h>

void	free_map(t_map *map, size_t len)
{
	size_t	i;

	i = 0;
	while (i < map->height && i < len)
		free(map->map[i++]);
	free(map->map);
}
