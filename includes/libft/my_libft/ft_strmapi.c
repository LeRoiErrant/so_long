/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vheran <vheran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 09:18:51 by vheran            #+#    #+#             */
/*   Updated: 2021/11/24 11:40:22 by vheran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*str;
	int		l;
	int		i;

	if (!s)
		return (0);
	l = ft_strlen(s);
	str = (char *)malloc((l + 1) * sizeof(*str));
	if (!str)
		return (0);
	i = -1;
	while (++i < l)
		str[i] = f((unsigned int) i, s[i]);
	str[i] = '\0';
	return (str);
}
