/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborboll <aborboll@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 17:45:59 by aborboll          #+#    #+#             */
/*   Updated: 2020/10/12 02:48:40 by aborboll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

void	invalid_color(t_game *game)
{
	clear_memory(game);
	game->valid.colors = false;
}

int		parse_color(t_game *game, char *color)
{
	char	*tmp;
	int		result;

	tmp = NULL;
	if ((tmp = ft_strtrim(color, " ")) && validate_color(tmp))
	{
		result = ft_atoi(tmp);
		free(tmp);
		return (result);
	}
	if (color == NULL)
		validate_color(color);
	free(tmp);
	invalid_color(game);
	return (-1);
}

void	parse_floor(t_game *game, char *line)
{
	char	**colors;
	char	*trimmed_color;

	if (ft_strnstr(line, "F ", 2) &&
		(trimmed_color = ft_strtrim(line, "F ")) &&
		(colors = ft_split(trimmed_color, ',')))
	{
		if (has_floor(game))
		{
			ft_error("ERR: Floor already defined!", false);
			game->valid.colors = false;
			free(trimmed_color);
			ft_split_del(colors);
			return ;
		}
		if (ft_countchars(trimmed_color, ',') != 2)
			ft_memcpy(colors[0], trimmed_color, ft_strlen(trimmed_color));
		free(trimmed_color);
		game->colors.floor = (t_color){
			.r = parse_color(game, game->valid.colors ? colors[0] :
			trimmed_color),
			.g = parse_color(game, game->valid.colors ? colors[1] :
			"0"),
			.b = parse_color(game, game->valid.colors ? colors[2] :
			"0"),
		};
		ft_split_del(colors);
	}
}

void	parse_ceiling(t_game *game, char *line)
{
	char	**colors;
	char	*trimmed_color;

	if (ft_strnstr(line, "C ", 2) &&
		(trimmed_color = ft_strtrim(line, "C ")) &&
		(colors = ft_split(trimmed_color, ',')))
	{
		if (has_ceiling(game))
		{
			ft_error("ERR: Ceiling already defined!", false);
			game->valid.colors = false;
			free(trimmed_color);
			ft_split_del(colors);
			return ;
		}
		if (ft_countchars(trimmed_color, ',') != 2)
			ft_memcpy(colors[0], trimmed_color, ft_strlen(trimmed_color));
		game->colors.ceiling = (t_color){
			.r = parse_color(game, game->valid.colors ? colors[0] :
			trimmed_color),
			.g = parse_color(game, game->valid.colors ? colors[1] :
			"0"),
			.b = parse_color(game, game->valid.colors ? colors[2] :
			"0"),
		};
		free(trimmed_color);
		ft_split_del(colors);
	}
}
