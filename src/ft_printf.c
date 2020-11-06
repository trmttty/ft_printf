/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttarumot <ttarumot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 14:23:21 by ttarumot          #+#    #+#             */
/*   Updated: 2020/08/17 07:48:37 by ttarumot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	ft_init_info(t_info *info)
{
	info->flags = 0;
	info->width = 0;
	info->dot = 0;
	info->precision = 0;
	info->modifier = 0;
	info->sign = 0;
	info->pad = ' ';
	info->radix = 10;
	info->digits = S_DIGITS;
}

static int	ft_vprintf(const char *fmt, va_list ap)
{
	t_info	info;
	long	done;

	done = 0;
	while (*fmt)
	{
		if (*fmt != '%')
		{
			ft_put_count_char(*fmt++, &done);
			continue;
		}
		fmt++;
		ft_init_info(&info);
		ft_parse_format(&fmt, ap, &info);
		ft_put_argument(&fmt, ap, &info, &done);
	}
	return (done);
}

static int	ft_check_format(const char *fmt, va_list ap)
{
	t_info	info;

	while (*fmt)
	{
		if (*fmt++ != '%')
			continue;
		ft_init_info(&info);
		ft_parse_format(&fmt, ap, &info);
		if (info.width > 2147483645)
			return (-1);
		if (ft_strchr("pdiuxX", *fmt) && info.precision > 2147483645)
			return (-1);
	}
	return (0);
}

int			ft_printf(const char *fmt, ...)
{
	int		done;
	va_list	ap;

	va_start(ap, fmt);
	done = ft_check_format(fmt, ap);
	va_end(ap);
	if (done == -1)
		return (-1);
	va_start(ap, fmt);
	done = ft_vprintf(fmt, ap);
	va_end(ap);
	return (done);
}
