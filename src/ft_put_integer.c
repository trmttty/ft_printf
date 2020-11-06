/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_integer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttarumot <ttarumot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 22:29:31 by ttarumot          #+#    #+#             */
/*   Updated: 2020/07/25 03:04:26 by ttarumot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int		ft_get_radix(const char fmt)
{
	int		radix;

	if (fmt == 'd' || fmt == 'i' || fmt == 'u')
		radix = 10;
	else
		radix = 16;
	return (radix);
}

static size_t	ft_set_number(unsigned long long nb, char *buf, t_info *info)
{
	unsigned long long	un;
	size_t				i;
	int					p;

	un = nb;
	if (info->flags & CAPITAL)
		info->digits = C_DIGITS;
	i = 0;
	if (!(info->dot && info->precision == 0 && nb == 0))
	{
		buf[i++] = info->digits[nb % info->radix];
		while (nb /= info->radix)
			buf[i++] = info->digits[nb % info->radix];
	}
	info->width -= i;
	if (info->sign && info->radix == 10)
		info->width--;
	if (info->flags & ALT && un != 0)
		info->width -= 2;
	p = info->precision - i;
	if (p > 0)
		info->width -= p;
	info->precision -= i;
	return (i);
}

void			ft_put_integer(char fmt, va_list ap, t_info *info, long *done)
{
	char				buf[25];
	unsigned long long	un;
	size_t				i;

	un = ft_get_integer(fmt, ap, info);
	info->radix = ft_get_radix(fmt);
	i = ft_set_number(un, buf, info);
	if ((info->flags & ZERO_PAD) && !info->dot && info->sign)
		ft_put_sign(info, done);
	if (un && (info->flags & ALT) && (info->flags & ZERO_PAD)
		&& !(info->flags & ALT && info->dot && info->flags & ZERO_PAD))
		ft_put_alt(info, done);
	if (!(info->flags & LEFT_AJUST))
		ft_put_pad(info, done);
	if (info->sign)
		ft_put_sign(info, done);
	if (un && (info->flags & ALT))
		ft_put_alt(info, done);
	while (info->precision-- > 0)
		ft_put_count_char('0', done);
	while (i > 0)
		ft_put_count_char(buf[--i], done);
	while (info->width-- > 0)
		ft_put_count_char(info->pad, done);
}
