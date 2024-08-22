/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vejurick <vejurick@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 14:28:34 by vejurick          #+#    #+#             */
/*   Updated: 2024/08/22 20:59:40 by vejurick         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube.h"

void	my_mlx_pixel_put(t_game *game, int x, int y, int color)	// put the pixel
{
	if (x < 0) // check the x position
		return ;
	else if (x >= S_W)
		return ;
	if (y < 0) // check the y position
		return ;
	else if (y >= S_H)
		return ;
	mlx_put_pixel(game->img_ptr, x, y, color); // put the pixel
}

float	nor_angle(float angle)	// normalize the angle
{
	if (angle < 0)
		angle += (2 * M_PI);
	if (angle > (2 * M_PI))
		angle -= (2 * M_PI);
	return (angle);
}

void	draw_floor_ceiling(t_game *game, int ray, int t_pix, int b_pix)	// draw the floor and the ceiling
{
	int		i;

	i = b_pix;
	while (i < S_H)
		my_mlx_pixel_put(game, ray, i++, 0xB99470FF); // floor
	i = 0;
	while (i < t_pix)
		my_mlx_pixel_put(game, ray, i++, 0x89CFF3FF); // ceiling
}

int	get_color(t_game *game, int flag)	// get the color of the wall
{
	game->ray_angle = nor_angle(game->ray_angle); // normalize the angle
	if (flag == 0)
	{
		if (game->ray_angle > M_PI / 2 && game->ray_angle < 3 * (M_PI / 2))
			return (0xB5B5B5FF); // west wall
		else
			return (0xB5B5B5FF); // east wall
	}
	else
	{
		if (game->ray_angle > 0 && game->ray_angle < M_PI)
			return (0xF5F5F5FF); // south wall
		else
			return (0xF5F5F5FF); // north wall
	}
}

void	draw_wall(t_game *game, int ray, int t_pix, int b_pix)	// draw the wall
{
	int color;

	color = get_color(game, game->wall_flag);
	while (t_pix < b_pix)
		my_mlx_pixel_put(game, ray, t_pix++, color);
}

void	render_wall(t_game *game, int ray)	// render the wall
{
	double	wall_h;
	double	b_pix;
	double	t_pix;

	game->ray_distance *= cos(nor_angle(game->ray_angle - game->player->angle)); // fix the fisheye
	wall_h = (TILE_SIZE / game->ray_distance) * ((S_W / 2) / tan(game->player->fov_radians / 2)); // get the wall height
	b_pix = (S_H / 2) + (wall_h / 2); // get the bottom pixel
	t_pix = (S_H / 2) - (wall_h / 2); // get the top pixel
	if (b_pix > S_H) // check the bottom pixel
		b_pix = S_H;
	if (t_pix < 0) // check the top pixel
		t_pix = 0;
	draw_wall(game, ray, t_pix, b_pix); // draw the wall
	draw_floor_ceiling(game, ray, t_pix, b_pix); // draw the floor and the ceiling
}

int	unit_circle(float angle, char c)	// check the unit circle
{
	if (c == 'x')
	{
		if (angle > 0 && angle < M_PI)
			return (1);
	}
	else if (c == 'y')
	{
		if (angle > (M_PI / 2) && angle < (3 * M_PI) / 2)
			return (1);
	}
	return (0);
}

int	inter_check(float angle, float *inter, float *step, int is_horizon)	// check the intersection
{
	if (is_horizon)
	{
		if (angle > 0 && angle < M_PI)
		{
			*inter += TILE_SIZE;
			return (-1);
		}
		*step *= -1;
	}
	else
	{
		if (!(angle > M_PI / 2 && angle < 3 * M_PI / 2)) 
		{
			*inter += TILE_SIZE;
			return (-1);
		}
		*step *= -1;
	}
	return (1);
}

int	wall_hit(float x, float y, t_game *game)	// check the wall hit
{
	int		x_m;
	int		y_m;

	if (x < 0 || y < 0)
		return (0);
	x_m = floor (x / TILE_SIZE);
	y_m = floor (y / TILE_SIZE);
	if ((y_m >= game->h_map || x_m >= game->w_map))
		return (0);
	if (game->map->map_in_array[y_m] && x_m <= (int)strlen(game->map->map_in_array[y_m]))
		if (game->map->map_in_array[y_m][x_m] == '1')
			return (0);
	return (1);
}

float	get_h_inter(t_game *game, float angl)
{
	float	h_x;
	float	h_y;
	float	x_step;
	float	y_step;
	int		pixel;

	y_step = TILE_SIZE;
	x_step = TILE_SIZE / tan(angl);
	h_y = floor(game->player->y_pixels / TILE_SIZE) * TILE_SIZE;
	pixel = inter_check(angl, &h_y, &y_step, 1);
	h_x = game->player->x_pixels + (h_y - game->player->y_pixels) / tan(angl);
	if ((unit_circle(angl, 'y') && x_step > 0) || (!unit_circle(angl, 'y') && x_step < 0))
		x_step *= -1;
	while (wall_hit(h_x, h_y - pixel, game))
	{
		h_x += x_step;
		h_y += y_step;
	}
	return (sqrt(pow(h_x - game->player->x_pixels, 2) + pow(h_y - game->player->y_pixels, 2)));
}

float	get_v_inter(t_game *game, float angl)
{
	float	v_x;
	float	v_y;
	float	x_step;
	float	y_step;
	int		pixel;

	x_step = TILE_SIZE; 
	y_step = TILE_SIZE * tan(angl);
	v_x = floor(game->player->x_pixels / TILE_SIZE) * TILE_SIZE;
	pixel = inter_check(angl, &v_x, &x_step, 0);
	v_y = game->player->y_pixels + (v_x - game->player->x_pixels) * tan(angl);
	if ((unit_circle(angl, 'x') && y_step < 0) || (!unit_circle(angl, 'x') && y_step > 0))
		y_step *= -1;
	while (wall_hit(v_x - pixel, v_y, game))
	{
		v_x += x_step;
		v_y += y_step;
	}
	return (sqrt(pow(v_x - game->player->x_pixels, 2) + pow(v_y - game->player->y_pixels, 2)));
}

void	cast_rays(t_game *game)
{
	double	h_inter;
	double	v_inter;
	int		ray;

	ray = 0;
	game->w_map = game->map->columns;
	game->h_map = game->map->rows;
	game->ray_angle = game->player->angle - (game->player->fov_radians / 2);
	while (ray < S_W)
	{
		game->wall_flag = 0;
		h_inter = get_h_inter(game, nor_angle(game->ray_angle));
		v_inter = get_v_inter(game, nor_angle(game->ray_angle));
		if (v_inter <= h_inter)
			game->ray_distance = v_inter;
		else
		{
			game->ray_distance = h_inter;
			game->wall_flag = 1;
		}
		render_wall(game, ray);
		ray++;
		game->ray_angle += (game->player->fov_radians / S_W);
	}
}