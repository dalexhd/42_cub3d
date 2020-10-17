/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborboll <aborboll@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 16:56:33 by aborboll          #+#    #+#             */
/*   Updated: 2020/10/17 12:32:07 by aborboll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

t_bool			has_map(t_game *game)
{
	return (ft_strlen(game->tmp_map) > 0);
}

t_ivector		position(t_game *game, int x, int y)
{
	t_ivector	pos;

	pos.x = 0;
	pos.y = 0;
	while (game->map[y] != 0)
	{
		x = 0;
		while (game->map[y][x] != '\0')
		{
			if (game->map[y][x] == game->spawn)
			{
				pos.x = x + 0.5;
				pos.y = y + 0.5;
				return (pos);
			}
			x++;
		}
		y++;
	}
	return (pos);
}

t_bool			check_first_last(t_game *game, int x, int y)
{
	while (game->map[y][x] != '\0')
	{
		if (game->map[y][x] != ' ' && game->map[y][x] != '1')
		{
			ft_error("Invalid Map #2", false);
			return (false);
		}
		x++;
	}
	y = 0;
	while (game->map[y])
		y++;
	y = y - 1;
	x = 0;
	while (game->map[y][x] != '\0')
	{
		if (game->map[y][x] != ' ' && game->map[y][x] != '1')
		{
			ft_error("Invalid Map #3", false);
			return (false);
		}
		x++;
	}
	return (true);
}

t_bool			flood_map(t_game *game, int x, int y)
{
	if (game->map[y][x] == '1' || game->map[y][x] == 'f')
		return (true);
	if (game->map[y][x] == '2' || game->map[y][x] == '0' ||
		game->map[y][x] == game->spawn)
	{
		game->map[y][x] = 'f';
		return (flood_map(game, x, y + 1) && flood_map(game, x, y - 1) &&
		flood_map(game, x + 1, y) && flood_map(game, x - 1, y) &&
		flood_map(game, x + 1, y + 1) && flood_map(game, x + 1, y - 1) &&
		flood_map(game, x - 1, y + 1) && flood_map(game, x - 1, y - 1));
	}
	else
	{
		ft_error("Invalid Map #4", false);
		return (false);
	}
}

t_bool			validate_map(t_game *game)
{
	t_ivector	pos;

	pos = position(game, 0, 0);
	if (!(check_first_last(game, 0, 0) && flood_map(game, pos.x, pos.y)))
	{
		game->valid.map = false;
		return (false);
	}
	return (true);
}
