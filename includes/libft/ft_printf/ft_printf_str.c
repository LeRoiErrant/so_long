/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vheran <vheran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 12:38:13 by vheran            #+#    #+#             */
/*   Updated: 2021/11/24 11:57:03 by vheran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_printfstr_first(char *output, t_flags flags)
{
	size_t	l;

	l = 0;
	l += ft_putstr_fd(output, 1);
	if (flags.width != 0)
		l += ft_printf_width(ft_strlen(output), flags);
	return (l);
}

int	ft_printfstr_last(char *output, t_flags flags)
{
	size_t	l;

	l = 0;
	if (flags.width != 0)
		l += ft_printf_width(ft_strlen(output), flags);
	l += ft_putstr_fd(output, 1);
	return (l);
}

int	ft_printf_str(char *str, t_flags flags)
{
	size_t	l;
	char	*output;

	l = 0;
	if (flags.dot < 0)
	{
		if (str == NULL)
			output = ft_strdup("(null)");
		else
			output = ft_strdup(str);
	}
	else
	{
		if (str == NULL)
			output = ft_strldup("(null)", flags.dot);
		else
			output = ft_strldup(str, flags.dot);
	}
	if (flags.minus)
		l += ft_printfstr_first(output, flags);
	else
		l += ft_printfstr_last(output, flags);
	free(output);
	return (l);
}
