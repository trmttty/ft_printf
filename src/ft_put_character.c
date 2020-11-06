/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_character.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttarumot <ttarumot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 00:39:07 by ttarumot          #+#    #+#             */
/*   Updated: 2020/08/15 10:45:35 by ttarumot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_put_character(va_list ap, t_info *info, long *done)
{
	unsigned char	c;

	c = va_arg(ap, int);
	info->width--;
	if (!(info->flags & LEFT_AJUST))
	{
		if (info->flags & ZERO_PAD)
			info->pad = '0';
		while (info->width-- > 0)
			ft_put_count_char(info->pad, done);
	}
	ft_put_count_char(c, done);
	while (info->width-- > 0)
		ft_put_count_char(info->pad, done);
}
