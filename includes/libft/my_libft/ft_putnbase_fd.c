/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbase_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vheran <vheran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 17:27:49 by vheran            #+#    #+#             */
/*   Updated: 2021/11/24 11:35:36 by vheran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	ft_check_error(int lb, char *base)
{
	int	i;
	int	j;

	i = 0;
	if (lb == 0 || lb == 1)
		return (1);
	while (base[i])
	{
		if (base[i] == 43 || base[i] == 45)
			return (1);
		i++;
	}
	i = 0;
	while (base[i])
	{
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

size_t	ft_putnbase_fd(int n, char *base, int fd)
{
	unsigned int	nb;
	unsigned int	lb;
	size_t			l;

	lb = ft_strlen(base);
	if (ft_check_error(lb, base))
		return (0);
	l = 0;
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		nb = -n;
		l = 1;
	}
	else
		nb = n;
	if (nb >= lb)
	{
		l += 1 + ft_putnbase_fd(n / lb, base, fd);
		ft_putchar_fd(base[nb % lb], fd);
	}
	else
		l += ft_putchar_fd(base[nb % lb], fd);
	return (l);
}
