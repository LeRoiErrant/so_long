/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   npc_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vheran <vheran@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 12:06:53 by vheran            #+#    #+#             */
/*   Updated: 2021/12/28 15:07:49 by vheran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long_bonus.h"

void	you_died(t_game *g)
{
	t_coord	c;

	g->loose_scr = 1;
	g->pc.pos.x = -1;
	c.x = (g->wsize.x / 2) - 48;
	c.y = g->wsize.y - 62;
	mlx_string_put(g->mlx, g->w, c.x, c.y, RED, YOU_DIED_MSG1);
	c.x = (g->wsize.x / 2) - 80;
	c.y = g->wsize.y - 44;
	mlx_string_put(g->mlx, g->w, c.x, c.y, WHITE, YOU_DIED_MSG2);
	c.x = (g->wsize.x / 2) - 100;
	c.y = g->wsize.y - 24;
	mlx_string_put(g->mlx, g->w, c.x, c.y, WHITE, YOU_DIED_MSG3);
}

static void	move_npc(t_game *g)
{
	int	x;
	int	y;

	y = -1;
	while (g->map[++y])
	{
		x = -1;
		while (g->map[y][++x])
		{
			if (g->map[y][x] == '2' || g->map[y][x] == '3')
				move_npc_right(g, x, y);
			else if (g->map[y][x] == '4')
				move_npc_up(g, x, y);
			else if (g->map[y][x] == '6')
				move_npc_left(g, x, y);
			else if (g->map[y][x] == '8' || g->map[y][x] == '9')
				move_npc_down(g, x, y);
		}
	}
}

void	anim_npc(t_game *g, int frame)
{
	if (frame == 0)
	{
		g->npc.cl = g->npc.sl0.img;
		g->npc.cr = g->npc.sr0.img;
		move_npc(g);
	}
	else if (frame == 1)
	{
		g->npc.cl = g->npc.sl1.img;
		g->npc.cr = g->npc.sr1.img;
	}
	else if (frame == 2)
	{
		g->npc.cl = g->npc.sl2.img;
		g->npc.cr = g->npc.sr2.img;
	}
	else if (frame == 3)
	{
		g->npc.cl = g->npc.sl3.img;
		g->npc.cr = g->npc.sr3.img;
	}
}
