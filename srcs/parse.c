/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborboll <aborboll@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 16:56:14 by aborboll          #+#    #+#             */
/*   Updated: 2020/10/24 13:07:23 by aborboll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

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
		mlx_get_screen_size(game->mlx, &game->tmp.width, &game->tmp.height);
		valid = validate_screen(game, resolution, size[1], size[2]);
		ft_strdel(&resolution);
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
		game->tmp.safe_line = true;
	}
}

void		parse_game(t_game *game, char *file)
{
	char	*line;
	char	*trimmed;
	int		fd;

	fd = parse_file(game, file);
	game->mlx = mlx_init();
	while (get_next_line(fd, &line))
	{
		game->tmp.safe_line = false;
		trimmed = ft_strtrim(line, " ");
		parse_screen(game, trimmed);
		parse_textures(game, trimmed);
		parse_floor(game, trimmed);
		parse_ceiling(game, trimmed);
		parse_map(game, line);
		ft_strdel(&trimmed);
		ft_strdel(&line);
	}
	ft_strdel(&line);
	close(fd);
	fill_map(game);
	set_sprites(game);
}
