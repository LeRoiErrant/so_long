/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vheran <vheran@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 17:07:51 by vheran            #+#    #+#             */
/*   Updated: 2021/12/14 14:33:52 by vheran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*char	*ft_strjoin(char const *s1, char const *s2)
{
	int		l1;
	int		l2;
	char	*str;

	if (!s1 && !s2)
		return (ft_strldup("", 1));
	if (!s1)
		return (ft_strldup(s2, ft_strlen(s2)));
	if (!s2)
		return (ft_strldup(s1, ft_strlen(s2)));
	l1 = (int) ft_strlen(s1);
	l2 = (int) ft_strlen(s2);
	str = (char *)malloc((l1 + l2 + 1) * sizeof(*str));
	if (!str)
		return (0);
	ft_strlcpy(str, s1, l1 + 1);
	ft_strlcat(str, s2, (l1 + l2 + 1));
	return (str);
}*/

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*join;
	int		l1;
	int		l2;

	if (!s1 && !s2)
		return (ft_strldup("", 1));
	if (!s1)
		return (ft_strldup(s2, ft_strlen(s2)));
	if (!s2)
		return (ft_strldup(s1, ft_strlen(s2)));
	l1 = ft_strlen(s1);
	l2 = ft_strlen(s2);
	join = (char *)malloc((l1 + l2 + 1) * sizeof(*join));
	if (!join)
		return (0);
	ft_memmove(join, s1, l1);
	ft_memmove(join + l1, s2, l2);
	join[l1 + l2] = '\0';
	return (join);
}
