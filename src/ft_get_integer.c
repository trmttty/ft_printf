/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_integer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttarumot <ttarumot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 14:16:09 by ttarumot          #+#    #+#             */
/*   Updated: 2020/07/25 14:07:24 by ttarumot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

long long			ft_get_signed(va_list ap, int type)
{
	if (type >= LL)
		return (va_arg(ap, long long));
	else if (type == L)
		return (va_arg(ap, long));
	else if (type == I)
		return (va_arg(ap, int));
	else if (type == S)
		return ((short)va_arg(ap, int));
	return ((signed char)va_arg(ap, int));
}

unsigned long long	ft_get_unsigned(va_list ap, int type)
{
	if (type >= LL)
		return (va_arg(ap, unsigned long long));
	else if (type == L)
		return (va_arg(ap, unsigned long));
	else if (type == I)
		return (va_arg(ap, unsigned int));
	else if (type == S)
		return ((unsigned short)va_arg(ap, unsigned int));
	return ((unsigned char)va_arg(ap, unsigned int));
}

unsigned long long	ft_get_integer(const char fmt, va_list ap, t_info *info)
{
	unsigned long long	ui;
	long long			si;

	if (fmt == 'd' || fmt == 'i')
	{
		si = ft_get_signed(ap, info->modifier);
		if (si < 0)
		{
			si = -si;
			info->sign = '-';
		}
		ui = si;
	}
	else
		ui = ft_get_unsigned(ap, info->modifier);
	return (ui);
}
