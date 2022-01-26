/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putubase_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vheran <vheran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 13:54:34 by vheran            #+#    #+#             */
/*   Updated: 2021/11/24 11:36:12 by vheran           ###   ########.fr       */
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

size_t	ft_putubase_fd(unsigned long n, char *base, int fd)
{
	unsigned int		lb;
	size_t				l;

	lb = ft_strlen(base);
	if (!ft_check_error(lb, base))
	{
		if (n >= lb)
		{
			l = 1 + ft_putubase_fd(n / lb, base, fd);
			ft_putchar_fd(base[n % lb], fd);
		}
		else
			l = ft_putchar_fd(base[n % lb], fd);
		return (l);
	}
	return (0);
}
