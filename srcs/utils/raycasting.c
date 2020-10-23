/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborboll <aborboll@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/17 13:55:49 by aborboll          #+#    #+#             */
/*   Updated: 2020/10/22 13:56:12 by aborboll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

t_bool			is_side(t_ray ray)
{
	return (ray.wall_direction != WEST && ray.wall_direction != EAST);
}

int				ray_direction(t_ray ray)
{
	if (ray.side.x > ray.side.y)
		return (ray.dir.y < 0 ? NORTH : SOUTH);
	return (ray.dir.x < 0 ? WEST : EAST);
}

t_texture		ray_texture(t_game *game, t_ray ray)
{
	t_texture	texture;

	if (ray.wall_direction == NORTH)
		texture = game->textures.north;
	if (ray.wall_direction == SOUTH)
		texture = game->textures.south;
	if (ray.wall_direction == WEST)
		texture = game->textures.west;
	if (ray.wall_direction == EAST)
		texture = game->textures.east;
	return (texture);
}

t_ray			setup_ray(t_game *game, int x)
{
	t_ray		ray;
	double		camera_x;

	camera_x = 2 * x / (double)game->width - 1;
	ray.dir = (t_direction){.x = game->dir.x + game->plane.x * camera_x,
		.y = game->dir.y + game->plane.y * camera_x};
	ray.delta = (t_direction){.x = fabs(1 / ray.dir.x),
		.y = fabs(1 / ray.dir.y)};
	ray.step = (t_ivector){.x = ray.dir.x < 0 ? -1 : 1,
		.y = ray.dir.y < 0 ? -1 : 1};
	ray.map = (t_ivector){.x = (int)game->player.x, .y = (int)game->player.y};
	ray.side = (t_direction){.x = ray.dir.x < 0 ?
		(game->player.x - ray.map.x) * ray.delta.x :
		(ray.map.x + 1.0 - game->player.x) * ray.delta.x,
		.y = ray.dir.y < 0 ? (game->player.y - ray.map.y) * ray.delta.y :
		(ray.map.y + 1.0 - game->player.y) * ray.delta.y
	};
	return (ray);
}

t_ray			cast_texture(t_game *game, t_ray ray)
{
	double		wall_x;

	if (!is_side(ray))
		wall_x = game->player.y + ray.dist * ray.dir.y;
	else
		wall_x = game->player.x + ray.dist * ray.dir.x;
	wall_x -= floor(wall_x);
	ray.texture_x = wall_x * (double)ray.texture.width;
	ray.texture_step = (double)ray.texture.height / ray.height;
	ray.texture_pos = (ray.start - game->height / 2 + ray.height / 2)
		* ray.texture_step;
	return (ray);
}

t_ray			cast_ray(t_game *game, int x)
{
	t_ray		ray;
	t_bool		hit;

	ray = setup_ray(game, x);
	hit = false;
	while (hit == false)
	{
		ray.wall_direction = ray_direction(ray);
		ray.texture = ray_texture(game, ray);
		if (ray.side.x < ray.side.y)
		{
			ray.side.x += ray.delta.x;
			ray.map.x += ray.step.x;
		}
		else
		{
			ray.side.y += ray.delta.y;
			ray.map.y += ray.step.y;
		}
		if (game->map[ray.map.y][ray.map.x] == '1')
			hit = true;
	}
	if (!is_side(ray))
		ray.dist = (ray.map.x - game->player.x + (1 - ray.step.x) / 2) / ray.dir.x;
	else
		ray.dist = (ray.map.y - game->player.y + (1 - ray.step.y) / 2) / ray.dir.y;
	ray.height = (int)(game->height / ray.dist);
	ray.start = -ray.height / 2 + game->height / 2;
	ray.end = ray.height / 2 + game->height / 2;
	if (ray.start < 0)
		ray.start = 0;
	if (ray.end >= game->height)
		ray.end = game->height - 1;
	if (ray.end < 0)
		ray.end = 0;
	game->zbuffer[x] = ray.dist;
	return (ray);
}
