/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborboll <aborboll@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 17:45:59 by aborboll          #+#    #+#             */
/*   Updated: 2020/10/08 22:18:01 by aborboll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

void	invalid_color(t_game *game, char **colors, char *line)
{
	free(colors);
	ft_strdel(&line);
	free(game);
	exit(EXIT_FAILURE);
}

int		parse_color(t_game *game, char *color, char **colors, char *line)
{
	if (validate_color(color))
		return (ft_atoi(color));
	invalid_color(game, colors, line);
	return (0);
}

void	parse_floor(t_game *game, char *line)
{
	char	**colors;
	char	*trimmed_color;

	if (ft_strnstr(line, "F ", 2) &&
		(trimmed_color = ft_strtrim(line, "F ")) &&
		(colors = ft_split(trimmed_color, ',')))
	{
		game->colors.floor = (t_color){
			.r = parse_color(game, colors[0], colors, line),
			.g = parse_color(game, colors[1], colors, line),
			.b = parse_color(game, colors[2], colors, line),
		};
		ft_split_del(colors);
		free(trimmed_color);
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
		game->colors.ceiling = (t_color){
			.r = parse_color(game, colors[0], colors, line),
			.g = parse_color(game, colors[1], colors, line),
			.b = parse_color(game, colors[2], colors, line),
		};
		ft_split_del(colors);
		free(trimmed_color);
	}
}
