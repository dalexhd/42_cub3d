/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborboll <aborboll@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 10:57:57 by aborboll          #+#    #+#             */
/*   Updated: 2020/10/10 20:41:12 by aborboll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

void	clear_texture(t_texture texture, void *mlx_ptr)
{
	if (texture.texture)
		mlx_destroy_image(mlx_ptr, texture.texture);
}

void	clear_memory(t_game *game)
{
	free(game->tmp_map);
	if (game->tmp_mlx)
	{
		mlx_destroy_display(game->tmp_mlx);
		free(game->tmp_mlx);
	}
	if (game->map != NULL)
		ft_split_del(game->map);
	free(game);
}
