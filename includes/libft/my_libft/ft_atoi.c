/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vheran <vheran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 10:20:16 by vheran            #+#    #+#             */
/*   Updated: 2021/10/28 10:20:16 by vheran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_atoi(const char *nptr)
{
	int			n;
	long int	c;
	int			i;

	n = 1;
	c = 0;
	i = 0;
	while (ft_iswhitespace(nptr[i]))
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			n *= -1;
		i++;
	}
	while ('0' <= nptr[i] && nptr[i] <= '9')
	{
		c *= 10;
		c += (nptr[i++] - 48);
		if ((c * n) > INT_MAX)
			return (-1);
		if ((c * n) < INT_MIN)
			return (0);
	}
	return ((int) c * n);
}
