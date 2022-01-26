/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vheran <vheran@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 15:40:53 by vheran            #+#    #+#             */
/*   Updated: 2021/12/20 11:39:05 by vheran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list	*lst;
	int		i;

	i = 0;
	if (*alst && new)
	{
		lst = ft_lstlast(*alst);
		lst->next = new;
	}
	else
		*alst = new;
}
