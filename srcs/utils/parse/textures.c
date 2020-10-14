/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborboll <aborboll@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 15:47:40 by aborboll          #+#    #+#             */
/*   Updated: 2020/10/14 10:45:38 by aborboll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

char		*parse_texture(char *name, size_t sp, char *line)
{
	char	*trimmed_path;

	trimmed_path = NULL;
	if (ft_strnstr(line, name, sp) &&
		(trimmed_path = ft_strtrim(line, name)))
	{
		return (trimmed_path);
	}
	return (trimmed_path);
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
