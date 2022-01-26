/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vheran <vheran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 11:16:45 by vheran            #+#    #+#             */
/*   Updated: 2021/11/24 11:26:57 by vheran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*str;
	size_t	i;

	str = malloc((count * size) * sizeof(char));
	if (!str)
		return (0);
	i = 0;
	while (i < (count * size))
	{
		str[i] = '\0';
		i++;
	}
	return ((void *) str);
}
