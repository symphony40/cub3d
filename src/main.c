/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vejurick <vejurick@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 17:24:42 by vejurick          #+#    #+#             */
/*   Updated: 2024/08/06 18:29:02 by vejurick         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube.h"

void	validate_args(int argc, char **argv)
{
	if (argc != 2)
		ft_error("Wrong number of arguments", EXIT_FAILURE);
	if (ft_strncmp(argv[1] + ft_strlen(argv[1]) - 4, ".cub", 4) != 0)
		ft_error("Map must be .cub", EXIT_FAILURE);
}

void readme(t_map *map, t_player *player)
{
	int i = 0;
	printf("\nMap is stored in map->map_in_array in a 2D array. All whitespace is replaced by walls (1):\n");
	while (map->map_in_array[i])
	{
		printf("%s\n", map->map_in_array[i]);
		i++;
	}
	printf("\nMap dimesions are stored in map->rows and map->columns:\n");
	printf("rows: %i columns: %i\n", map->rows,map->columns);
	printf("\nPaths to textures are stored as strings in map->texture_north/south/etc.:\n");
	printf("NORTH: %s\n", map->texture_north);
	printf("SOUTH: %s\n", map->texture_south);
	printf("WEST: %s\n", map->texture_west);
	printf("EAST: %s\n", map->texture_east);
	printf("\nCeiling and floor colours are stored in map->ceiling_color and map->floor_color:\n");
	printf("CEILING: %i, %i, %i\n", map->ceiling_color[0],map->ceiling_color[1],map->ceiling_color[2]);
	printf("FLOOR: %i, %i, %i\n", map->floor_color[0],map->floor_color[1],map->floor_color[2]);
	printf("\nIn t_player is saved coordinates of the player and the way he is facing:\n");
	printf("x: %i y: %i facing: %i\n", player->x,player->y, player->facing);
	printf("%s\n", map->map);
}

void	init_map_struct(t_map *map)
{
	map->texture_north = NULL;
	map->texture_south = NULL;
	map->texture_west = NULL;
	map->texture_east = NULL;
}

void	ft_final_free(t_map *map)
{
	int	i;

	i = 0;
	while (map->map_in_array[i] != NULL)
	{
		free(map->map_in_array[i]);
		i++;
	}
	free(map->map_in_array);
	i = 0;
	while (map->map_file_contents[i] != NULL)
	{
		free(map->map_file_contents[i]);
		i++;
	}
	free(map->map_file_contents);
	free(map->map);
	free((void *)map->texture_north);
	free((void *)map->texture_south);
	free((void *)map->texture_west);
	free((void *)map->texture_east);
}

int	main(int argc, char **argv)
{
	t_game		game;
	t_map		map;
	t_player	player;

	init_map_struct(&map);
	validate_args(argc, argv);
	parse_map(argv, &map);
	find_player(&map, &player);
	// readme(&map, &player);
	game.map = &map;
	game.mlx_p = mlx_init();
	game.win_ptr = mlx_new_window(game.mlx_p, 1920, 1080, "Cub3D");
	if (!game.win_ptr)
	{
		ft_final_free(&map);
		return (free(game.mlx_p), 1);
	}
	mlx_key_hook(game.win_ptr, on_keypress, &game);
	mlx_hook(game.win_ptr, 33, 1L << 17, on_destroy, &game);
	mlx_loop(game.mlx_p);
	ft_final_free(&map);
	return (EXIT_SUCCESS);
}
