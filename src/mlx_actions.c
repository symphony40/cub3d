/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_actions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vejurick <vejurick@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 14:36:35 by vejurick          #+#    #+#             */
/*   Updated: 2024/08/22 21:04:18 by vejurick         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube.h"

void ft_release(mlx_key_data_t keydata, t_game *game)
{
	if (keydata.key == MLX_KEY_D && (keydata.action == MLX_RELEASE))
		game->leftRight = 0;
	else if (keydata.key == MLX_KEY_A && (keydata.action == MLX_RELEASE))
		game->leftRight = 0;
	else if (keydata.key == MLX_KEY_S && (keydata.action == MLX_RELEASE))
		game->upDown = 0;
	else if (keydata.key == MLX_KEY_W && (keydata.action == MLX_RELEASE))
		game->upDown = 0;
	else if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_RELEASE)
		game->rotate = 0;
	else if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_RELEASE)
		game->rotate = 0;
}

void keypress(mlx_key_data_t keydata, void* param)
{
	t_game	*game;

	game = param;
	if (mlx_is_key_down(game->mlx_p, MLX_KEY_ESCAPE))
	{
		ft_final_free(game->map);
		mlx_close_window(game->mlx_p);
		exit (EXIT_SUCCESS);
	}
	else if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
		game->leftRight = -1;
	else if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
		game->leftRight = 1;
	else if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
		game->upDown = -1;
	else if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
		game->upDown = 1;
	else if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_PRESS)
		game->rotate = -1;
	else if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_PRESS)
		game->rotate = 1;
	ft_release(keydata, game);
}

void hook(t_game *game, double move_x, double move_y)
{
	if (game->rotate == 1)
		rotate_player(game, 1);
	if (game->rotate == -1)
		rotate_player(game, 0);
	if (game->leftRight == 1)
	{
		move_x = -sin(game->player->angle) * PLAYER_SPEED;
		move_y = cos(game->player->angle) * PLAYER_SPEED;
		move_player(game, move_x, move_y);
	}
	if (game->leftRight == -1)
	{
		move_x = sin(game->player->angle) * PLAYER_SPEED;
		move_y = -cos(game->player->angle) * PLAYER_SPEED;
		move_player(game, move_x, move_y);
	}
	if (game->upDown == 1)
	{
		move_x = cos(game->player->angle) * PLAYER_SPEED;
		move_y = sin(game->player->angle) * PLAYER_SPEED;
		move_player(game, move_x, move_y);
	}
	if (game->upDown == -1)
	{
		move_x = -cos(game->player->angle) * PLAYER_SPEED;
		move_y = -sin(game->player->angle) * PLAYER_SPEED;
		move_player(game, move_x, move_y);
	}
}

void game_loop(void* param)
{
	t_game	*game;

	game = param;
	
	mlx_delete_image(game->mlx_p, game->img_ptr);
	game->img_ptr = mlx_new_image(game->mlx_p, S_W, S_H);
	hook(game, 0, 0);	
	cast_rays(game);
	mlx_image_to_window(game->mlx_p, game->img_ptr, 0, 0);
}

void	starting_mlx_loop(t_game *game)
{
	game->mlx_p = mlx_init(S_W , S_H, "MLX42", 1);
	if (!game->mlx_p)
	{
		free(game->mlx_p);
		ft_final_free(game->map);
		return ;
	}
	if (game->player->facing == NORTH)
		game->player->angle = 3 * PI / 2;
	if (game->player->facing == SOUTH)
		game->player->angle = PI / 2;
	if (game->player->facing == EAST)
		game->player->angle = 0;
	if (game->player->facing == WEST)
		game->player->angle = PI;
	mlx_loop_hook(game->mlx_p, &game_loop, game);
	mlx_key_hook(game->mlx_p, &keypress, game);
	mlx_loop(game->mlx_p);
	mlx_terminate(game->mlx_p);
}
