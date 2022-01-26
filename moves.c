/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vheran <vheran@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 18:02:36 by vheran            #+#    #+#             */
/*   Updated: 2022/01/13 14:42:57 by vheran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

void	move_pc(t_game *g, int xd, int yd)
{
	t_coord	c;

	c.x = g->pc.pos.x * g->size;
	c.y = g->pc.pos.y * g->size;
	mlx_put_image_to_window(g->mlx, g->w, g->floor.img, c.x, c.y);
	c.x = (g->pc.pos.x + xd) * g->size;
	c.y = (g->pc.pos.y + yd) * g->size;
	mlx_put_image_to_window(g->mlx, g->w, g->pc.spr.img, c.x, c.y);
	g->moves++;
	g->pc.pos.x += xd;
	g->pc.pos.y += yd;
}

void	move(t_game *g, int xd, int yd)
{
	t_coord	m;

	m.x = g->pc.pos.x;
	m.y = g->pc.pos.y;
	if (g->map[m.y + yd][m.x + xd] == 'E' && g->loot_c != 0)
		print_hud(g, CANT_LEAVE);
	else if (g->map[m.y + yd][m.x + xd] == 'E' && g->loot_c == 0)
	{
		print_hud(g, YOU_WON);
		exit_game(g);
	}
	else
	{
		if (g->map[m.y + yd][m.x + xd] == 'C')
			collect_loot(g, m.x + xd, m.y + yd);
		move_pc(g, xd, yd);
		print_hud(g, SCORES_HUD);
	}
}

void	check_move(t_game *g, int xd, int yd)
{
	int	x;
	int	y;

	x = g->pc.pos.x;
	y = g->pc.pos.y;
	if (g->map[y + yd][x + xd] != '1')
		move(g, xd, yd);
	else
		print_hud(g, CANT_MOVE);
}
