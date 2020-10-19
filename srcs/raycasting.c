/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborboll <aborboll@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/17 13:16:37 by aborboll          #+#    #+#             */
/*   Updated: 2020/10/19 16:04:54 by aborboll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

void		floor_ceiling(t_game *game)
{
	int		y;
	int		x;
	double	dist;

	y = 0;
	while (y < game->height)
	{
		dist = (0.5 * game->height) / (y - game->height / 2);
		x = 0;
		while (x < game->width)
		{
			set_pixel(game, game->width * y + x,
				ft_color(convert_color(game->colors.floor), dist));
			set_pixel(game, game->width * (game->height - y - 1) + x,
				ft_color(convert_color(game->colors.ceiling), dist));
			x++;
		}
		y++;
	}
}

void		raycasting(t_game *game)
{
	t_ray	ray;

	game->x = -1;
	floor_ceiling(game);
	while (++game->x < game->width)
	{
		ray = cast_texture(game, cast_ray(game, game->x));
		draw_textured_line(game, ray.start, ray.end, ray);
	}
	mlx_put_image_to_window(game->mlx, game->win, game->img.img_ptr, 0, 0);
}
