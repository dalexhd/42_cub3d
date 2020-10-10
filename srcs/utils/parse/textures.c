/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborboll <aborboll@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 15:47:40 by aborboll          #+#    #+#             */
/*   Updated: 2020/10/10 21:21:57 by aborboll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

char		*parse_texture(char *name, size_t sp, char *line)
{
	char	*path;
	char	*trimmed_path;

	path = NULL;
	if (ft_strnstr(line, name, sp) &&
		(trimmed_path = ft_strtrim(line, name)))
	{
		path = ft_strnew(ft_strlen(trimmed_path) + 1);
		path = ft_strcpy(path, trimmed_path);
		free(trimmed_path);
		return (path);
	}
	return (path);
}

void		parse_textures(t_game *game, char *line)
{
	char	*path;

	path = NULL;
	if ((path = parse_texture("NO ", 3, line)) &&
		validate_texture(game, path, "NO"))
		game->textures.north.path = path;
	else if ((path = parse_texture("SO ", 3, line)) &&
		validate_texture(game, path, "SO"))
		game->textures.south.path = path;
	else if ((path = parse_texture("WE ", 3, line)) &&
		validate_texture(game, path, "WE"))
		game->textures.west.path = path;
	else if ((path = parse_texture("EA ", 3, line)) &&
		validate_texture(game, path, "EA"))
		game->textures.east.path = path;
	else if ((path = parse_texture("S ", 2, line)) &&
		validate_texture(game, path, "S"))
		game->textures.sprite.path = path;
}
