/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_fill.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppontet <ppontet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 16:45:04 by ppontet           #+#    #+#             */
/*   Updated: 2025/01/13 18:03:22 by ppontet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <fcntl.h>
#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>

static t_map	*store_map(t_map *map, t_map_size map_size)
{
	size_t	i;

	map_size.fd = open(map_size.map_name, O_RDONLY);
	if (map_size.fd == -1)
		return (NULL);
	i = 0;
	while (i <= map->height)
	{
		if (read(map_size.fd, map->map[i], map_size.line_len + 1) == -1)
			return ((void)free_map(map, i), NULL);
		i++;
	}
	return (map);
}

t_map	*fill_map(t_map_size map_size, t_map *map)
{
	size_t	i;

	i = 0;
	if (map == NULL)
		return (NULL);
	map->height = map_size.count_line;
	map->width = map_size.line_len;
	map->map = malloc(sizeof(char *) * (map->height + 1));
	if (map->map == NULL)
		return (NULL);
	while (i <= map->height)
	{
		map->map[i] = malloc(sizeof(char) * (map->width + 1));
		if (map->map[i] == NULL)
			return ((void)free_map(map, i), NULL);
		i++;
	}
	if (store_map(map, map_size) == NULL)
		return (NULL);
	return (map);
}
