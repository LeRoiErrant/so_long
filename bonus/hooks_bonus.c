/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vheran <vheran@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 18:57:50 by vheran            #+#    #+#             */
/*   Updated: 2023/01/09 18:27:04 by vheran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long_bonus.h"

int	ft_key_event(int keyc, t_game *g)
{
	if (keyc == ESC)
		exit_game(g);
	if (keyc == R)
		restart_game(g);
	if (g->loose_scr == 0 && g->end_screen == 0)
	{
		if (g->move == true) {
			if (keyc == W || keyc == A || keyc == S || keyc == D)
			{
				if (keyc == A)
				{
					g->pc.dir = A;
					g->pc.current = g->pc.sprl.img;
				}
				else if (keyc == D)
				{
					g->pc.dir = D;
					g->pc.current = g->pc.sprr.img;
				}
				get_move_dir(g, keyc);
				g->move = false;
			}
			else
				print_hud(g, KEY_HUD);
		}
	}
	return (0);
}

int	ft_key_event_two(int keyc, t_game *g)
{
	if (keyc == W || keyc == A || keyc == S || keyc == D)
		g->move = true;

	return (0);
}
