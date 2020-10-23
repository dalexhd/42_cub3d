/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotating.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborboll <aborboll@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 18:42:35 by aborboll          #+#    #+#             */
/*   Updated: 2020/10/23 10:32:37 by aborboll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

void		rotate_right(t_game *game)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = game->dir.x;
	game->dir.x = game->dir.x * cos(game->player.rotate_speed) -
		game->dir.y * sin(game->player.rotate_speed);
	game->dir.y = old_dir_x * sin(game->player.rotate_speed) + game->dir.y *
		cos(game->player.rotate_speed);
	old_plane_x = game->plane.x;
	game->plane.x = game->plane.x * cos(game->player.rotate_speed) -
		game->plane.y * sin(game->player.rotate_speed);
	game->plane.y = old_plane_x * sin(game->player.rotate_speed) +
		game->plane.y * cos(game->player.rotate_speed);
}

void		rotate_left(t_game *game)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = game->dir.x;
	game->dir.x = game->dir.x * cos(-game->player.rotate_speed) - game->dir.y *
		sin(-game->player.rotate_speed);
	game->dir.y = old_dir_x * sin(-game->player.rotate_speed) + game->dir.y *
		cos(-game->player.rotate_speed);
	old_plane_x = game->plane.x;
	game->plane.x = game->plane.x * cos(-game->player.rotate_speed) -
		game->plane.y * sin(-game->player.rotate_speed);
	game->plane.y = old_plane_x * sin(-game->player.rotate_speed) +
		game->plane.y * cos(-game->player.rotate_speed);
}

void		ft_rotate(t_game *game)
{
	if (game->player.rotating.left)
		rotate_left(game);
	if (game->player.rotating.right)
		rotate_right(game);
}