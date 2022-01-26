/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vheran <vheran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 11:06:45 by vheran            #+#    #+#             */
/*   Updated: 2021/11/24 11:39:18 by vheran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	l;
	size_t	i;

	l = ft_strlen(dst);
	i = 0;
	if (dstsize <= l)
		return (ft_strlen(src) + dstsize);
	while (src[i] && i < (dstsize - l - 1))
	{
		dst[l + i] = src[i];
		i++;
	}
	dst[l + i] = '\0';
	return (l + ft_strlen(src));
}
