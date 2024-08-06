/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vejurick <vejurick@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 17:24:55 by vejurick          #+#    #+#             */
/*   Updated: 2024/08/05 23:49:02 by vejurick         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_H
# define CUBE_H

# include "ft_printf.h"
# include "libft.h"
# include "get_next_line.h"
# include "../minilibx-linux/mlx.h"
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <errno.h>
# include <signal.h>
# include <unistd.h>

# define NORTH 1
# define SOUTH 2
# define WEST 3
# define EAST 4

typedef struct s_player
{
	int	x;
	int	y;
	int	facing;
}				t_player;

typedef struct s_map
{
	char		**map_file_contents;
	char		*map;
	char		**map_in_array;
	const char	*texture_north;
	const char	*texture_south;
	const char	*texture_west;
	const char	*texture_east;
	int			ceiling_color[3];
	int			floor_color[3];
	int			file_fd;
	int			floor_found;
	int			ceiling_found;
	int			i;
	int			rows;
	int			columns;
}				t_map;

typedef struct s_game
{
	t_map		*map;
	t_player	*player;
	void		*mlx_p;
	void		*win_ptr;
}				t_game;

void	validate_args(int argc, char **argv);
void	ft_error(char *message, int status);
void	ft_error_and_free_map(char *message, int status, t_map *map);
void	ft_error_and_free_parsed_map(char *message, int status, t_map *map);
void	ft_error_and_free_map_and_textures(char *message, int status, t_map *map);
void	parse_map(char **argv, t_map *map);
void	read_map_file(t_map *map);
void	separate_map_and_textures(t_map *map);
int		find_floor_and_ceiling(t_map *map);
int		ft_isspace(char c);
int		parse_color(const char *line, int color[3]);
int		parse_color2(const char *ptr, int color[3]);
char	*ft_strcat(char *dest, const char *src);
void	find_map(t_map *map);
void	find_textures(t_map *map);
int		find_textures2(t_map *map, int no_found, int so_found);
int		parse_textures(const char *line, const char **textures);
int		textures_final_check(int no_found, int so_found, int we_found, int ea_found, t_map *map);
void	has_walls_around(t_map *map);
void	has_walls_around2(t_map *map);
void	space_to_wall(t_map *map);
void	calculate_map_dimensions(t_map *map);
void	find_player(t_map *map, t_player *player);
void	ft_final_free(t_map *map);

#endif