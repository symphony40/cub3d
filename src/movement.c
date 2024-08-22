/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vejurick <vejurick@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 21:03:45 by vejurick          #+#    #+#             */
/*   Updated: 2024/08/22 22:05:22 by vejurick         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube.h"

void	rotate_player(t_game *game, int i)
{
	if (i == 1)
	{
		game->player->angle += ROTATION_SPEED;
		if (game->player->angle > 2 * PI)
			game->player->angle -= 2 * PI;
	}
	else
	{
		game->player->angle -= ROTATION_SPEED;
		if (game->player->angle < 0)
			game->player->angle += 2 * PI;
	}
}

void	move_player(t_game *game, double move_x, double move_y)
{
	int	map_grid_y;
	int	map_grid_x;
	int	new_x;
	int	new_y;

	new_x = roundf(game->player->x_pixels + move_x);
	new_y = roundf(game->player->y_pixels + move_y);
	map_grid_x = (new_x / TILE_SIZE);
	map_grid_y = (new_y / TILE_SIZE);
	if (game->map->map_in_array[map_grid_y][map_grid_x] != '1' &&
	(game->map->map_in_array[map_grid_y][game->player->x_pixels / TILE_SIZE] != '1' &&
	game->map->map_in_array[game->player->y_pixels / TILE_SIZE][map_grid_x] != '1'))
	{
		game->player->x_pixels = new_x;
		game->player->y_pixels = new_y;
	}
}
