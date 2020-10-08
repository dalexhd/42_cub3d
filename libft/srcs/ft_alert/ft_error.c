/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborboll <aborboll@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 15:15:10 by aborboll          #+#    #+#             */
/*   Updated: 2020/10/08 17:59:42 by aborboll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	ft_error(char *s, t_bool close)
{
	ft_printf(C_RED"❌ %s\n"C_CLEAR, s);
	if (close)
		exit(EXIT_FAILURE);
}
