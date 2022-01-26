/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vheran <vheran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 16:48:03 by vheran            #+#    #+#             */
/*   Updated: 2021/11/24 11:34:14 by vheran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_lstclear(t_list	**lst, void (*del)(void *))
{
	t_list	*ls;
	t_list	*tmp;

	if (*lst && del)
	{
		ls = *lst;
		while (ls)
		{
			tmp = ls->next;
			ft_lstdelone(ls, del);
			ls = tmp;
		}
		*lst = 0;
	}
}
