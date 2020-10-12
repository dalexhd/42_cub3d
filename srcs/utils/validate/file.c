/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborboll <aborboll@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 19:49:10 by aborboll          #+#    #+#             */
/*   Updated: 2020/10/10 21:25:11 by aborboll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

t_bool		valid_cubfile(char *file)
{
	if (!ft_strendswith(file, ".cub"))
	{
		ft_error("ARGV ERROR: Use: ./CUB3D [file].cub"C_X, false);
		return (false);
	}
	return (true);
}
