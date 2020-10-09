/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborboll <aborboll@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 16:56:11 by aborboll          #+#    #+#             */
/*   Updated: 2020/10/09 14:01:23 by aborboll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

t_bool		is_map_line(char *line)
{
	char	*set;
	char	last_char;
	size_t	i;
	t_bool	has;
	t_bool	has_rev;

	set = " 120N";
	last_char = line[ft_strlen(line) - 1];
	has = FALSE;
	has_rev = FALSE;
	i = -1;
	while (++i < ft_strlen(set))
		if (line[0] == set[i])
			has = TRUE;
	i = -1;
	while (++i < ft_strlen(set))
		if (last_char == set[i])
			has_rev = TRUE;
	return (has && has_rev);
}

void		parse_map(t_game *game, char *line)
{
	char	*tmp;

	if (has_screen(game) && has_colors(game) &&
	has_textures(game) && is_map_line(line))
	{
		tmp = game->tmp_map;
		game->tmp_map = ft_strjoin(tmp, ft_strcat(line, "\n"));
		free(tmp);
	}
}

void		fill_map(t_game *game)
{
	if (validate_map(game->tmp_map))
	{
		game->map = ft_split(game->tmp_map, '\n');
		free(game->tmp_map);
	}
}
