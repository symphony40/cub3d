/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_actions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vejurick <vejurick@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 14:36:35 by vejurick          #+#    #+#             */
/*   Updated: 2024/08/07 15:25:05 by vejurick         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube.h"

// All functions in this file except for the last one are there just the put the demostrative white square to the window to test the library and are to be deleted later

void keypress(void* param)
{
	t_game	*game;

	game = param;
	if (mlx_is_key_down(game->mlx_p, MLX_KEY_ESCAPE))
	{
		ft_final_free(game->map);
		mlx_close_window(game->mlx_p);
		exit (EXIT_SUCCESS);
	}
	if (mlx_is_key_down(game->mlx_p, MLX_KEY_UP))
		game->win_ptr->instances[0].y -= 5;
	if (mlx_is_key_down(game->mlx_p, MLX_KEY_DOWN))
		game->win_ptr->instances[0].y += 5;
	if (mlx_is_key_down(game->mlx_p, MLX_KEY_LEFT))
		game->win_ptr->instances[0].x -= 5;
	if (mlx_is_key_down(game->mlx_p, MLX_KEY_RIGHT))
		game->win_ptr->instances[0].x += 5;
}

int32_t ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a)
{
    return (r << 24 | g << 16 | b << 8 | a);
}

void put_square(void* param)
{
	t_game	*game;

	game = param;
	
	for (uint32_t i = 0; i < 5; ++i)
	{
		for (uint32_t y = 0; y < 5; ++y)
		{
			uint32_t color = ft_pixel(
				0xFF, // R
				0xFF, // G
				0xFF, // B
				0xFF  // A
			);
			mlx_put_pixel(game->win_ptr, i, y, color);
		}
	}
}

void	starting_mlx_loop(t_game *game)
{
	game->mlx_p = mlx_init(1920, 1080, "MLX42", 1);
	if (!game->mlx_p)
	{
		free(game->mlx_p);
		ft_final_free(game->map);
		return ;
	}
	if (!(game->win_ptr = mlx_new_image(game->mlx_p, 128, 128)))
	{
		mlx_close_window(game->mlx_p);
		puts(mlx_strerror(mlx_errno));
		return ;
	}
	if (mlx_image_to_window(game->mlx_p, game->win_ptr, 0, 0) == -1)
	{
		mlx_close_window(game->mlx_p);
		puts(mlx_strerror(mlx_errno));
		return ;
	}
	mlx_loop_hook(game->mlx_p, &put_square, game);
	mlx_loop_hook(game->mlx_p, &keypress, game);
	mlx_loop(game->mlx_p);
	mlx_terminate(game->mlx_p);
}
