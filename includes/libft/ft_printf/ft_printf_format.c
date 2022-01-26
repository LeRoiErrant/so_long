/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_format.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vheran <vheran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 10:27:40 by vheran            #+#    #+#             */
/*   Updated: 2021/11/24 11:57:20 by vheran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_printf_format(va_list args, t_flags flags)
{
	size_t	l;
	char	c;

	l = 0;
	c = flags.type;
	if (c == 'c')
		l = ft_printf_char((char)va_arg(args, int), flags);
	else if (c == 's')
		l = ft_printf_str((char *)va_arg(args, int *), flags);
	else if (c == 'p')
		l = ft_printf_ptr(va_arg(args, unsigned long), flags);
	else if (c == 'i' || c == 'd')
		l = ft_printf_nbr(va_arg(args, int), flags);
	else if (c == 'u')
		l = ft_printf_uns(va_arg(args, unsigned), flags);
	else if (c == 'x')
		l = ft_printf_hex(va_arg(args, unsigned), flags, HEX_LOW);
	else if (c == 'X')
		l = ft_printf_hex(va_arg(args, unsigned), flags, HEX_UP);
	else if (c == '%')
		l = ft_printf_char('%', flags);
	return (l);
}
