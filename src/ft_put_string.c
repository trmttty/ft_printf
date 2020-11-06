/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_string.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttarumot <ttarumot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 00:54:58 by ttarumot          #+#    #+#             */
/*   Updated: 2020/08/15 10:50:27 by ttarumot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_put_string(va_list ap, t_info *info, long *done)
{
	char	*s;
	size_t	len;

	s = (char*)va_arg(ap, const char *);
	if (s == NULL)
		s = "(null)";
	len = ft_strlen(s);
	if (info->dot && (size_t)info->precision < len)
		len = info->precision;
	info->width -= len;
	if (!(info->flags & LEFT_AJUST))
	{
		if (info->flags & ZERO_PAD)
			info->pad = '0';
		while (info->width-- > 0)
			ft_put_count_char(info->pad, done);
	}
	while (len--)
		ft_put_count_char(*s++, done);
	while (info->width-- > 0)
		ft_put_count_char(' ', done);
}
