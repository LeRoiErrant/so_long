/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vheran <vheran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 18:33:20 by vheran            #+#    #+#             */
/*   Updated: 2022/01/11 11:06:01 by vheran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static t_flags	ft_init_pf_flags(void)
{
	t_flags	flags;

	flags.width = 0;
	flags.minus = 0;
	flags.zero = 0;
	flags.dot = -1;
	flags.hash = 0;
	flags.space = 0;
	flags.plus = 0;
	flags.type = 0;
	flags.neg = 0;
	flags.pos = 0;
	return (flags);
}

static int	ft_treat_pf_input(const char *str, va_list args)
{
	t_flags	flags;
	int		c;
	int		i;

	i = -1;
	c = 0;
	while (str[++i])
	{
		flags = ft_init_pf_flags();
		if (str[i] != '%')
			c += ft_putchar_fd(str[i], 1);
		else
		{
			i = ft_treat_pf_flags(str, &flags, i);
			if (!i)
				return (0);
			else
				c += ft_printf_format(args, flags);
		}
	}
	return (c);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		c;

	va_start(args, str);
	c = ft_treat_pf_input(str, args);
	va_end(args);
	return (c);
}
