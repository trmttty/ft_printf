/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_percentage.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttarumot <ttarumot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 23:38:11 by ttarumot          #+#    #+#             */
/*   Updated: 2020/07/25 02:06:50 by ttarumot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_put_percentage(t_info *info, long *done)
{
	info->width--;
	if (!(info->flags & LEFT_AJUST))
	{
		if (info->flags & ZERO_PAD)
			info->pad = '0';
		while (info->width-- > 0)
			ft_put_count_char(info->pad, done);
	}
	ft_put_count_char('%', done);
	while (info->width-- > 0)
		ft_put_count_char(info->pad, done);
}
