/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alert.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborboll <aborboll@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/24 17:55:19 by aborboll          #+#    #+#             */
/*   Updated: 2020/10/08 18:01:57 by aborboll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ALERT_H
# define FT_ALERT_H

# include "types.h"
# include "color.h"

void	ft_error(char *s, t_bool close);
void	ft_warn(char *s);

#endif
