/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_warn.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborboll <aborboll@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 15:15:10 by aborboll          #+#    #+#             */
/*   Updated: 2020/10/10 22:05:16 by aborboll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void		ft_warn(char *s, ...)
{
	va_list args;

	va_start(args, s);
	ft_printf(C_YELLOW"⚠️ ");
	ft_vprintf(s, &args);
	ft_printf(C_X"\n");
	va_end(args);
}
