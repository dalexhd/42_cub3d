/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborboll <aborboll@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 17:20:18 by aborboll          #+#    #+#             */
/*   Updated: 2020/10/09 12:28:12 by aborboll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

t_bool	has_textures(t_game *game)
{
	return (game->textures.north.path &&
	game->textures.south.path &&
	game->textures.west.path &&
	game->textures.east.path);
}
