/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vejurick <vejurick@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 21:05:15 by vejurick          #+#    #+#             */
/*   Updated: 2024/08/22 21:55:07 by vejurick         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube.h"

unsigned int	rgb_to_hex(int color[3])
{
	return (color[0] << 24 | color[1] << 16 | color[2] << 8 | 255 << 0);
}

void	my_mlx_pixel_put(t_game *game, int x, int y, unsigned int color)
{
	if (x < 0)
		return ;
	else if (x >= S_W)
		return ;
	if (y < 0)
		return ;
	else if (y >= S_H)
		return ;
	mlx_put_pixel(game->img_ptr, x, y, color);
}

void	draw_floor_ceiling(t_game *game, int ray, int t_pix, int b_pix)
{
	int				i;
	unsigned int	floor_hex;
	unsigned int	ceiling_hex;

	floor_hex = rgb_to_hex(game->map->floor_color);
	ceiling_hex = rgb_to_hex(game->map->ceiling_color);
	i = b_pix;
	while (i < S_H)
		my_mlx_pixel_put(game, ray, i++, floor_hex);
	i = 0;
	while (i < t_pix)
		my_mlx_pixel_put(game, ray, i++, ceiling_hex);
}

int	get_color(t_game *game, int flag)
{
	game->ray_angle = nor_angle(game->ray_angle);
	if (flag == 0)
	{
		if (game->ray_angle > PI / 2 && game->ray_angle < 3 * (PI / 2))
			return (0xB5B5B5FF); // west wall
		else
			return (0xB5B5B5FF); // east wall
	}
	else
	{
		if (game->ray_angle > 0 && game->ray_angle < PI)
			return (0xF5F5F5FF); // south wall
		else
			return (0xF5F5F5FF); // north wall
	}
}

void	draw_wall(t_game *game, int ray, int t_pix, int b_pix)
{
	int color;

	color = get_color(game, game->wall_flag);
	while (t_pix < b_pix)
		my_mlx_pixel_put(game, ray, t_pix++, color);
}

void	render_wall(t_game *game, int ray)
{
	double	wall_h;
	double	b_pix;
	double	t_pix;

	game->ray_distance *= cos(nor_angle(game->ray_angle - game->player->angle));
	wall_h = (TILE_SIZE / game->ray_distance) * ((S_W / 2) / tan(game->player->fov_radians / 2));
	b_pix = (S_H / 2) + (wall_h / 2);
	t_pix = (S_H / 2) - (wall_h / 2);
	if (b_pix > S_H)
		b_pix = S_H;
	if (t_pix < 0)
		t_pix = 0;
	draw_wall(game, ray, t_pix, b_pix);
	draw_floor_ceiling(game, ray, t_pix, b_pix);
}
