/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborboll <aborboll@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 16:56:44 by aborboll          #+#    #+#             */
/*   Updated: 2020/10/11 21:48:59 by aborboll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

t_bool		valid_cub(t_game *game)
{
	return (game->valid.screen &&
	game->valid.textures &&
	game->valid.colors &&
	game->valid.map);
}

t_bool		valid_cub_struct(t_game *game)
{
	return (has_colors(game) &&
	has_screen(game) &&
	has_textures(game) &&
	game->valid.map);
}
