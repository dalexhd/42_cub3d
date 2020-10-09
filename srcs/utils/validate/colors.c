/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborboll <aborboll@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 16:56:21 by aborboll          #+#    #+#             */
/*   Updated: 2020/10/09 12:22:47 by aborboll         ###   ########.fr       */
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
	if (ft_strlen(color) < 1)
	{
		ft_error("Invalid floor ceiling colors length!", false);
		return (FALSE);
	}
	else if (!ft_strevery(color, ft_isdigit))
	{
		ft_error("Invalid floor ceiling colors numbers!", false);
		return (FALSE);
	}
	else if (ft_atoi(color) > 255)
	{
		ft_error("Max color value is 255!", false);
		return (FALSE);
	}
	return (TRUE);
}
