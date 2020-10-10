/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborboll <aborboll@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 16:56:41 by aborboll          #+#    #+#             */
/*   Updated: 2020/10/10 16:06:42 by aborboll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

t_bool	has_screen(t_game *game)
{
	return (game->width != -1 &&
	game->height != -1);
}

t_bool	validate_screen(t_game *game, char *width, char *height)
{
	if (ft_strlen(height) < 1 || ft_strlen(width) < 1)
	{
		ft_error("Invalid width/height length!", false);
		return (FALSE);
	}
	else if (!ft_strevery(height, ft_isdigit) ||
		!ft_strevery(width, ft_isdigit))
	{
		ft_error("Invalid width/height numbers!", false);
		return (FALSE);
	}
	else if ((ft_atoi(width) > game->width || ft_atoi(width) == 0) ||
	ft_atoi(height) > game->height || ft_atoi(height) == 0)
	{
		ft_error("Bad resolution size!", false);
		return (FALSE);
	}
	return (TRUE);
}

void	invalid_screen(t_game *game, char **size)
{
	ft_split_del(size);
	clear_memory(game);
	game->valid.screen = false;
}
