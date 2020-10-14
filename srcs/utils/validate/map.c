/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborboll <aborboll@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 16:56:33 by aborboll          #+#    #+#             */
/*   Updated: 2020/10/13 20:04:33 by aborboll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

t_bool		has_map(t_game *game)
{
	return (ft_strlen(game->tmp_map) > 0);
}

t_bool		validate_map(char *tmp_map)
{
	(void)tmp_map;
	return (TRUE);
}
