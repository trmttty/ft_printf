/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttarumot <ttarumot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 14:59:55 by ttarumot          #+#    #+#             */
/*   Updated: 2020/08/17 09:33:33 by ttarumot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	ft_parse_flags(const char **fmt, t_info *info)
{
	while (ft_strchr("-+ #0", **fmt))
	{
		if (**fmt == '-')
			info->flags |= LEFT_AJUST;
		else if (**fmt == '+')
		{
			info->flags |= WITH_SIGN;
			info->sign = '+';
		}
		else if (**fmt == '#')
			info->flags |= ALT;
		else if (**fmt == '0')
			info->flags |= ZERO_PAD;
		else if (**fmt == ' ')
		{
			info->flags |= WITH_SIGN;
			info->sign = ' ';
		}
		(*fmt)++;
	}
}

static void	ft_parse_width(const char **fmt, va_list ap, t_info *info)
{
	if (**fmt == '*')
	{
		info->width = va_arg(ap, int);
		if (info->width < 0)
		{
			info->flags |= LEFT_AJUST;
			info->width = -info->width;
		}
		(*fmt)++;
	}
	else
	{
		while (ft_isdigit(**fmt))
		{
			info->width = info->width * 10 + ft_ctoi(**fmt);
			(*fmt)++;
		}
	}
}

static void	ft_parse_precision(const char **fmt, va_list ap, t_info *info)
{
	info->dot = 1;
	if (**fmt == '*')
	{
		info->precision = va_arg(ap, int);
		if (info->precision < 0)
		{
			info->dot = 0;
			info->precision = 0;
		}
		(*fmt)++;
	}
	else
	{
		while (ft_isdigit(**fmt))
		{
			info->precision = info->precision * 10 + ft_ctoi(**fmt);
			(*fmt)++;
		}
	}
}

void		ft_parse_format(const char **fmt, va_list ap, t_info *info)
{
	ft_parse_flags(fmt, info);
	ft_parse_width(fmt, ap, info);
	if (**fmt == '.')
	{
		(*fmt)++;
		ft_parse_precision(fmt, ap, info);
	}
	while (ft_strchr("hl", **fmt))
	{
		if (**fmt == 'h')
			info->modifier--;
		else
			info->modifier++;
		(*fmt)++;
	}
}
