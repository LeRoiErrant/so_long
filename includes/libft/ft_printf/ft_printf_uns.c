/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_uns.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vheran <vheran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 09:58:09 by vheran            #+#    #+#             */
/*   Updated: 2021/11/24 11:56:59 by vheran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_printf_uns(unsigned n, t_flags flags)
{
	char	*utoa;
	size_t	l;

	l = 0;
	if (flags.dot == 0 && n == 0)
	{
		flags.minus = 0;
		l += ft_printf_width_nbr(0, flags);
		return (l);
	}
	utoa = ft_ulltoa_base(n, DECIMAL);
	if (flags.minus && flags.dot < 0)
		l += ft_printfnbr_first(utoa, flags);
	else if (flags.width && flags.dot >= 0 && flags.minus)
		l += ft_printfnbr_middle(utoa, &flags);
	else
		l += ft_printfnbr_last(utoa, flags);
	free(utoa);
	return (l);
}
