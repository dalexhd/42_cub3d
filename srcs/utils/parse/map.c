/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborboll <aborboll@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 16:56:11 by aborboll          #+#    #+#             */
/*   Updated: 2020/10/17 12:22:44 by aborboll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

static	t_bool	is_map_line(char *line)
{
	char		*set;
	char		last_char;
	size_t		i;
	t_bool		has;
	t_bool		has_rev;

	set = " 120NSWE";
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

void			parse_map(t_game *game, char *line)
{
	char		*tmp;

	if (!game->tmp.safe_line && is_map_line(line))
	{
		tmp = game->tmp_map;
		game->tmp_map = ft_strjoin(game->tmp_map, ft_strcat(line, "\n"));
		free(tmp);
	}
}

void			check_player_pos(t_game *game)
{
	size_t		i;
	size_t		valid;

	i = 0;
	valid = 0;
	while (game->tmp_map[i] != '\0')
	{
		if (game->tmp_map[i] == 'S' || game->tmp_map[i] == 'N' ||
			game->tmp_map[i] == 'W' || game->tmp_map[i] == 'E')
		{
			valid++;
			game->spawn = game->tmp_map[i];
		}
		i++;
	}
	if (valid != 1)
		ft_error("Mapp err 1", false);
}

void			fill_map(t_game *game)
{
	t_bool		valid;

	(void)valid;
	if (valid_cub_struct(game))
	{
		if (has_map(game))
		{
			check_player_pos(game);
			game->map = ft_split(game->tmp_map, '\n');
			valid = validate_map(game);
		}
		else
			ft_error(ERR_MAP_MISSING, false);
	}
}
