/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hud.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vheran <vheran@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 17:12:25 by vheran            #+#    #+#             */
/*   Updated: 2021/12/23 11:16:30 by vheran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

static void	cant_leave_yet(int loot_c)
{
	ft_putstr_fd("You can't leave yet! ", 1);
	if (loot_c == 1)
		ft_putstr_fd("1 beer left to find!", 1);
	else
	{
		ft_putnbr_fd(loot_c, 1);
		ft_putstr_fd(" beers left to find!", 1);
	}
}

void	print_hud(t_game *g, int msgno)
{
	ft_putstr_fd("\r                                                      \r", 1);
	if (msgno == SCORES_HUD)
	{
		ft_putstr_fd("Moves: ", 1);
		ft_putnbr_fd(g->moves, 1);
		ft_putstr_fd(" Beers: ", 1);
		ft_putnbr_fd(g->loot_c, 1);
	}
	else if (msgno == CANT_MOVE)
		ft_putstr_fd(CANT_MOVE_MSG, 1);
	else if (msgno == CANT_LEAVE)
		cant_leave_yet(g->loot_c);
	else if (msgno == YOU_WON)
		ft_putstr_fd(YOU_WON_MSG, 1);
	else if (msgno == KEY_HUD)
		ft_putstr_fd(KEY_MSG, 1);
}
