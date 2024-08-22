/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_floor_ceiling.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vejurick <vejurick@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 18:25:09 by vejurick          #+#    #+#             */
/*   Updated: 2024/08/22 22:02:45 by vejurick         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube.h"

int	ft_isspace(char c)
{
	return (c == ' ' || c == '\t' || c == '\n'
		|| c == '\v' || c == '\f' || c == '\r');
}

int	find_floor_and_ceiling(t_map *map)
{
	map->floor_found = 0;
	map->ceiling_found = 0;
	map->i = 0;
	while (map->map_file_contents[map->i] != NULL)
	{
		if (ft_strncmp(map->map_file_contents[map->i], "F", 1) == 0)
		{
			if (parse_color(map->map_file_contents[map->i], map->floor_color) == 0)
				map->floor_found = 1;
			else
				ft_error_and_free_map("Invalid floor color format", EXIT_FAILURE, map);
		}
		else if (ft_strncmp(map->map_file_contents[map->i], "C", 1) == 0)
		{
			if (parse_color(map->map_file_contents[map->i], map->ceiling_color) == 0)
				map->ceiling_found = 1;
			else
				ft_error_and_free_map("Invalid ceiling color format", EXIT_FAILURE, map);
		}
		map->i++;
	}
	if (!map->floor_found || !map->ceiling_found)
		ft_error_and_free_map("Ceiling or floor color not found", EXIT_FAILURE, map);
	return (0);
}

int	parse_color(const char *line, int color[3])
{
	const char	*ptr;

	ptr = line;
	while (*ptr && !ft_isdigit(*ptr))
		ptr++;
	color[0] = 0;
	while (ft_isdigit(*ptr))
	{
		color[0] = color[0] * 10 + (*ptr - '0');
		ptr++;
	}
	if (*ptr != ',')
		return (-1);
	ptr++;
	return (parse_color2(ptr, color));
}

int	parse_color2(const char *ptr, int color[3])
{
	while (*ptr && ft_isspace(*ptr))
		ptr++;
	color[1] = 0;
	while (ft_isdigit(*ptr))
	{
		color[1] = color[1] * 10 + (*ptr - '0');
		ptr++;
	}
	if (*ptr != ',')
		return (-1);
	ptr++;
	while (*ptr && ft_isspace(*ptr))
		ptr++;
	color[2] = 0;
	while (ft_isdigit(*ptr))
	{
		color[2] = color[2] * 10 + (*ptr - '0');
		ptr++;
	}
	if (*ptr != '\0' && !ft_isspace(*ptr))
		return (-1);
	if (color[0] < 0 || color[0] > 255
		|| color[1] < 0 || color[1] > 255 || color[2] < 0 || color[2] > 255)
		return (-1);
	return (0);
}
