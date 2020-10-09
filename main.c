/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborboll <aborboll@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 17:26:50 by aborboll          #+#    #+#             */
/*   Updated: 2020/10/09 13:59:18 by aborboll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cube3d.h"

int	main(int argc, char **argv)
{
	t_game	*game;

	game = init_game(argc, argv);
	ft_split_del(game->map);
	free(game);
	return (TRUE);
}
