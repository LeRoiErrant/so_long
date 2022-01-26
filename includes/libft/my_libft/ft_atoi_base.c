/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vheran <vheran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 15:59:09 by vheran            #+#    #+#             */
/*   Updated: 2021/11/24 11:06:38 by vheran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	ft_isallowed(int c)
{
	if (c == 43 || c == 45 || ft_iswhitespace(c))
		return (0);
	else
		return (1);
}

static int	ft_check_base(int lb, char *base)
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

static size_t	ft_charvalue(char c, char *base)
{
	size_t	i;

	i = -1;
	while (base[++i])
		if (base[i] == c)
			return (i);
	return (++i);
}

long long int	ft_atoi_base(const char *nptr, char *base)
{
	int				n;
	long long int	c;
	size_t			lb;

	lb = ft_strlen(base);
	if (!ft_check_base(lb, base))
		return (0);
	n = 1;
	c = 0;
	while (ft_iswhitespace(*nptr))
		nptr++;
	if (*nptr == '+' || *nptr == '-')
	{
		if (*nptr == '-')
			n *= -1;
		nptr++;
	}
	while (ft_charvalue(*nptr, base) < lb + 1)
	{
		c *= lb;
		c += ft_charvalue(*(nptr++), base);
	}
	return (c * n);
}
