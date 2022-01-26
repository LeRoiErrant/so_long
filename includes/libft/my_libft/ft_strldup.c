/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strldup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vheran <vheran@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 21:31:29 by vheran            #+#    #+#             */
/*   Updated: 2021/12/13 11:01:52 by vheran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strldup(const char *s1, size_t max)
{
	char		*dup;
	size_t		len;

	len = ft_strlen(s1);
	if (len > max)
		len = max;
	dup = (char *)malloc((len + 1) * sizeof(*dup));
	if (!dup)
		return (0);
	dup = ft_memmove(dup, s1, len);
	return (dup);
}
