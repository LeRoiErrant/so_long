/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vheran <vheran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 12:52:27 by vheran            #+#    #+#             */
/*   Updated: 2021/11/24 11:57:24 by vheran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	ft_printfchar_first(char c, t_flags flags)
{
	size_t	l;

	l = 0;
	l += ft_putchar_fd(c, 1);
	if (flags.width != 0)
		l += ft_printf_width(1, flags);
	return (l);
}

static int	ft_printfchar_last(char c, t_flags flags)
{
	size_t	l;

	l = 0;
	if (flags.width != 0)
		l += ft_printf_width(1, flags);
	l += ft_putchar_fd(c, 1);
	return (l);
}

int	ft_printf_char(char c, t_flags flags)
{
	size_t	l;

	l = 0;
	if (flags.minus)
		l += ft_printfchar_first(c, flags);
	else
		l += ft_printfchar_last(c, flags);
	return (l);
}
