/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countnumbers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborboll <aborboll@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 17:59:32 by aborboll          #+#    #+#             */
/*   Updated: 2020/10/13 18:35:47 by aborboll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/*
** @author	aborboll
** @param	{char const *str}	The string where count numbers
** @desc	Count numbers in string
** @returns	int
*/

size_t	ft_countnumbers(char const *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i]) && !ft_isdigit(str[i + 1]))
		{
			count++;
		}
		i++;
	}
	return (count);
}
