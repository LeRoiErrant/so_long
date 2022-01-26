/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vheran <vheran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 11:59:02 by vheran            #+#    #+#             */
/*   Updated: 2021/11/24 11:56:28 by vheran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# define PTF_FLAGS ".-# +"
# define PTF_TYPES "cspdiuxX%%"
# include "../libft.h"

typedef struct s_flags
{
	int		width;
	int		minus;
	int		zero;
	int		dot;
	int		hash;
	int		space;
	int		plus;
	int		type;
	int		neg;
	char	pos;
}		t_flags;

int		ft_printf(const char *str, ...);
int		ft_printf_format(va_list args, t_flags flags);
//---Flags---//
int		ft_treat_pf_flags(const char *str, t_flags *flags, int i);
t_flags	ft_treat_pf_dot(const char *str, int *i, t_flags flags);
t_flags	ft_treat_pf_width(char c, t_flags flags);
t_flags	ft_treat_pf_minus(t_flags flags);
t_flags	ft_treat_pf_pos(char c, t_flags flags);
int		ft_treat_pf_type(const char *str, int i, t_flags *flags);
//t_flags	ft_check_dot_type(t_flags flags);
int		ft_is_pftype(char c, char *types);
int		ft_is_pfflag(char c, char *flags);
int		ft_printf_width(int len, t_flags flags);
int		ft_printf_width_nbr(int len, t_flags flags);
int		ft_printfnbr_first(char *nbr, t_flags flags);
int		ft_printfnbr_middle(char *nbr, t_flags *flags);
int		ft_printfnbr_last(char *nbr, t_flags flags);
int		ft_printfstr_first(char *output, t_flags flags);
int		ft_printfstr_last(char *output, t_flags flags);
//---Formats---//
int		ft_printf_char(char c, t_flags flags);
int		ft_printf_str(char *str, t_flags flags);
int		ft_printf_nbr(int n, t_flags flags);
int		ft_printf_hex(unsigned long long n, t_flags flags, char *uppercase);
int		ft_printf_uns(unsigned n, t_flags flags);
int		ft_printf_ptr(unsigned long long ptr, t_flags flags);
/*---Version One---*/
/*
int	ft_printf(const char *str, ...);
int	ft_print_format(va_list args, char c);
*/

#endif