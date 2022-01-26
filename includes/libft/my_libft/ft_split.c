/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vheran <vheran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 12:26:25 by vheran            #+#    #+#             */
/*   Updated: 2021/11/24 11:36:22 by vheran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	ft_c_str(char const *s, char c)
{
	int	n;
	int	i;

	n = 0;
	i = -1;
	while (s[++i] == c || s[i] == '\0')
		if (s[i] == '\0')
			return (0);
	while (s[++i] != '\0')
		if (s[i] == c && s[i - 1] != c)
			n++;
	if (s[i - 1] != c)
		n++;
	return (n);
}

static void	ft_fulfill(char **array, char const *str, char sep)
{
	int	ai;
	int	i;

	ai = -1;
	while (*str == sep && *str != '\0')
		str++;
	while (*str != '\0')
	{
		i = 0;
		while (str[i] != sep && str[i] != '\0')
			i++;
		array[++ai] = ft_substr(str, 0, i);
		while (*str != sep && *str != '\0')
			str++;
		while (*str == sep && *str != '\0')
			str++;
	}
}

char	**ft_split(char const *s, char c)
{
	int		n;
	char	**index;

	if (!s)
		return (0);
	n = ft_c_str(s, c);
	index = (char **)malloc((n + 1) * sizeof(*index));
	if (!index)
		return (0);
	if (n != 0)
		ft_fulfill(index, s, c);
	index[n] = 0;
	return (index);
}
