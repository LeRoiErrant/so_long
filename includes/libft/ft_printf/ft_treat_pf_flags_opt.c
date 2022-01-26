/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_pf_flags_opt.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vheran <vheran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 18:48:56 by vheran            #+#    #+#             */
/*   Updated: 2021/11/24 11:56:40 by vheran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

t_flags	ft_treat_pf_dot(const char *str, int	*i, t_flags flags)
{
	int	index;

	index = *i;
	flags.dot = 0;
	while (ft_isdigit(str[++index]))
		flags.dot = ((flags.dot * 10) + (str[index] - '0'));
	*i = index;
	return (flags);
}

t_flags	ft_treat_pf_width(char c, t_flags flags)
{
	flags.width = (flags.width * 10 + (c - '0'));
	return (flags);
}

t_flags	ft_treat_pf_minus(t_flags flags)
{
	flags.minus = 1;
	flags.zero = 0;
	return (flags);
}

t_flags	ft_treat_pf_pos(char c, t_flags flags)
{
	if (c == ' ')
	{
		flags.space = 1;
		flags.pos = ' ';
	}
	else
	{
		flags.plus = 1;
		flags.space = 0;
		flags.pos = '+';
	}
	return (flags);
}

int	ft_treat_pf_type(const char *str, int i, t_flags *flags)
{
	flags->type = str[i];
	return (i);
}
