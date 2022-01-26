/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vheran <vheran@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 16:43:06 by vheran            #+#    #+#             */
/*   Updated: 2021/12/14 14:29:27 by vheran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*d;
	const char	*s;

	d = dst;
	s = src;
	if (!dst && !src)
		return (0);
	if (s < d)
	{
		while (len-- > 0)
			d[len] = s[len];
	}
	else
		ft_memcpy(dst, src, len);
	return (dst);
}
