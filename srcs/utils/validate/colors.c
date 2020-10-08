/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborboll <aborboll@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 16:56:21 by aborboll          #+#    #+#             */
/*   Updated: 2020/10/08 17:58:26 by aborboll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

t_bool	validate_color(char *color)
{
	if (ft_strlen(color) < 1)
	{
		ft_error("Invalid floor ceiling colors length!", false);
		return (FALSE);
	}
	else if (!ft_strevery(color, ft_isdigit))
	{
		ft_error("Invalid floor ceiling colors numbers!", false);
		return (FALSE);
	}
	else if (ft_atoi(color) > 255)
	{
		ft_error("Max color value is 255!", false);
		return (FALSE);
	}
	return (TRUE);
}
