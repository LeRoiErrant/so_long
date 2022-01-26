/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_width_nbr.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vheran <vheran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 12:17:53 by vheran            #+#    #+#             */
/*   Updated: 2022/01/11 11:06:25 by vheran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	ft_printf_zero(int len, t_flags flags)
{
	int	l;
	int	i;

	l = 0;
	i = 0;
	if (flags.neg)
		l += ft_putchar_fd('-', 1);
	else if (flags.space || flags.plus)
		l += ft_putchar_fd(flags.pos, 1);
	if (flags.zero == 1 && flags.dot < 0)
		while ((flags.width - (i++)) - len > 0)
			l += ft_putchar_fd('0', 1);
	else if (!flags.width && flags.dot >= 0 && !flags.minus)
		while ((flags.dot - (i++)) - len > 0)
			l += ft_putchar_fd('0', 1);
	else
		while ((flags.dot - (i++)) - len > 0)
			l += ft_putchar_fd('0', 1);
	return (l);
}

static int	ft_printf_zero_n_space(int len, t_flags flags)
{
	int	l;
	int	i;

	l = 0;
	i = 0;
	if (flags.dot > len)
	{
		while (((flags.width + len) - (i++)) - (flags.dot + len) > 0)
			l += ft_putchar_fd(' ', 1);
		i = 0;
		if (flags.neg)
			l += ft_putchar_fd('-', 1);
		else if (flags.space || flags.plus)
			l += ft_putchar_fd(flags.pos, 1);
		while ((flags.dot - (i++)) - (len) > 0)
			l += ft_putchar_fd('0', 1);
		return (l);
	}
	while ((flags.width - (i++)) - (len) > 0)
		l += ft_putchar_fd(' ', 1);
	if (flags.neg)
		l += ft_putchar_fd('-', 1);
	else if (flags.space || flags.plus)
		l += ft_putchar_fd(flags.pos, 1);
	return (l);
}

static int	ft_printf_space(int len, t_flags flags)
{
	int	l;

	l = 0;
	while ((flags.width--) - len > 0)
		l += ft_putchar_fd(' ', 1);
	if (flags.neg)
		l += ft_putchar_fd('-', 1);
	else if (flags.space || flags.plus)
		l += ft_putchar_fd(flags.pos, 1);
	return (l);
}

int	ft_printf_width_nbr(int len, t_flags flags)
{
	int	l;

	l = 0;
	if (flags.zero == 1 && flags.dot < 0)
		l += ft_printf_zero(len, flags);
	else if (!flags.width && flags.dot >= 0)
		l += ft_printf_zero(len, flags);
	else if (flags.width && flags.dot >= 0 && !flags.minus)
		l += ft_printf_zero_n_space(len, flags);
	else if (flags.width && flags.dot >= 0 && flags.minus)
		l += ft_printf_zero(len, flags);
	else
		l += ft_printf_space(len, flags);
	return (l);
}
