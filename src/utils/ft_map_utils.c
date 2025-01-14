/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppontet <ppontet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 16:46:13 by ppontet           #+#    #+#             */
/*   Updated: 2025/01/14 10:45:46 by ppontet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdlib.h>

void	free_map(t_map *map, size_t len)
{
	size_t	i;

	i = 0;
	while (map != NULL && i < (len + 1) && i < (map->height + 1))
	{
		if (map->map[i])
		{
			free(map->map[i]);
			map->map[i] = NULL;
		}
		i++;
	}
	if (map != NULL && map->map != NULL)
	{
		free(map->map);
		map->map = NULL;
	}
	if (map != NULL)
	{
		free(map);
		map = NULL;
	}
}
