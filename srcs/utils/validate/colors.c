/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborboll <aborboll@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 16:56:21 by aborboll          #+#    #+#             */
/*   Updated: 2020/10/12 02:42:38 by aborboll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

t_bool	has_colors(t_game *game)
{
	return (has_floor(game) && has_ceiling(game));
}

t_bool	has_floor(t_game *game)
{
	return (game->colors.floor.r != -1 &&
	game->colors.floor.g != -1 &&
	game->colors.floor.b != -1);
}

t_bool	has_ceiling(t_game *game)
{
	return (game->colors.ceiling.r != -1 &&
	game->colors.ceiling.g != -1 &&
	game->colors.ceiling.b != -1);
}

t_bool	validate_color(char *color)
{
	int	num;

	if (color == NULL || ft_strlen(color) < 1)
	{
		ft_error("ERR: Invalid colors length!", false);
		return (false);
	}
	else if (!ft_strevery(color, ft_isdigit))
	{
		ft_error("ERR: Invalid RGB number. Found %s", false, color);
		return (false);
	}
	else if ((num = ft_atoi(color)) > 255)
	{
		ft_error("ERR: Max color value is 255. Found %i", false, num);
		return (false);
	}
	return (true);
}
