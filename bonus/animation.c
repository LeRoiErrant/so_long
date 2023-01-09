/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vheran <vheran@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 12:39:24 by vheran            #+#    #+#             */
/*   Updated: 2023/01/09 09:20:42 by vheran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long_bonus.h"

static void	anim_pc(t_pc *pc, int sprite)
{
	if (sprite == 0)
	{
		if (pc->dir == D)
			pc->current = pc->sprr.img;
		else
			pc->current = pc->sprl.img;
	}
	else if (sprite == 1)
	{
		if (pc->dir == D)
			pc->current = pc->sprr1.img;
		else
			pc->current = pc->sprl1.img;
	}
	else if (sprite == 2)
	{
		if (pc->dir == D)
			pc->current = pc->sprr2.img;
		else
			pc->current = pc->sprl2.img;
	}
}

static void	get_anim(t_game *g, int frame)
{
	g->move = true;
	if (frame == 0 || frame == 2)
	{
		anim_pc(&g->pc, 0);
		anim_npc(g, frame);
		g->loot.current = g->loot.loot0.img;
		draw_map(g);
	}
	if (frame == 1)
	{
		anim_pc(&g->pc, 2);
		anim_npc(g, frame);
		g->loot.current = g->loot.loot1.img;
		draw_map(g);
	}
	if (frame == 3)
	{
		anim_pc(&g->pc, 1);
		anim_npc(g, frame);
		g->loot.current = g->loot.loot2.img;
		draw_map(g);
	}
}

int	anim_frames(t_game *g)
{
	if (g->end_screen == 0)
	{	
		if (g->frame == g->framect)
			get_anim(g, 1);
		else if (g->frame == 2 * g->framect)
			get_anim(g, 2);
		else if (g->frame == 3 * g->framect)
			get_anim(g, 3);
		else if (g->frame == 4 * g->framect)
		{
			get_anim(g, 0);
			g->frame = 0;
		}
		g->frame++;
	}
	else
	{
		if (g->end_screen == 7 * g->framect)
			exit_game(g);
		g->end_screen++;
	}
	return (1);
}
