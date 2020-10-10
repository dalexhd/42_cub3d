/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborboll <aborboll@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 15:04:06 by aborboll          #+#    #+#             */
/*   Updated: 2020/10/10 20:22:23 by aborboll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

t_player		init_player(void)
{
	t_player	player;

	player = (t_player){
		.deg = 0,
		.rotating = {.right = FALSE, .left = FALSE},
		.speed = PL_SPEED * 3.6 / 100.0, .rotate_speed = RT_SPEED * M_PI / 180,
		.moving = {.forward = FALSE, .backward = FALSE,
		.right = FALSE, .left = FALSE},
	};
	return (player);
}

t_textures		init_textures(void)
{
	t_textures	textures;

	textures = (t_textures){
		.north.path = NULL, .north.ptr = NULL,
		.south.path = NULL, .south.ptr = NULL,
		.east.path = NULL, .east.ptr = NULL,
		.west.path = NULL, .west.ptr = NULL,
		.sprite.path = NULL, .sprite.ptr = NULL,
	};
	return (textures);
}

t_game			*init_structure(void)
{
	t_game		*game;

	game = (t_game *)malloc(sizeof(t_game));
	game->width = -1;
	game->height = -1;
	game->textures = init_textures();
	game->tmp_map = ft_strdup("");
	game->minimap = 1;
	game->player = (t_player){.x = -0., .y = -0.};
	game->dir = (t_direction){.x = -1., .y = 0.};
	game->plane = (t_direction){.x = 0, .y = 1};
	game->player = init_player();
	game->valid = (t_valid){.screen = true, .textures = true,
		.colors = true, .map = true};
	return (game);
}

t_game			*init_game(int argc, char **argv)
{
	t_game		*game;

	if (argc < 2 || argc > 3)
		ft_error("Please check your arguments", true);
	game = init_structure();
	parse_game(game, argv[1]);
	if (!valid_cub(game))
		exit(EXIT_FAILURE);
	fill_map(game);
	return (game);
}
