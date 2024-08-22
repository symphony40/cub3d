/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_textures.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vejurick <vejurick@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 18:19:30 by vejurick          #+#    #+#             */
/*   Updated: 2024/08/22 22:06:26 by vejurick         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube.h"

void	find_textures(t_map *map)
{
	int	no_found;
	int	so_found;

	no_found = 0;
	so_found = 0;
	map->i = 0;
	while (map->map_file_contents[map->i] != NULL)
	{
		if (ft_strncmp(map->map_file_contents[map->i], "NO", 2) == 0)
		{
			if (parse_textures(map->map_file_contents[map->i], &(map->texture_north)) == 0)
				no_found = 1;
			else
				ft_error_and_free_map_and_textures("Invalid north texture format", EXIT_FAILURE, map);
		}
		else if (ft_strncmp(map->map_file_contents[map->i], "SO", 2) == 0)
		{
			if (parse_textures(map->map_file_contents[map->i], &(map->texture_south)) == 0)
				so_found = 1;
			else
				ft_error_and_free_map_and_textures("Invalid south texture format", EXIT_FAILURE, map);
		}
		map->i++;
	}
	find_textures2(map, no_found, so_found);
}

int	find_textures2(t_map *map, int no_found, int so_found)
{
	int	we_found;
	int	ea_found;

	we_found = 0;
	ea_found = 0;
	map->i = 0;
	while (map->map_file_contents[map->i] != NULL)
	{
		if (ft_strncmp(map->map_file_contents[map->i], "WE", 2) == 0)
		{
			if (parse_textures(map->map_file_contents[map->i], &(map->texture_west)) == 0)
				we_found = 1;
			else
				ft_error_and_free_map_and_textures("Invalid west texture format", EXIT_FAILURE, map);
		}
		else if (ft_strncmp(map->map_file_contents[map->i], "EA", 2) == 0)
		{
			if (parse_textures(map->map_file_contents[map->i], &(map->texture_east)) == 0)
				ea_found = 1;
			else
				ft_error_and_free_map_and_textures("Invalid east texture format", EXIT_FAILURE, map);
		}
		map->i++;
	}
	return (textures_final_check(no_found, so_found, we_found, ea_found, map));
}

int	textures_final_check(int no_found, int so_found, int we_found, int ea_found, t_map *map)
{
	if (!no_found || !so_found || !we_found || !ea_found)
		ft_error_and_free_map_and_textures("Missing some textures", EXIT_FAILURE, map);
	return (0);
}

int	parse_textures(const char *line, const char **texture)
{
	const char	*ptr;
	int			fd;

	ptr = line;
	ptr = ptr + 3;
	*texture = ft_strdup(ptr);
	fd = open(*texture, O_RDONLY);
	if (fd < 0)
		return (-1);
	close(fd);
	return (0);
}
