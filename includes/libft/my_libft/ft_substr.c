/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vheran <vheran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 15:09:49 by vheran            #+#    #+#             */
/*   Updated: 2021/11/24 11:40:42 by vheran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	int		l;
	int		i;

	if (!s)
		return (0);
	l = (int) ft_strlen(&s[start]);
	if (l > (int) len)
		l = (int) len;
	str = malloc((l + 1) * sizeof(*str));
	if (!str)
		return (0);
	if (ft_strlen(s) < (size_t) start)
	{
		*str = '\0';
		return (str);
	}
	i = -1;
	while (++i < l)
		str[i] = s[start + i];
	str[i] = '\0';
	return (str);
}
