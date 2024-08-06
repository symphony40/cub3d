/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vejurick <vejurick@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 20:46:56 by vejurick          #+#    #+#             */
/*   Updated: 2024/08/06 10:28:28 by vejurick         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube.h"

void	has_walls_around(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (map->map_in_array[i])
	{
		j = 0;
		while (ft_isspace(map->map_in_array[i][j]))
			j++;
		if (map->map_in_array[i][j] != '1')
			ft_error_and_free_map_and_textures("Wall missing on the left", EXIT_FAILURE, map);
		while (map->map_in_array[i][j])
			j++;
		if (map->map_in_array[i][j - 1] != '1')
			ft_error_and_free_map_and_textures("Wall missing on the right", EXIT_FAILURE, map);
		i++;
	}
	has_walls_around2(map);
}

void	has_walls_around2(t_map *map)
{
	int	i;
	int	j;

	j = 0;
	if (map->map_in_array == NULL || map->map_in_array[0] == NULL)
		ft_error_and_free_map_and_textures("Invalid map data", EXIT_FAILURE, map);
	while (map->map_in_array[0][j])
	{
		i = 0;
		while (map->map_in_array[i] && ft_isspace(map->map_in_array[i][j]))
			i++;
		if (map->map_in_array[i] == NULL)
			ft_error_and_free_map_and_textures("Invalid map column", EXIT_FAILURE, map);
		if (map->map_in_array[i][j] != '1')
			ft_error_and_free_map_and_textures("Wall missing on the top", EXIT_FAILURE, map);
		while (map->map_in_array[i] && map->map_in_array[i][j] && !ft_isspace(map->map_in_array[i][j]))
			i++;
		if (i > 0 && map->map_in_array[i - 1][j] != '1')
			ft_error_and_free_map_and_textures("Wall missing on the bottom", EXIT_FAILURE, map);
		j++;
	}
}
