/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screenshot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborboll <aborboll@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 15:44:21 by aborboll          #+#    #+#             */
/*   Updated: 2020/10/23 10:24:48 by aborboll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

static	void			int_char(t_uchar *src, int nb)
{
	src[0] = (t_uchar)(nb);
	src[1] = (t_uchar)(nb >> 8);
	src[2] = (t_uchar)(nb >> 16);
	src[3] = (t_uchar)(nb >> 24);
}

static	void			bmp_header(t_game *game, int fd, int size)
{
	int					y;
	static t_uchar		bmp_header[54];

	y = -1;
	while (++y < 54)
		bmp_header[y] = 0;
	bmp_header[0] = (t_uchar)'B';
	bmp_header[1] = (t_uchar)'M';
	int_char(bmp_header + 2, size);
	bmp_header[10] = (t_uchar)(54);
	bmp_header[14] = (t_uchar)(40);
	int_char(bmp_header + 18, game->width);
	int_char(bmp_header + 22, game->width);
	bmp_header[26] = (unsigned char)(1);
	bmp_header[28] = (unsigned char)(24);
	write(fd, bmp_header, 54);
}

static void				bmp_pixels(t_game *game, int fd, int pad)
{
	unsigned char		zero[3];
	int					y;
	int					x;
	int					color;

	y = -1;
	while (++y < 3)
		zero[y] = 0;
	y = -1;
	while (++y < game->height)
	{
		x = -1;
		while (++x < game->width)
		{
			color = game->img.data[game->width * (game->height - 1 - y) + x];
			write(fd, &color, 3);
			write(fd, &zero, pad);
		}
	}
}

int						take_screenshot(t_game *game)
{
	int					fd;
	int					size;
	int					pad;

	pad = (4 - (game->width * 3) % 4) % 4;
	size = 54 + (3 * (game->width + pad) * game->height);
	if ((fd = open("screenshot.bmp", O_WRONLY | O_CREAT, 0666)) < 0)
		return (0);
	bmp_header(game, fd, size);
	bmp_pixels(game, fd, pad);
	close(fd);
	return (1);
}
