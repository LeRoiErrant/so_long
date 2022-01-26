/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vheran <vheran@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 10:51:10 by vheran            #+#    #+#             */
/*   Updated: 2021/12/18 10:51:10 by vheran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

void	error_arg(int err_no)
{
	if (err_no == 0)
		ft_putstr_fd(ERR_ARGC, 2);
	else
		ft_putstr_fd(ERR_EXT, 2);
	exit(EXIT_FAILURE);
}

void	error_map(int err_no, t_game *g)
{
	int	i;

	i = -1;
	while (g->map[++i])
		free(g->map[i]);
	free(g->map);
	if (err_no == 1)
		ft_putstr_fd(ERR_WALLS, 2);
	else if (err_no == 2)
		ft_putstr_fd(ERR_NOEXIT, 2);
	else if (err_no == 3)
		ft_putstr_fd(ERR_NOCOLL, 2);
	else if (err_no == 4)
		ft_putstr_fd(ERR_NOSTART, 2);
	else if (err_no == 5)
		ft_putstr_fd(ERR_RECT, 2);
	else
		ft_putstr_fd(ERR_CHAR, 2);
	exit(EXIT_FAILURE);
}
