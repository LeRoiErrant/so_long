/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_width.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vheran <vheran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 12:42:24 by vheran            #+#    #+#             */
/*   Updated: 2021/11/24 11:56:51 by vheran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	ft_printf_width_str(int len, t_flags flags)
{
	int	l;
	int	i;

	l = 0;
	i = 0;
	if (flags.zero == 1 && flags.dot < 0)
		while ((flags.width - (i++)) - len > 0)
			l += ft_putchar_fd('0', 1);
	else
		while ((flags.width--) - len > 0)
			l += ft_putchar_fd(' ', 1);
	return (l);
}

int	ft_printf_width(int len, t_flags flags)
{
	int		l;
	char	t;

	l = 0;
	t = flags.type;
	if (t == 'i' || t == 'd' || t == 'u' || t == 'x' || t == 'X' || t == '%')
		l += ft_printf_width_nbr(len, flags);
	else
		l += ft_printf_width_str(len, flags);
	return (l);
}
