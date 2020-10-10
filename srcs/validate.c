/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborboll <aborboll@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 16:56:44 by aborboll          #+#    #+#             */
/*   Updated: 2020/10/10 14:30:55 by aborboll         ###   ########.fr       */
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
