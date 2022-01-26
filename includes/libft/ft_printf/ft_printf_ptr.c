/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_ptr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vheran <vheran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 10:29:38 by vheran            #+#    #+#             */
/*   Updated: 2021/11/24 11:57:07 by vheran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static char	*ft_get_address(unsigned long long ptr)
{
	char	*ulltoa;
	int		l;
	char	*address;

	ulltoa = ft_ulltoa_base(ptr, HEX_LOW);
	l = ft_strlen(ulltoa) + 3;
	address = (char *)malloc(l * sizeof(char));
	if (!address)
		return (0);
	ft_strlcpy(address, "0x", l);
	ft_strlcat(address, ulltoa, l);
	free(ulltoa);
	return (address);
}

int	ft_printf_ptr(unsigned long long ptr, t_flags flags)
{
	size_t	l;
	char	*address;

	l = 0;
	if (flags.dot < 0)
	{
		if (ptr == 0)
			address = ft_substr("0x0", 0, 4);
		else
			address = ft_get_address(ptr);
	}
	else
	{
		if (ptr == 0)
			address = ft_strldup("0x0", flags.dot + 2);
		else
			address = ft_strldup(ft_get_address(ptr), flags.dot + 2);
	}
	if (flags.minus)
		l += ft_printfstr_first(address, flags);
	else
		l += ft_printfstr_last(address, flags);
	free(address);
	return (l);
}
