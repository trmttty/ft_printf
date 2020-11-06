/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_argument.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttarumot <ttarumot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 17:57:53 by ttarumot          #+#    #+#             */
/*   Updated: 2020/07/25 16:13:53 by ttarumot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	ft_set_pointer(va_list ap, t_info *info, long *done)
{
	if (info->modifier >= LL)
		*(va_arg(ap, long long*)) = *done;
	else if (info->modifier == L)
		*(va_arg(ap, long*)) = *done;
	else if (info->modifier == I)
		*(va_arg(ap, int*)) = *done;
	else if (info->modifier == S)
		*(va_arg(ap, short*)) = *done;
	else if (info->modifier <= C)
		*(va_arg(ap, char*)) = *done;
}

void		ft_put_argument(const char **fmt, va_list ap,
							t_info *info, long *done)
{
	if (ft_strchr("diuxX", **fmt))
	{
		if (**fmt == 'X')
			info->flags |= CAPITAL;
		ft_put_integer(**fmt, ap, info, done);
	}
	else if (**fmt == 'p')
		ft_put_pointer(ap, info, done);
	else if (**fmt == 'c')
		ft_put_character(ap, info, done);
	else if (**fmt == 's')
		ft_put_string(ap, info, done);
	else if (**fmt == '%')
		ft_put_percentage(info, done);
	else if (**fmt == 'n')
		ft_set_pointer(ap, info, done);
	else
	{
		while (**fmt != '%')
			(*fmt)--;
	}
	(*fmt)++;
}
