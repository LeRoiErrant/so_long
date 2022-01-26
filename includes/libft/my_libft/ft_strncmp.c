/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vheran <vheran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 09:37:35 by vheran            #+#    #+#             */
/*   Updated: 2021/11/24 11:40:27 by vheran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	if (!s1 || !s2)
		return ((unsigned char) s1[i] - (unsigned char) s2[i]);
	while (s1[i] == s2[i] && i < n - 1 && s1[i] && s2[i])
		i++;
	return ((unsigned char) s1[i] - (unsigned char) s2[i]);
}
