/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborboll <aborboll@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 10:18:33 by aborboll          #+#    #+#             */
/*   Updated: 2020/10/26 16:19:59 by aborboll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

void			order_sprites(t_game *game, t_sprites sprites)
{
	size_t		i;
	size_t		k;
	t_sprite	tmp;

	if (sprites.count == 0)
		return ;
	i = -1;
	while (++i < sprites.count)
		sprites.data[i].d = hypot(sprites.data[i].x -
			game->player.x, sprites.data[i].y - game->player.y);
	i = -1;
	while (++i < sprites.count - 1)
	{
		k = i;
		while (++k < sprites.count)
		{
			if (sprites.data[i].d < sprites.data[k].d)
			{
				tmp = sprites.data[i];
				sprites.data[i] = sprites.data[k];
				sprites.data[k] = tmp;
			}
		}
	}
}

t_sprite		init_sprite(t_game *game, t_sprite sprite)
{
	sprite.x = sprite.x - game->player.x;
	sprite.y = sprite.y - game->player.y;
	sprite.inv_det = 1.0 / (game->plane.x * game->dir.y - game->dir.x
		* game->plane.y);
	sprite.transform.x = sprite.inv_det * (game->dir.y * sprite.x - game->dir.x
		* sprite.y);
	sprite.transform.y = sprite.inv_det * (-game->plane.y * sprite.x +
		game->plane.x * sprite.y);
	sprite.screen_x = (int)((game->width / 2) *
		(1 + sprite.transform.x / sprite.transform.y));
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
	return (sprite);
}

void			draw_sprite(t_game *game, t_texture sp, t_sprite s)
{
	int			x;
	int			y;
	int			k;
	t_texture	t;

	x = s.start.x - 1;
	t = sp;
	while (++x < s.end.x)
	{
		s.texture.x = (x - (-s.width / 2 + s.screen_x)) * t.width / s.width;
		if (s.transform.y > 0 && x > 0 && x < game->width &&
			s.transform.y < game->zbuffer[x])
		{
			y = s.start.y - 1;
			while (++y < s.end.y)
			{
				k = y * 256 - game->height * 128 + s.height * 128;
				s.texture.y = ((k * t.height) / s.height) / 256;
				s.color = t.ptr[t.width * s.texture.y + s.texture.x];
				if ((s.color & 0x00ffffff) != 0)
					set_pixel(game, game->width * y + x,
						ft_color(s.color, s.d));
			}
		}
	}
}

void			draw_sprites(t_game *game)
{
	size_t		i;

	i = -1;
	order_sprites(game, game->sprites);
	order_sprites(game, game->sprites1);
	i = -1;
	while (++i < game->sprites.count)
		draw_sprite(game, game->textures.sprite,
			init_sprite(game, game->sprites.data[i]));
	i = -1;
	while (++i < game->sprites1.count)
		draw_sprite(game, game->textures.sprite1,
			init_sprite(game, game->sprites1.data[i]));
}

void			set_sprites(t_game *game, size_t i, size_t z)
{
	size_t		y;
	size_t		x;

	if (valid_cub_struct(game) && has_map(game, false))
	{
		game->zbuffer = malloc(sizeof(double) * game->width);
		game->sprites.data = malloc(sizeof(t_sprite) * game->sprites.count);
		game->sprites1.data = malloc(sizeof(t_sprite) * game->sprites1.count);
		y = -1;
		while (game->map[++y])
		{
			x = -1;
			while (game->map[y][++x])
			{
				if (game->map[y][x] == '2')
					game->sprites.data[++i] = (t_sprite){.y = (double)y +
						0.5, .x = (double)x + 0.5, .d = (double)0};
				if (game->map[y][x] == '3')
					game->sprites1.data[++z] = (t_sprite){.y = (double)y +
						0.5, .x = (double)x + 0.5, .d = (double)0};
			}
		}
	}
}
