/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_pointer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttarumot <ttarumot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 01:13:33 by ttarumot          #+#    #+#             */
/*   Updated: 2020/07/25 11:32:13 by ttarumot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static size_t	set_number(va_list ap, char *buf, t_info *info)
{
	unsigned long long	n;
	size_t				i;

	n = (unsigned long)va_arg(ap, void*);
	i = 0;
	if (!(info->dot && info->precision == 0 && n == 0))
	{
		buf[(i)++] = info->digits[n % 16];
		while (n /= 16)
			buf[(i)++] = info->digits[n % 16];
	}
	info->width -= (i + 2);
	return (i);
}

void			ft_put_pointer(va_list ap, t_info *info, long *done)
{
	char	buf[25];
	size_t	i;

	i = set_number(ap, buf, info);
	if (!(info->flags & LEFT_AJUST) && !(info->flags & ZERO_PAD))
	{
		while (info->width-- > 0)
			ft_put_count_char(' ', done);
	}
	ft_put_count_char('0', done);
	ft_put_count_char('x', done);
	if (!(info->flags & LEFT_AJUST) && (info->flags & ZERO_PAD))
	{
		while (info->width-- > 0)
			ft_put_count_char('0', done);
	}
	info->precision -= i;
	while (info->precision-- > 0)
		ft_put_count_char('0', done);
	while (i > 0)
		ft_put_count_char(buf[--i], done);
	while (info->width-- > 0)
		ft_put_count_char(' ', done);
}
