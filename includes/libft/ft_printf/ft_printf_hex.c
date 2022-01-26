/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vheran <vheran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 09:48:59 by vheran            #+#    #+#             */
/*   Updated: 2021/11/24 11:57:17 by vheran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static char	*ft_printf_alterhex(unsigned long long n, char *uppercase)
{
	char	*tmp;
	char	*alterhex;
	size_t	l;

	tmp = ft_ulltoa_base(n, uppercase);
	l = ft_strlen(tmp) + 3;
	alterhex = (char *)malloc(l * sizeof(char));
	if (!ft_strncmp(HEX_LOW, uppercase, ft_strlen(uppercase)))
		ft_strlcpy(alterhex, "0x", l);
	else
		ft_strlcpy(alterhex, "0X", l);
	ft_strlcat(alterhex, tmp, l);
	free(tmp);
	return (alterhex);
}

int	ft_printf_hex(unsigned long long n, t_flags flags, char *uppercase)
{
	char	*utohex;
	size_t	l;

	l = 0;
	if (flags.dot == 0 && n == 0)
	{
		flags.minus = 0;
		l += ft_printf_width_nbr(0, flags);
		return (l);
	}
	if (flags.hash && n)
		utohex = ft_printf_alterhex(n, uppercase);
	else
		utohex = ft_ulltoa_base(n, uppercase);
	if (flags.minus && flags.dot < 0)
		l += ft_printfnbr_first(utohex, flags);
	else if (flags.width && flags.dot >= 0 && flags.minus)
		l += ft_printfnbr_middle(utohex, &flags);
	else
		l += ft_printfnbr_last(utohex, flags);
	free(utohex);
	return (l);
}
