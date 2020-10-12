/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborboll <aborboll@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 19:50:27 by aborboll          #+#    #+#             */
/*   Updated: 2020/10/10 20:20:55 by aborboll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

int		parse_file(t_game *game, char *file)
{
	int	fd;

	if (!valid_cubfile(file))
	{
		clear_memory(game);
		exit(EXIT_FAILURE);
	}
	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		clear_memory(game);
		ft_error("Error opening \"%s\" file!", true, file);
	}
	return (fd);
}