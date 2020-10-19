/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborboll <aborboll@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 18:42:35 by aborboll          #+#    #+#             */
/*   Updated: 2020/10/19 19:09:57 by aborboll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

void	move_forward(t_game *game)
{
	if (game->map[(int)game->player.y][(int)(game->player.x + game->dir.x *
		game->player.speed)] == '0')
		game->player.x += game->dir.x * game->player.speed;
	if (game->map[(int)(game->player.y + game->dir.y * game->player.speed)]
		[(int)game->player.x] == '0')
		game->player.y += game->dir.y * game->player.speed;
}

void	move_backward(t_game *game)
{
	if (game->map[(int)game->player.y][(int)(game->player.x - game->dir.x *
		game->player.speed)] == '0')
		game->player.x -= game->dir.x * game->player.speed;
	if (game->map[(int)(game->player.y - game->dir.y * game->player.speed)]
		[(int)game->player.x] == '0')
		game->player.y -= game->dir.y * game->player.speed;
}

void	move_right(t_game *game)
{
	if (game->map[(int)game->player.y][(int)(game->player.x - game->dir.y *
		game->player.speed)] == '0')
		game->player.x += -game->dir.y * game->player.speed;
	if (game->map[(int)(game->player.y + game->dir.x * game->player.speed)]
		[(int)game->player.x] == '0')
		game->player.y += game->dir.x * game->player.speed;
}

void	move_left(t_game *game)
{
	if (game->map[(int)game->player.y][(int)(game->player.x + game->dir.y *
		game->player.speed)] == '0')
		game->player.x += game->dir.y * game->player.speed;
	if (game->map[(int)(game->player.y - game->dir.x * game->player.speed)]
		[(int)game->player.x] == '0')
		game->player.y += -game->dir.x * game->player.speed;
}
