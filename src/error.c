/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vejurick <vejurick@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 17:59:14 by vejurick          #+#    #+#             */
/*   Updated: 2024/07/31 14:21:10 by vejurick         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube.h"

void	ft_error(char *message, int status)
{
	ft_printf("Error\n%s\n", message);
	exit (status);
}

void	ft_error_and_free_map(char *message, int status, t_map *map)
{
	int	i;

	i = 0;
	while (map->map_file_contents[i] != NULL)
	{
		free(map->map_file_contents[i]);
		i++;
	}
	free(map->map_file_contents);
	ft_error(message, status);
}

void	ft_error_and_free_map_and_textures(char *message, int status, t_map *map)
{
	int	i;

	i = 0;
	while (map->map_file_contents[i] != NULL)
	{
		free(map->map_file_contents[i]);
		i++;
	}
	free(map->map_file_contents);
	if (map->texture_north != NULL)
		free((void *)map->texture_north);
	if (map->texture_south != NULL)
		free((void *)map->texture_south);
	if (map->texture_west != NULL)
		free((void *)map->texture_west);
	if (map->texture_east != NULL)
		free((void *)map->texture_east);
	ft_error(message, status);
}

void	ft_error_and_free_parsed_map(char *message, int status, t_map *map)
{
	int	i;

	i = 0;
	while (map->map_in_array[i] != NULL)
	{
		free(map->map_in_array[i]);
		i++;
	}
	free(map->map_in_array);
	free(map->map);
	free((void *)map->texture_north);
	free((void *)map->texture_south);
	free((void *)map->texture_west);
	free((void *)map->texture_east);
	ft_error_and_free_map(message, status, map);
}
