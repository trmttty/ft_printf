/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttarumot <ttarumot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 14:28:02 by ttarumot          #+#    #+#             */
/*   Updated: 2020/07/25 10:26:19 by ttarumot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_put_count_char(unsigned char c, long *done)
{
	write(1, &c, 1);
	(*done)++;
}

void	ft_put_sign(t_info *info, long *done)
{
	if (info->radix != 10)
		return ;
	ft_put_count_char(info->sign, done);
	info->sign = 0;
}

void	ft_put_alt(t_info *info, long *done)
{
	ft_put_count_char('0', done);
	if (info->flags & CAPITAL)
		ft_put_count_char('X', done);
	else
		ft_put_count_char('x', done);
	info->flags &= ~ALT;
}

void	ft_put_pad(t_info *info, long *done)
{
	if (info->flags & ZERO_PAD && !info->dot)
		info->pad = '0';
	while (info->width-- > 0)
		ft_put_count_char(info->pad, done);
}
