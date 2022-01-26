/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vheran <vheran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 10:48:40 by vheran            #+#    #+#             */
/*   Updated: 2021/11/24 11:35:44 by vheran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

size_t	ft_putnbr_fd(int n, int fd)
{
	unsigned int	nb;
	size_t			l;

	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		nb = -n;
		l = 1;
	}
	else
	{
		nb = n;
		l = 0;
	}
	if (nb > 9)
	{	
		l += 1 + ft_putnbr_fd(nb / 10, fd);
		ft_putchar_fd((nb % 10) + 48, fd);
	}
	else
		l += ft_putchar_fd(nb + 48, fd);
	return (l);
}
