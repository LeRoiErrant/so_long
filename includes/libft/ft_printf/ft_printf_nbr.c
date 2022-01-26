/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_nbr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vheran <vheran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 13:06:52 by vheran            #+#    #+#             */
/*   Updated: 2021/11/24 11:57:10 by vheran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_printfnbr_first(char *nbr, t_flags flags)
{
	size_t	l;

	l = 0;
	if (flags.neg)
		l += ft_putchar_fd('-', 1);
	flags.neg = 0;
	l += ft_putstr_fd(nbr, 1);
	if (flags.width)
		l += ft_printf_width(ft_strlen(nbr), flags);
	return (l);
}

int	ft_printfnbr_middle(char *nbr, t_flags *flags)
{
	int	l;
	int	len;
	int	tmp;

	l = 0;
	len = ft_strlen(nbr);
	if (flags->dot >= len)
	{
		l += ft_printf_width_nbr(len, *flags);
		l += ft_putstr_fd(nbr, 1);
		tmp = flags->dot;
		flags->dot = -1;
		flags->neg = 0;
		l += ft_printf_width_nbr(tmp, *flags);
	}
	else
	{
		flags->dot = -1;
		if (flags->neg)
			l += ft_putchar_fd('-', 1);
		flags->neg = 0;
		l += ft_putstr_fd(nbr, 1);
		l += ft_printf_width_nbr(len, *flags);
	}
	return (l);
}

int	ft_printfnbr_last(char *nbr, t_flags flags)
{
	size_t	l;

	l = 0;
	if (flags.width || flags.dot >= 0)
		l += ft_printf_width(ft_strlen(nbr), flags);
	else if (flags.pos)
		l += ft_putchar_fd(flags.pos, 1);
	else if (flags.neg)
		l += ft_putchar_fd('-', 1);
	l += ft_putstr_fd(nbr, 1);
	return (l);
}

static int	ft_printf_value_zero(t_flags flags)
{
	int	l;

	l = 0;
	flags.minus = 0;
	l += ft_printf_width_nbr(0, flags);
	return (l);
}

int	ft_printf_nbr(int n, t_flags flags)
{
	char				*itoa;
	unsigned int		nb;
	size_t				l;

	l = 0;
	if (n < 0)
	{
		flags.neg = 1;
		nb = -n;
		flags.width--;
	}
	else
		nb = n;
	if (flags.dot == 0 && nb == 0)
		return (l += ft_printf_value_zero(flags));
	itoa = ft_itoa(nb);
	if (flags.minus && flags.dot < 0)
		l += ft_printfnbr_first(itoa, flags);
	else if (flags.width && flags.dot >= 0 && flags.minus)
		l += ft_printfnbr_middle(itoa, &flags);
	else
		l += ft_printfnbr_last(itoa, flags);
	free(itoa);
	return (l);
}
