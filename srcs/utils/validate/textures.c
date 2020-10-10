/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborboll <aborboll@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 17:20:18 by aborboll          #+#    #+#             */
/*   Updated: 2020/10/10 22:05:36 by aborboll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

t_texture		load_texture(void *mlx_ptr, t_texture texture)
{
	texture.texture = mlx_xpm_file_to_image(mlx_ptr, texture.path,
	&texture.width, &texture.height);
	texture.ptr = (int *)mlx_get_data_addr(texture.texture,
	&texture.bpp,
	&texture.size_l,
	&texture.endian);
	return (texture);
}

static	int		texture_file(t_game *game, char *file, char *name)
{
	int			fd;

	if (!ft_strendswith(file, ".xpm") && !ft_strendswith(file, ".png"))
	{
		ft_error("Texture %s must have .xpm or .png format!", false, name);
		clear_memory(game);
		free(file);
		game->valid.textures = false;
		return (false);
	}
	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		ft_error("Error opening \"%s\" texture!", false, file);
		clear_memory(game);
		free(file);
		game->valid.textures = false;
		return (false);
	}
	return (fd);
}

t_bool			validate_texture(t_game *game, char *texture_path, char *name)
{
	int			fd;
	t_texture	tmp_texture;

	if (!(fd = texture_file(game, texture_path, name)))
		return (false);
	close(fd);
	tmp_texture.path = texture_path;
	tmp_texture = load_texture(game->tmp_mlx, tmp_texture);
	if (!tmp_texture.texture)
	{
		ft_error("ERR: Invalid \"%s\" texture!", false);
		clear_texture(tmp_texture, game->tmp_mlx);
		clear_memory(game);
		free(texture_path);
		game->valid.textures = false;
		return (false);
	}
	clear_texture(tmp_texture, game->tmp_mlx);
	free(texture_path);
	return (true);
}

t_bool			has_textures(t_game *game)
{
	return (game->textures.north.path &&
	game->textures.south.path &&
	game->textures.west.path &&
	game->textures.east.path);
}
