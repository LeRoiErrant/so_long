/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vheran <vheran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 18:40:02 by vheran            #+#    #+#             */
/*   Updated: 2021/11/24 11:32:50 by vheran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static size_t	ft_resultlen(long long int n, size_t lb)
{
	int				len;
	unsigned int	nb;

	len = 1;
	if (n < 0)
	{
		len++;
		nb = -n;
	}
	else
		nb = n;
	if (nb >= lb)
		len += ft_resultlen(nb / lb, lb);
	return (len);
}

static int	ft_check_base(size_t lb, char *base)
{
	int	i;
	int	j;

	if (lb == 0 || lb == 1)
		return (0);
	i = -1;
	while (base[++i])
		if (base[i] == 43 || base[i] == 45)
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

static void	ft_fillresult(char *r, long long int n, int i, char *b)
{
	unsigned long int	nb;
	size_t				lb;

	lb = ft_strlen(b);
	if (n < 0)
	{
		r[0] = '-';
		nb = -n;
	}
	else
		nb = n;
	if (nb >= lb)
	{
		ft_fillresult(r, nb / lb, i - 1, b);
		r[i] = b[nb % lb];
	}
	else
		r[i] = b[nb];
}

char	*ft_itoa_base(long long int n, char *base)
{
	char	*result;
	size_t	lbase;
	size_t	lresult;

	lbase = ft_strlen(base);
	if (!ft_check_base(lbase, base))
		return (0);
	lresult = ft_resultlen(n, lbase);
	result = (char *)malloc((lresult + 1) * sizeof(*result));
	if (!result)
		return (0);
	ft_fillresult(result, n, lresult - 1, base);
	result[lresult] = '\0';
	return (result);
}
