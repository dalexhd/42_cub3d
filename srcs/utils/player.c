/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborboll <aborboll@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/17 12:47:56 by aborboll          #+#    #+#             */
/*   Updated: 2020/10/17 12:48:20 by aborboll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

t_bool	is_moving(t_game *game)
{
	if (game->player.moving.forward ||
	game->player.moving.backward ||
	game->player.moving.right ||
	game->player.moving.left)
		return (TRUE);
	return (FALSE);
}

t_bool	is_rotating(t_game *game)
{
	if (game->player.rotating.left || game->player.rotating.right)
		return (TRUE);
	return (FALSE);
}

t_bool	is_shifting(t_game *game)
{
	if (game->player.shifting)
		return (TRUE);
	return (FALSE);
}
