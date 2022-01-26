/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ulltoa_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vheran <vheran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 09:07:32 by vheran            #+#    #+#             */
/*   Updated: 2021/11/24 11:40:51 by vheran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	ft_count_base(unsigned long long n, char *base)
{
	int					c;
	unsigned long long	lb;

	c = 1;
	lb = ft_strlen(base);
	if (n >= lb)
		c += ft_count_base(n / lb, base);
	return (c);
}

static void	ft_ull_base(char *str, unsigned long long n, int i, char *base)
{
	unsigned long long	lb;

	lb = ft_strlen(base);
	if (n >= lb)
	{
		ft_ull_base(str, n / lb, i - 1, base);
		str[i] = base[n % lb];
	}
	else
		str[i] = base[n];
}

char	*ft_ulltoa_base(unsigned long long n, char *base)
{
	char	*result;
	int		l;

	l = ft_count_base(n, base);
	result = (char *)malloc((l + 1) * sizeof(char));
	if (!result)
		return (0);
	ft_ull_base(result, n, l - 1, base);
	result[l] = '\0';
	return (result);
}
