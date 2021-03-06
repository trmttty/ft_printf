/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttarumot <ttarumot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/25 10:05:08 by ttarumot          #+#    #+#             */
/*   Updated: 2020/08/17 06:41:16 by ttarumot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_wspace(const char c)
{
	return (c == '\t' || c == '\n' || c == '\v' || c == '\f' || c == '\r' \
			|| c == ' ');
}

static long	set_number(const char *str)
{
	long	nb;

	nb = 0;
	while (ft_isdigit(*str))
		nb = nb * 10 + (*str++ - '0');
	return (nb);
}

int			ft_atoi(const char *str)
{
	int		sign;

	sign = 1;
	while (is_wspace(*str))
		str++;
	if (*str == '+')
		str++;
	else if (*str == '-')
	{
		sign = -1;
		str++;
	}
	return ((int)(sign * set_number(str)));
}
