/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_actions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vejurick <vejurick@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 14:36:35 by vejurick          #+#    #+#             */
/*   Updated: 2024/08/06 18:29:23 by vejurick         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube.h"

int	on_keypress(int keysym, t_game *game)
{
	if (keysym == ESC)
	{
		mlx_destroy_window(game->mlx_p, game->win_ptr);
		mlx_destroy_display(game->mlx_p);
		free(game->mlx_p);
		ft_final_free(game->map);
		exit (EXIT_SUCCESS);
	}
	return (0);
}

int	on_destroy(t_game *game)
{
	mlx_destroy_window(game->mlx_p, game->win_ptr);
	mlx_destroy_display(game->mlx_p);
	free(game->mlx_p);
	ft_final_free(game->map);
	exit (EXIT_SUCCESS);
}