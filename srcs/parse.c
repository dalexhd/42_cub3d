/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborboll <aborboll@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 16:56:14 by aborboll          #+#    #+#             */
/*   Updated: 2020/10/10 20:24:16 by aborboll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

void		parse_screen(t_game *game, char *line)
{
	char	**size;

	if (!ft_strncmp("R ", line, 2) && (size = ft_split(line, ' ')))
	{
		game->tmp_mlx = mlx_init();
		mlx_get_screen_size(game->tmp_mlx, &game->width, &game->height);
		if (validate_screen(game, size[1], size[2]))
		{
			game->valid.screen = true;
			game->width = ft_atoi(size[1]);
			game->height = ft_atoi(size[2]);
			ft_split_del(size);
		}
		else
			invalid_screen(game, size);
	}
}

void		parse_game(t_game *game, char *file)
{
	char	*line;
	int		fd;

	fd = parse_file(game, file);
	line = NULL;
	while (get_next_line(fd, &line))
	{
		if (valid_cub(game))
		{
			parse_screen(game, line);
			parse_textures(game, line);
			parse_floor(game, line);
			parse_ceiling(game, line);
			parse_map(game, line);
		}
		free(line);
	}
	free(line);
	close(fd);
}
