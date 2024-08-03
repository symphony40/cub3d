/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vejurick <vejurick@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 20:32:53 by vejurick          #+#    #+#             */
/*   Updated: 2024/07/24 20:38:38 by vejurick         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube.h"

int	is_valid_map_line(char *line)
{
	size_t	j;

	j = 0;
	while (j < ft_strlen(line))
	{
		if (!ft_strchr(" 01NESW", line[j]))
			return (0);
		j++;
	}
	return (1);
}

int	find_map_start_index(char **map_file_contents, int length)
{
	int	i;

	i = 0;
	while (i < length)
	{
		if (is_valid_map_line(map_file_contents[i]))
			return (i);
		i++;
	}
	return (-1);
}

int	calculate_map_size(char **map_file_contents, int start_index, int length)
{
	int	map_size;
	int	i;

	map_size = 0;
	i = start_index;
	while (i < length)
	{
		map_size += ft_strlen(map_file_contents[i]) + 1;
		i++;
	}
	return (map_size);
}

void	concatenate_lines(char *map, char **map_file_contents, int start, int length)
{
	int	i;

	i = start;
	map[0] = '\0';
	while (i < length)
	{
		ft_strcat(map, map_file_contents[i]);
		ft_strcat(map, "\n");
		i++;
	}
}

void	find_map(t_map *map)
{
	int	length;
	int	index;
	int	map_size;

	length = 0;
	while (map->map_file_contents[length] != NULL)
		length++;
	index = find_map_start_index(map->map_file_contents, length);
	if (index != -1)
	{
		map_size = calculate_map_size(map->map_file_contents, index, length);
		map->map = (char *)malloc(map_size + 1);
		if (map->map == NULL)
		{
			ft_error_and_free_map("Map memory allocation failed", EXIT_FAILURE, map);
			return ;
		}
		concatenate_lines(map->map, map->map_file_contents, index, length);
	}
}
