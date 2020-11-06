/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttarumot <ttarumot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 14:00:49 by ttarumot          #+#    #+#             */
/*   Updated: 2020/08/17 07:47:46 by ttarumot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include "libft.h"
# include <stdarg.h>

# define ZERO_PAD		1
# define ALT			2
# define CAPITAL		4
# define WITH_SIGN		8
# define LEFT_AJUST		16

# define LL	2
# define L	1
# define I	0
# define S	-1
# define C	-2

# define S_DIGITS "0123456789abcdef"
# define C_DIGITS "0123456789ABCDEF"

typedef struct			s_info
{
	char				flags;
	int					width;
	int					dot;
	int					precision;
	char				modifier;
	char				sign;
	char				pad;
	int					radix;
	char				*digits;
}						t_info;

int						ft_printf(const char *fmt, ...);
void					ft_put_integer(char fmt, va_list ap,
										t_info *info, long *done);
void					ft_put_percentage(t_info *info, long *done);
void					ft_put_pointer(va_list ap, t_info *info, long *done);
void					ft_put_character(va_list ap, t_info *info, long *done);
void					ft_put_string(va_list ap, t_info *info, long *done);
unsigned long long		ft_get_integer(const char fmt, va_list ap,
											t_info *info);
unsigned long long		ft_get_unsigned(va_list ap, int type);
long long				ft_get_signed(va_list ap, int type);
void					ft_put_count_char(unsigned char c, long *done);
void					ft_put_sign(t_info *info, long *done);
void					ft_put_alt(t_info *info, long *done);
void					ft_put_pad(t_info *info, long *done);
void					ft_parse_format(const char **fmt, va_list ap,
											t_info *info);
void					ft_put_argument(const char **fmt, va_list ap,
											t_info *info, long *done);

#endif
