/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_fill.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppontet <ppontet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 16:45:04 by ppontet           #+#    #+#             */
/*   Updated: 2025/01/18 19:03:15 by ppontet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <fcntl.h>
#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>

static void	map_init(t_map *map, t_map_size map_size)
{
	map->map = NULL;
	map->error = 0;
	map->width = map_size.line_len;
	map->height = map_size.count_line;
	map->collectibles = 0;
	map->exit = (t_coordinates){0, 0};
	map->textures.collectible.ptr = NULL;
	map->textures.exit_off.ptr = NULL;
	map->textures.exit_off_fl.ptr = NULL;
	map->textures.exit_off_fr.ptr = NULL;
	map->textures.exit_on.ptr = NULL;
	map->textures.floor.ptr = NULL;
	map->textures.player_fr.ptr = NULL;
	map->textures.player_fl.ptr = NULL;
	map->textures.wall.ptr = NULL;
}

static t_map	*store_map(t_map *map, t_map_size map_size)
{
	size_t	i;
	ssize_t	ret;

	map_size.fd = open(map_size.map_name, O_RDONLY);
	if (map_size.fd == -1)
		return (NULL);
	i = 0;
	ret = 1;
	while (i <= map->height && ret != 0)
	{
		ret = read(map_size.fd, map->map[i], map_size.line_len + 1);
		if (ret == -1)
			return ((void)free_map(map, i), NULL);
		map->map[i][ret] = '\0';
		i++;
	}
	return (map);
}

t_map	*fill_map(t_map *map, t_map_size map_size)
{
	size_t	i;

	i = 0;
	if (map == NULL)
		return (NULL);
	map_init(map, map_size);
	map->map = malloc(sizeof(char *) * (map->height + 1));
	if (map->map == NULL)
		return (NULL);
	while (i <= map->height)
	{
		map->map[i] = malloc(sizeof(char) * (map->width + 2));
		if (map->map[i] == NULL)
			return ((void)free_map(map, i), NULL);
		i++;
	}
	if (store_map(map, map_size) == NULL)
		return (NULL);
	if (check_map(map) == -1)
		return (NULL);
	return (map);
}
