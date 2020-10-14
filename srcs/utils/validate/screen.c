/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborboll <aborboll@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 16:56:41 by aborboll          #+#    #+#             */
/*   Updated: 2020/10/14 10:53:57 by aborboll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

t_bool		has_screen(t_game *game)
{
	return (game->width != -1 &&
	game->height != -1);
}

/*
** Validate screen resolution
** @param  {t_game*} game      : The game instance
** @param  {char*} width       : The width of the parsed file
** @param  {char*} height      : The height of the parsed file
** Why do I return 2 at the last if case? This is because I need
** 3 posible values here: True, false, and intermediate (2).
*/

t_bool		validate_screen(t_game *game, char *width, char *height)
{
	t_bool	error;

	error = false;
	if (has_map(game) && (error = true))
		ft_error(ERR_AFTER_MAP, false, "Resolution");
	if (((!width || ft_strlen(width) < 1) || !ft_strevery(width, ft_isdigit))
		&& (error = true))
	{
		ft_error(ft_countnumbers(width) == 2 ? "Invalid resolution. Found %s" :
		"Invalid width. Found %s", false, width);
	}
	else if (((!height || ft_strlen(height) < 1) ||
		!ft_strevery(height, ft_isdigit)) && (error = true))
	{
		ft_error(ft_countnumbers(height) > 2 ? "Invalid resolution. Found %s" :
		"Invalid height. Found %s", false, height);
	}
	else if (((ft_atoll(width) > game->tmp.width || ft_atoll(width) == 0) ||
	ft_atoll(height) > game->tmp.height || ft_atoll(height) == 0))
	{
		ft_warn("Bad resolution size!\n\tSetting resolution to %ux%u",
			game->tmp.width, game->tmp.height);
		return (2);
	}
	return (!error);
}

void		invalid_screen(t_game *game, char **size)
{
	ft_split_del(size);
	game->valid.screen = false;
}
