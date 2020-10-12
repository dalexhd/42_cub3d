/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborboll <aborboll@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 16:56:14 by aborboll          #+#    #+#             */
/*   Updated: 2020/10/12 02:58:59 by aborboll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

void		parse_screen(t_game *game, char *line)
{
	char	**size;

	if (!ft_strncmp("R ", line, 2) && (size = ft_split(line, ' ')))
	{
		mlx_get_screen_size(game->tmp_mlx, &game->width, &game->height);
		if (validate_screen(game, size[1], size[2]))
		{
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
	char	*trimmed;
	int		fd;

	fd = parse_file(game, file);
	game->tmp_mlx = mlx_init();
	while (get_next_line(fd, &line))
	{
		trimmed = ft_strtrim(line, " ");
		if (valid_cub(game))
		{
			parse_screen(game, trimmed);
			parse_textures(game, trimmed);
			parse_floor(game, trimmed);
			parse_ceiling(game, trimmed);
			parse_map(game, trimmed);
		}
		free(trimmed);
		free(line);
	}
	free(line);
	close(fd);
}
