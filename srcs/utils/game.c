/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborboll <aborboll@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/17 12:46:18 by aborboll          #+#    #+#             */
/*   Updated: 2020/10/17 12:51:58 by aborboll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

int		main_loop(t_game *game)
{
	if (is_moving(game))
		ft_move(game);
	if (is_rotating(game))
		ft_rotate(game);
	ft_shift(game);
	return (TRUE);
}
