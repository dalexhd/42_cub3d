/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborboll <aborboll@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 16:56:21 by aborboll          #+#    #+#             */
/*   Updated: 2020/10/10 14:11:56 by aborboll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

t_bool	has_colors(t_game *game)
{
	return (game->colors.ceiling.r &&
	game->colors.ceiling.g &&
	game->colors.ceiling.b &&
	game->colors.floor.r &&
	game->colors.floor.g &&
	game->colors.floor.b);
}

t_bool	validate_color(char *color)
{
	int	num;

	if (!color || ft_strlen(color) < 1)
	{
		ft_error("ERR: Invalid colors length!", false);
		return (false);
	}
	else if (!ft_strevery(color, ft_isdigit))
	{
		ft_error("ERR: Invalid RGB number. Found \"%s\"", false, color);
		return (false);
	}
	else if ((num = ft_atoi(color)) > 255)
	{
		ft_error("ERR: Max color value is 255. Found %i", false, num);
		return (false);
	}
	return (true);
}
