/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborboll <aborboll@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 16:56:14 by aborboll          #+#    #+#             */
/*   Updated: 2020/10/14 10:53:46 by aborboll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

void		parse_screen(t_game *game, char *line)
{
	char	**size;
	char	*resolution;
	t_bool	valid;

	if (!ft_strncmp("R ", line, 2) && (size = ft_split(line, ' ')) &&
		(resolution = ft_strtrim(line, "R ")))
	{
		if (ft_countwords(resolution, ' ') != 2)
			ft_memcpy(size[1], resolution, ft_strlen(resolution));
		ft_strdel(&resolution);
		mlx_get_screen_size(game->tmp_mlx, &game->tmp.width, &game->tmp.height);
		valid = validate_screen(game, size[1], size[2]);
		if (valid == true)
		{
			game->width = ft_atoi(size[1]);
			game->height = ft_atoi(size[2]);
			ft_split_del(size);
		}
		else if (valid == false)
			invalid_screen(game, size);
		else
			ft_split_del(size);
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
		parse_screen(game, trimmed);
		parse_textures(game, trimmed);
		parse_floor(game, trimmed);
		parse_ceiling(game, trimmed);
		parse_map(game, trimmed);
		free(trimmed);
		free(line);
	}
	free(line);
	close(fd);
}
