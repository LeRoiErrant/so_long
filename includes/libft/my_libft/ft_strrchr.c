/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vheran <vheran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 10:44:48 by vheran            #+#    #+#             */
/*   Updated: 2021/11/24 11:40:34 by vheran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char		ch;
	const char	*a;
	int			r;

	ch = (char) c;
	r = 0;
	while (*s != '\0')
	{
		if (*s == ch)
		{
			a = s;
			r = 1;
		}
		s++;
	}
	if (r == 1)
		return ((char *) a);
	else if (ch == '\0')
		return ((char *) s);
	else
		return (0);
}
