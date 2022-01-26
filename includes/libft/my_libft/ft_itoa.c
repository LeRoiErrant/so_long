/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vheran <vheran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 23:24:00 by vheran            #+#    #+#             */
/*   Updated: 2021/11/24 11:33:42 by vheran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	ft_countn(long long int n)
{
	int				c;
	unsigned int	nb;

	c = 1;
	if (n < 0)
	{
		c++;
		nb = -n;
	}
	else
		nb = n;
	if (nb > 9)
		c += ft_countn(nb / 10);
	return (c);
}

static void	ft_printn(char *str, long long int n, int i)
{
	unsigned int	nb;

	if (n < 0)
	{
		str[0] = '-';
		nb = -n;
	}
	else
		nb = n;
	if (nb > 9)
	{
		ft_printn(str, nb / 10, i - 1);
		str[i] = (nb % 10) + 48;
	}
	else
		str[i] = nb + 48;
}

char	*ft_itoa(long long int n)
{
	char	*result;
	int		l;

	l = ft_countn(n);
	result = (char *)malloc((l + 1) * sizeof(*result));
	if (!result)
		return (0);
	ft_printn(result, n, l - 1);
	result[l] = '\0';
	return (result);
}
