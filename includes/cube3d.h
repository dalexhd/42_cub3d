/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborboll <aborboll@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/31 07:32:52 by aborboll          #+#    #+#             */
/*   Updated: 2020/10/07 17:11:42 by aborboll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_H
# define CUBE3D_H

/*
** Include our libraries.
*/
# include "../libft/includes/libft.h"
# include "../libft/includes/color.h"
# ifdef __linux__
#  include "../minilibx/linux/mlx.h"
# elif __APPLE__
#  include "../minilibx/opengl/mlx.h"
# endif

/*
** We assign the corresponding SO keyboard layout.
*/
# ifdef __linux__
#  include "keyboard/linux.h"
# elif __APPLE__
#  include "keyboard/darwin.h"
# endif

/*
** Include necessary libraries.
*/
# include <stdarg.h>
# include <mlx.h>
# include <stdio.h>

/*
** Include our game global settings.
*/
# include "settings.h"

/*
** Include internal values of the cub3d.
*/
# include "internal.h"

typedef struct	s_img
{
	void		*img_ptr;
	int			*data;
	int			width;
	int			height;
	int			size_l;
	int			bpp;
	int			endian;
}				t_img;

typedef struct	s_texture
{
	char		*path;
	int			*ptr;
	void		*texture;
	int			start;
	int			end;
	int			width;
	int			height;
	int			size_l;
	int			bpp;
	int			endian;
}				t_texture;

typedef struct	s_textures
{
	t_texture	north;
	t_texture	south;
	t_texture	east;
	t_texture	west;
	t_texture	sprite;
	t_texture	floor;
	t_texture	ceiling;
}				t_textures;

typedef struct	s_move
{
	t_bool		forward;
	t_bool		backward;
	t_bool		right;
	t_bool		left;
}				t_move;

typedef struct	s_rotate
{
	t_bool		right;
	t_bool		left;
}				t_rotate;

typedef struct	s_player
{
	double		x;
	double		y;
	double		deg;
	double		speed;
	double		rotate_speed;
	t_move		moving;
	t_rotate	rotating;
	t_bool		shifting;
}				t_player;

typedef struct	s_color
{
	int			r;
	int			g;
	int			b;
}				t_color;

typedef struct	s_colors
{
	t_color		floor;
	t_color		ceiling;
}				t_colors;

typedef struct	s_direction
{
	double		x;
	double		y;
}				t_direction;

typedef struct	s_ivector
{
	int			x;
	int			y;
}				t_ivector;

typedef struct	s_ray
{
	t_direction	dir;
	t_direction	side;
	t_direction	delta;
	t_ivector	step;
	t_ivector	map;
	t_bool		is_north;
	t_texture	texture;
	int			start;
	int			end;
	int			height;
	double		shade;
	double		dist;
	int			wall_direction;
	int			texture_x;
	double		texture_step;
	double		texture_pos;
}				t_ray;

typedef struct	s_game
{
	void		*mlx;
	void		*tmp_mlx;
	void		*win;
	int			width;
	int			height;
	int			x;
	char		**map;
	int			minimap;
	t_img		img;
	t_ray		*rays;
	t_colors	colors;
	t_player	player;
	t_direction	dir;
	t_textures	textures;
	t_direction	plane;
}				t_game;

#endif
