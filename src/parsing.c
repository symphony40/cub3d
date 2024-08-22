/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vejurick <vejurick@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 18:24:07 by vejurick          #+#    #+#             */
/*   Updated: 2024/08/22 22:06:06 by vejurick         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube.h"

char	*ft_strcat(char *dest, const char *src)
{
	char		*dest_ptr;
	const char	*src_ptr;

	dest_ptr = dest;
	while (*dest_ptr != '\0')
		dest_ptr++;
	src_ptr = src;
	while (*src_ptr != '\0')
	{
		*dest_ptr = *src_ptr;
		dest_ptr++;
		src_ptr++;
	}
	*dest_ptr = '\0';
	return (dest);
}

void	read_map_file(t_map *map)
{
	char		*line;
	char		*temp;
	char		*map_in_string;

	map_in_string = NULL;
	line = get_next_line(map->file_fd);
	if (!line)
		ft_error("Empty file", EXIT_FAILURE);
	while (line)
	{
		temp = ft_strjoin(map_in_string, line);
		free(map_in_string);
		free(line);
		map_in_string = temp;
		line = get_next_line(map->file_fd);
	}
	map->map_file_contents = ft_split(map_in_string, '\n');
	free(map_in_string);
}

void	space_to_wall(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map->map_in_array[i])
	{
		while (map->map_in_array[i][j])
		{
			if (ft_isspace(map->map_in_array[i][j]))
				map->map_in_array[i][j] = 49;
			j++;
		}
		j = 0;
		i++;
	}
}

void	separate_map_and_textures(t_map *map)
{
	find_floor_and_ceiling(map);
	find_textures(map);
	find_map(map);
	map->map_in_array = ft_split(map->map, '\n');
	has_walls_around(map);
	space_to_wall(map);
}

void	parse_map(char **argv, t_map *map)
{
	t_player	player;

	(void)player;
	map->file_fd = open(argv[1], O_RDONLY);
	if (map->file_fd < 0)
		ft_error("File does not exist", EXIT_FAILURE);
	read_map_file(map);
	separate_map_and_textures(map);
}
