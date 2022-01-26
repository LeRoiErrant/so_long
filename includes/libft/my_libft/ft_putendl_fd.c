/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vheran <vheran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 10:42:04 by vheran            #+#    #+#             */
/*   Updated: 2021/11/24 11:35:32 by vheran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

size_t	ft_putendl_fd(char *s, int fd)
{
	size_t	l;

	l = 0;
	if (s)
	{
		l = ft_strlen((const char *) s);
		write(fd, s, l);
		write(fd, "\n", 1);
		l++;
	}
	return (l);
}
