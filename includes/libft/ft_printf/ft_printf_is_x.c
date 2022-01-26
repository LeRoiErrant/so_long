/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_is_x.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vheran <vheran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 09:52:52 by vheran            #+#    #+#             */
/*   Updated: 2021/11/24 11:57:14 by vheran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_is_pftype(char c, char *types)
{
	while (*types)
		if (*(types++) == c)
			return (1);
	return (0);
}

int	ft_is_pfflag(char c, char *flags)
{
	while (*flags)
		if (*(flags++) == c)
			return (1);
	return (0);
}
