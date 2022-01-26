/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vheran <vheran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 12:09:26 by vheran            #+#    #+#             */
/*   Updated: 2021/11/24 11:27:19 by vheran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static bool	ft_isallowed(int c)
{
	if (c == 43 || c == 45 || ft_iswhitespace(c))
		return (0);
	else
		return (1);
}

static int	ft_checkb(int lb, char *base)
{
	int	i;
	int	j;

	if (lb == 0 || lb == 1)
		return (0);
	i = -1;
	while (base[++i])
		if (!ft_isallowed(base[i]))
			return (0);
	i = -1;
	while (base[++i])
	{
		j = i;
		while (base[++j])
			if (base[i] == base[j])
				return (0);
	}
	return (1);
}

char	*ft_convert_base(char *str, char *bsrc, char *bdst)
{
	char		*result;
	long int	temp;

	if (!ft_checkb(ft_strlen(bsrc), bsrc) || !ft_checkb(ft_strlen(bdst), bdst))
		return (0);
	temp = ft_atoi_base(str, bsrc);
	result = ft_itoa_base(temp, bdst);
	return (result);
}
