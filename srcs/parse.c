/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborboll <aborboll@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 16:56:14 by aborboll          #+#    #+#             */
/*   Updated: 2020/10/08 22:20:54 by aborboll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

void		parse_screen(t_game *game, char *line)
{
	char	**size;

	if (!ft_strncmp("R ", line, 2) && (size = ft_split(line, ' ')))
	{
		game->width = ft_atoi(size[1]);
		game->height = ft_atoi(size[2]);
		ft_split_del(size);
	}
}

void		parse_textures(t_game *game, char *line)
{
	char	**path;

	path = NULL;
	if (ft_strnstr(line, "NO ", 3) && (path = ft_split(line, ' ')))
		game->textures.north.path = path[1];
	else if (ft_strnstr(line, "SO ", 3) && (path = ft_split(line, ' ')))
		game->textures.south.path = path[1];
	else if (ft_strnstr(line, "WE ", 3) && (path = ft_split(line, ' ')))
		game->textures.west.path = path[1];
	else if (ft_strnstr(line, "EA ", 3) && (path = ft_split(line, ' ')))
		game->textures.east.path = path[1];
	else if (ft_strnstr(line, "S ", 2) && (path = ft_split(line, ' ')))
		game->textures.sprite.path = path[1];
	if (path != NULL)
		ft_split_del(path);
}

void		parse_file(t_game *game, char *file)
{
	char	*line;
	int		fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		free(game);
		ft_error("Error opening cub file!", TRUE);
	}
	line = NULL;
	while (get_next_line(fd, &line))
	{
		parse_screen(game, line);
		parse_textures(game, line);
		parse_floor(game, line);
		parse_ceiling(game, line);
		free(line);
	}
	free(line);
	close(fd);
}
