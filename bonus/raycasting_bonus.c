/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborboll <aborboll@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/17 13:16:37 by aborboll          #+#    #+#             */
/*   Updated: 2020/10/24 13:34:27 by aborboll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

void			floor_ceiling(t_game *game)
{
	t_texture	floor_texture;
	t_texture	ceiling_texture;

	floor_texture = game->textures.floor;
	ceiling_texture = game->textures.ceiling;
	for(int y = 0; y < game->height; y++)
	{
		double rayDirX0 = game->dir.x - game->plane.x;
		double rayDirY0 = game->dir.y - game->plane.y;
		double rayDirX1 = game->dir.x + game->plane.x;
		double rayDirY1 = game->dir.y + game->plane.y;
		int p = y - game->height / 2;
		double posZ = 0.5 * game->height;
		double rowDistance = posZ / p;
		double floorStepX = rowDistance * (rayDirX1 - rayDirX0) / game->width;
		double floorStepY = rowDistance * (rayDirY1 - rayDirY0) / game->width;
		double floorX = game->player.x + rowDistance * rayDirX0;
		double floorY = game->player.y + rowDistance * rayDirY0;
		for(int x = 0; x < game->width; ++x)
		{
			// the cell coord is simply got from the integer parts of floorX and floorY
			int cellX = (int)(floorX);
			int cellY = (int)(floorY);

			// get the texture coordinate from the fractional part
			int tx_f = (int)(floor_texture.width * (floorX - cellX)) & (floor_texture.width - 1);
			int ty_f = (int)(floor_texture.height * (floorY - cellY)) & (floor_texture.height - 1);

			int tx_c = (int)(ceiling_texture.width * (floorX - cellX)) & (ceiling_texture.width - 1);
			int ty_c = (int)(ceiling_texture.height * (floorY - cellY)) & (ceiling_texture.height - 1);
			floorX += floorStepX;
			floorY += floorStepY;
			// choose texture and draw the pixel
			int color;
			// floor
			color = floor_texture.ptr[floor_texture.width * ty_f + tx_f];
			set_pixel(game, game->width * y + x, ft_color(color, rowDistance));
			// ceiling
  			color = ceiling_texture.ptr[ceiling_texture.width * ty_c + tx_c];
			set_pixel(game, game->width * (game->height - y - 1) + x, ft_color(color, rowDistance));
		}
	}
}

void			raycasting(t_game *game)
{
	t_ray	ray;

	game->x = -1;
	floor_ceiling(game);
	while (++game->x < game->width)
	{
		ray = cast_texture(game, cast_ray(game, game->x));
		draw_textured_line(game, ray.start, ray.end, ray);
	}
	draw_sprites(game);
	if (game->bmp)
	{
		take_screenshot(game);
		clear_memory(game);
		exit(EXIT_SUCCESS);
	}
	mlx_put_image_to_window(game->mlx, game->win, game->img.img_ptr, 0, 0);
}
