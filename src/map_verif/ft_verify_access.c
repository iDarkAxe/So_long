/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verify_access.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppontet <ppontet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 13:51:57 by ppontet           #+#    #+#             */
/*   Updated: 2025/01/19 18:09:30 by ppontet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// @TODO REMOVE !!!
#include <stdlib.h>
#include <string.h>

/**
 * @brief DFS pour valider l'accessibilité des collectibles et de la sortie.
 *
 * @param map Structure contenant la carte.
 * @param pos Position actuelle (x, y) dans la carte.
 * @return int 1 si toutes les pièces sont accessibles, 0 sinon.
 */
static int	dfs_validate(t_map *map, char **visit_map, t_coordinates pos,
		int *collectibles, int *exit_found)
{
	(void)collectibles;
	if (pos.x >= map->width || pos.y >= map->height
		|| visit_map[pos.y][pos.x] == '1')
		return (0);
	if (visit_map[pos.y][pos.x] == 'V')
		return (1);
	if (visit_map[pos.y][pos.x] == 'C')
		*collectibles--;
	if (visit_map[pos.y][pos.x] == 'E')
		*exit_found = 1;
	visit_map[pos.y][pos.x] = 'V';
	dfs_validate(map, visit_map, (t_coordinates){pos.x + 1, pos.y},
		collectibles, exit_found);
	dfs_validate(map, visit_map, (t_coordinates){pos.x - 1, pos.y},
		collectibles, exit_found);
	dfs_validate(map, visit_map, (t_coordinates){pos.x, pos.y + 1},
		collectibles, exit_found);
	dfs_validate(map, visit_map, (t_coordinates){pos.x, pos.y - 1},
		collectibles, exit_found);
	return (*collectibles == 0 && *exit_found == 1);
}

/**
 * @brief Vérifie la validité de la carte.
 *
 * @param map Structure contenant la carte et ses métadonnées.
 * @return int 1 si valide, 0 sinon.
 */
int	validate_map(t_map *map)
{
	t_coordinates	player_pos;
	char			**new_map;
	size_t			i;
	int				collectibles;
	int				exit_found;

	i = 0;
	exit_found = 0;
	collectibles = map->collectibles;
	new_map = malloc(sizeof(char *) * (map->height + 1));
	if (new_map == NULL)
		return (-1);
	while (i <= map->height)
	{
		new_map[i] = strdup(map->map[i]);
		if (new_map[i] == NULL)
			return ((void)free(new_map), -1);
		i++;
	}
	player_pos = find_position(map, 'P');
	if (player_pos.x == (size_t)-1 || player_pos.y == (size_t)-1)
		return (0);
	if (!dfs_validate(map, new_map, player_pos, &collectibles, &exit_found))
		return (0);
	return (1);
}
