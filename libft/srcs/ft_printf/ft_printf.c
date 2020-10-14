/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborboll <aborboll@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/24 18:43:19 by aborboll          #+#    #+#             */
/*   Updated: 2020/10/13 10:15:09 by aborboll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

void	print(t_info *info)
{
	int i;

	i = 0;
	if (info->flags[F_Neg] && info->flags[F_Trash])
		ft_putchar((char)0);
	while (*info->res != '\0' && info->res[i])
	{
		ft_putchar((char)info->res[i]);
		i++;
	}
	if (!info->flags[F_Neg] && info->flags[F_Trash])
		ft_putchar((char)0);
	if (ft_strlen(info->str[0]) > 0)
		(info->str[0])++;
	info->count += i;
}

void	check_and_print(t_info *info)
{
	(info->str[0])++;
	check_flags(info);
	check_width(info);
	check_for_precision(info);
	check_for_lengths(info);
	check_type(info);
	if (info->type)
	{
		if (info->type == 's' || info->type == 'S')
			do_string(info);
		if (info->type == 'i' || info->type == 'd' || info->type == 'u')
			do_number(info, 0);
		else if (info->type == 'o' || info->type == 'O')
			do_octal(info);
		else if (info->type == 'x' || info->type == 'X')
			do_hex(info);
		else if (info->type == 'c' || info->type == 'C')
			do_char(info);
		else if (info->type == 'p' || info->type == 'P')
			do_address(info);
		else if (info->type == '%')
			do_percentage(info);
		print(info);
	}
	reinit(info);
}

int		ft_printf(char *format, ...)
{
	va_list args;
	int		result;

	va_start(args, format);
	result = ft_fprintf(1, format, args);
	va_end(args);
	return (result);
}
