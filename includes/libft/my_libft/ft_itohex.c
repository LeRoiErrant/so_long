/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itohex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vheran <vheran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 12:47:08 by vheran            #+#    #+#             */
/*   Updated: 2021/11/24 11:34:00 by vheran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static void	ft_reversebinary(unsigned int i, char *str)
{
	(void) i;
	if (*str == 48)
		*str = 49;
	else
		*str = 48;
}

char	*ft_itohex(int n, char *uppercase)
{
	char			*result;
	char			tmp[33];
	long long int	nb;

	if (n >= 0)
		result = ft_itoa_base(n, uppercase);
	else
	{
		nb = -n;
		ft_bzero(tmp, 33);
		ft_memset(tmp, 48, 32);
		result = ft_itoa_base(nb, "01");
		nb = ft_strlen(result);
		ft_memmove(&tmp[32 - nb], result, nb);
		ft_striteri(tmp, ft_reversebinary);
		nb = ft_atoi_base(tmp, "01") + 1;
		free(result);
		result = ft_itoa_base(nb, uppercase);
	}
	return (result);
}
