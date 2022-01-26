/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vheran <vheran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 14:17:28 by vheran            #+#    #+#             */
/*   Updated: 2021/11/24 11:35:24 by vheran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	char	*s;
	size_t	i;

	s = b;
	i = 0;
	while (i < len)
		s[i++] = (unsigned char) c;
	return (b);
}
