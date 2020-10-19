/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborboll <aborboll@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 17:00:16 by aborboll          #+#    #+#             */
/*   Updated: 2020/10/19 19:13:13 by aborboll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

void	ft_rotate(t_game *game)
{
	if (game->player.rotating.left)
		rotate_left(game);
	if (game->player.rotating.right)
		rotate_right(game);
}

void	ft_move(t_game *game)
{
	if (game->player.moving.forward)
		move_forward(game);
	if (game->player.moving.backward)
		move_backward(game);
	if (game->player.moving.left)
		move_left(game);
	if (game->player.moving.right)
		move_right(game);
}

void	ft_shift(t_game *game)
{
	if (game->player.shifting)
	{
		game->player.speed = (PL_SPEED * 3.6 / 100.0) / 2;
		game->player.rotate_speed = (RT_SPEED * M_PI / 180) / 1.5;
	}
	else
	{
		game->player.speed = PL_SPEED * 3.6 / 100.0;
		game->player.rotate_speed = RT_SPEED * M_PI / 180;
	}
}

int		key_press(int keycode, t_game *game)
{
	(void)(*game);
	if (keycode == KEY_ESC)
		close_window(game);
	if (keycode == KEY_W)
		game->player.moving.forward = 1;
	if (keycode == KEY_S)
		game->player.moving.backward = 1;
	if (keycode == KEY_D)
		game->player.moving.right = 1;
	if (keycode == KEY_A)
		game->player.moving.left = 1;
	if (keycode == KEY_RIGHT)
		game->player.rotating.right = 1;
	if (keycode == KEY_LEFT)
		game->player.rotating.left = 1;
	if (keycode == KEY_SHIFT)
		game->player.shifting = 1;
	return (0);
}

int		key_release(int keycode, t_game *game)
{
	if (keycode == KEY_W)
		game->player.moving.forward = 0;
	if (keycode == KEY_S)
		game->player.moving.backward = 0;
	if (keycode == KEY_D)
		game->player.moving.right = 0;
	if (keycode == KEY_A)
		game->player.moving.left = 0;
	if (keycode == KEY_RIGHT)
		game->player.rotating.right = 0;
	if (keycode == KEY_LEFT)
		game->player.rotating.left = 0;
	if (keycode == KEY_SHIFT)
	{
		game->player.shifting = 0;
	}
	return (0);
}

void	load_controls(t_game *game)
{
	mlx_hook(game->win, 2, 1L << 0, &key_press, game);
	mlx_hook(game->win, 3, 1L << 1, &key_release, game);
	mlx_hook(game->win, 17, 1L << 17, close_window, game);
}
