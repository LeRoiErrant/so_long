/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vheran <vheran@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 10:08:53 by vheran            #+#    #+#             */
/*   Updated: 2021/12/14 14:27:37 by vheran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	ch;

	ch = (char) c;
	if (!s)
		return (0);
	while (*s)
	{
		if (*s == ch)
			return ((char *) s);
		s++;
	}
	return (0);
}
