/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_pf_flags.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vheran <vheran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 19:22:40 by vheran            #+#    #+#             */
/*   Updated: 2021/11/24 11:56:36 by vheran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_treat_pf_flags(const char *str, t_flags *flags, int i)
{
	while (str[++i])
	{
		if (!ft_isdigit(str[i]) && !ft_is_pftype(str[i], PTF_TYPES)
			&& !ft_is_pfflag(str[i], PTF_FLAGS))
			return (0);
		if (str[i] == '0' && !flags->width && !flags->minus)
			flags->zero = 1;
		if (str[i] == '-')
			*flags = ft_treat_pf_minus(*flags);
		if (str[i] == '.')
			*flags = ft_treat_pf_dot(str, &i, *flags);
		if (str[i] == '#')
			flags->hash = 1;
		if (str[i] == ' ' && !flags->plus)
			*flags = ft_treat_pf_pos(str[i], *flags);
		if (str[i] == '+')
			*flags = ft_treat_pf_pos(str[i], *flags);
		if (ft_isdigit(str[i]))
			*flags = ft_treat_pf_width(str[i], *flags);
		if (ft_is_pftype(str[i], PTF_TYPES))
			return (ft_treat_pf_type(str, i, flags));
	}
	return (0);
}
