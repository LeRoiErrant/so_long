/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vheran <vheran@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 18:02:11 by vheran            #+#    #+#             */
/*   Updated: 2022/01/05 16:03:36 by vheran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

size_t	ft_strlcpy(char	*dst, const char *src, size_t dstsize)
{
	size_t	ls;
	size_t	i;

	ls = ft_strlen(src);
	i = -1;
	if (!src || !dst)
		return (0);
	else if (dstsize == 0)
		return (ls);
	else
	{
		while (src[++i] && i < (dstsize - 1))
			dst[i] = src[i];
		dst[i] = '\0';
	}
	return (ls);
}
