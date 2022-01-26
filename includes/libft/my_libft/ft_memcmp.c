/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vheran <vheran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 15:00:06 by vheran            #+#    #+#             */
/*   Updated: 2021/11/24 11:35:01 by vheran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const char	*st1;
	const char	*st2;
	size_t		i;

	st1 = s1;
	st2 = s2;
	i = 0;
	if (n == 0)
		return (0);
	while (i < n - 1 && st1[i] == st2[i])
		i++;
	return (((unsigned char) st1[i]) - ((unsigned char) st2[i]));
}
