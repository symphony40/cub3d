/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_player_and_map_size.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vejurick <vejurick@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 16:00:35 by vejurick          #+#    #+#             */
/*   Updated: 2024/07/30 18:08:38 by vejurick         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube.h"

void	calculate_map_dimensions(t_map *map)
{
	int		i;
	size_t	max_columns;
	size_t	current_columns;

	i = 0;
	max_columns = 0;
	while (map->map_in_array[i] != NULL)
	{
		current_columns = ft_strlen(map->map_in_array[i]);
		if (current_columns > max_columns)
			max_columns = current_columns;
		i++;
	}
	map->rows = i;
	map->columns = max_columns;
}

int	validate_player_direction(char direction, int *facing)
{
	if (direction == 'N')
	{
		*facing = NORTH;
		return (1);
	}
	else if (direction == 'S')
	{
		*facing = SOUTH;
		return (1);
	}
	else if (direction == 'W')
	{
		*facing = WEST;
		return (1);
	}
	else if (direction == 'E')
	{
		*facing = EAST;
		return (1);
	}
	else
		return (0);
}

void	find_player(t_map *map, t_player *player)
{
	int		player_found;
	int		i;
	size_t	j;
	char	current_char;

	player_found = 0;
	i = 0;
	calculate_map_dimensions(map);
	while (i < map->rows)
	{
		j = 0;
		while (j < ft_strlen(map->map_in_array[i]))
		{
			current_char = map->map_in_array[i][j];
			if (current_char == 'N' || current_char == 'S' || current_char == 'W' || current_char == 'E')
			{
				if (player_found)
					ft_error_and_free_parsed_map("Multiple players found", EXIT_FAILURE, map);
				player->x = j;
				player->y = i;
				if (!validate_player_direction(current_char, &player->facing))
					ft_error_and_free_parsed_map("Player facing invalid direction", EXIT_FAILURE, map);
				player_found = 1;
			}
			j++;
		}
		i++;
	}
	if (!player_found)
		ft_error_and_free_parsed_map("Player not found", EXIT_FAILURE, map);
}
