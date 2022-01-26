/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vheran <vheran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 17:28:07 by vheran            #+#    #+#             */
/*   Updated: 2021/11/24 12:50:04 by vheran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_list	*ft_lstmap(t_list *l, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlist;
	t_list	*add;

	if (!l || !f)
		return (0);
	add = ft_lstnew(f(l->content));
	if (!add)
		return (0);
	newlist = add;
	l = l->next;
	while (l)
	{
		add = ft_lstnew(f(l->content));
		if (!add)
		{
			ft_lstclear(&newlist, del);
			return (0);
		}
		l = l->next;
		ft_lstadd_back(&newlist, add);
	}
	return (newlist);
}
