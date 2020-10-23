/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborboll <aborboll@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 10:18:33 by aborboll          #+#    #+#             */
/*   Updated: 2020/10/23 09:53:44 by aborboll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

void			order_sprites(t_game *game)
{
	size_t		i;
	size_t		k;
	t_sprite	tmp;

	i = 0;
	while (i < game->sprites.count - 1)
	{
		k = i + 1;
		while (k < game->sprites.count)
		{
			if (game->sprites.data[i].d < game->sprites.data[k].d)
			{
				tmp = game->sprites.data[i];
				game->sprites.data[i] = game->sprites.data[k];
				game->sprites.data[k] = tmp;
			}
			k++;
		}
		i++;
	}
}

void			draw_sprites(t_game *game)
{
	size_t		i;
	int			y;
	int			x;
	t_sprite	sprite;

	i = -1;
	while (++i < game->sprites.count)
	{
		sprite = game->sprites.data[i];
		game->sprites.data[i].d = hypot(sprite.x - game->player.x,
			sprite.y - game->player.y);
	}
	order_sprites(game);
	i = -1;
	while (++i < game->sprites.count)
	{
		sprite = game->sprites.data[i];
		sprite.x = sprite.x - game->player.x;
		sprite.y = sprite.y - game->player.y;
		sprite.inv_det = 1.0 / (game->plane.x * game->dir.y - game->dir.x * game->plane.y);
		sprite.transform.x = sprite.inv_det * (game->dir.y * sprite.x - game->dir.x * sprite.y);
		sprite.transform.y = sprite.inv_det * (-game->plane.y * sprite.x + game->plane.x * sprite.y);
		sprite.screen_x = (int)((game->width / 2) * (1 + sprite.transform.x / sprite.transform.y));
		sprite.height = abs((int)(game->height / (sprite.transform.y)));
		sprite.start.y = -sprite.height / 2 + game->height / 2;
		if (sprite.start.y < 0)
			sprite.start.y = 0;
		sprite.end.y = sprite.height / 2 + game->height / 2;
		if (sprite.end.y >= game->height)
			sprite.end.y = game->height - 1;
		sprite.width = fabs((int)(game->height / (sprite.transform.y)));
		sprite.start.x = -sprite.width / 2 + sprite.screen_x;
		if (sprite.start.x < 0)
			sprite.start.x = 0;
		sprite.end.x = sprite.width / 2 + sprite.screen_x;
		if (sprite.end.x >= game->width)
			sprite.end.x = game->width - 1;
		x = sprite.start.x - 1;
		while (++x < sprite.end.x)
		{
			sprite.texture.x = (int)(256 * (x - (-sprite.width / 2 + sprite.screen_x)) * game->textures.sprite.width / sprite.width) / 256;
			if (sprite.transform.y > 0 && x > 0 && x < game->width && sprite.transform.y < game->zbuffer[x])
			{
				y = sprite.start.y - 1;
				while (++y < sprite.end.y)
				{
					sprite.d = (y) * 256 - game->height * 128 + sprite.height * 128;
					sprite.texture.y = ((sprite.d * game->textures.sprite.height) / sprite.height) / 256;
					sprite.color = game->textures.sprite.ptr[game->textures.sprite.width * sprite.texture.y + sprite.texture.x];
					if ((sprite.color & 0x00FFFFFF) != 0)
						set_pixel(game, game->width * y + x, sprite.color);
				}
			}
		}
	}
}

void			set_sprites(t_game *game)
{
	size_t		y;
	size_t		x;
	size_t		i;

	game->zbuffer = malloc(sizeof(double) * game->width);
	game->sprites.data = malloc(sizeof(t_sprite) * game->sprites.count);
	y = -1;
	i = -1;
	while (game->map[++y])
	{
		x = -1;
		while (game->map[y][++x])
			if (game->map[y][x] == '2')
				game->sprites.data[++i] = (t_sprite){.y = (double)y + 0.5,
					.x = (double)x + 0.5, .d = (double)0};
	}
}
