/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vheran <vheran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 18:00:17 by vheran            #+#    #+#             */
/*   Updated: 2021/11/24 11:40:38 by vheran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	ft_isset(char const *set, char c)
{
	int	i;

	i = -1;
	while (set[++i])
		if (c == set[i])
			return (1);
	return (0);
}

static int	ft_nbset(char const *s1, char const *set, int n, int l)
{
	int	c;

	c = 0;
	if (n > 0)
		while (ft_isset(set, s1[c]))
			c++;
	else
		while (ft_isset(set, s1[l - (c + 1)]))
			c++;
	return (c);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		l;
	int		i;
	int		c;
	char	*str;

	if (!s1 || !set)
		return (0);
	l = (int) ft_strlen(s1);
	i = ft_nbset(s1, set, 1, l);
	if (i != l)
		c = l - (i + ft_nbset(s1, set, 0, l));
	else
		c = 0;
	str = (char *)malloc((c + 1) * sizeof(*str));
	if (!str)
		return (0);
	l = -1;
	while (++l < c)
		str[l] = s1[i + l];
	str[l] = '\0';
	return (str);
}
