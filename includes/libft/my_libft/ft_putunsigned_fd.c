/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsigned_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vheran <vheran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 11:17:35 by vheran            #+#    #+#             */
/*   Updated: 2021/11/24 11:36:18 by vheran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

size_t	ft_putunsigned_fd(int n, int fd)
{
	size_t			l;
	unsigned int	nb;

	nb = n;
	if (nb > 9)
	{	
		l = 1 + ft_putunsigned_fd(nb / 10, fd);
		ft_putchar_fd((nb % 10) + 48, fd);
	}
	else
		l = ft_putchar_fd(nb + 48, fd);
	return (l);
}
