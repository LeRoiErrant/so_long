/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vheran <vheran@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 18:58:57 by vheran            #+#    #+#             */
/*   Updated: 2023/01/09 11:47:17 by vheran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long_bonus.h"

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->llen + x * (img->bpp / 8));
	*(unsigned int *)dst = color;
}

void	load_npc_tex(t_game *g, int format)
{
	if (format == 64)
	{
		load_tex(g, &g->npc.sr0, NPC_P64R0);
		load_tex(g, &g->npc.sr1, NPC_P64R1);
		load_tex(g, &g->npc.sr2, NPC_P64R2);
		load_tex(g, &g->npc.sr3, NPC_P64R3);
		load_tex(g, &g->npc.sl0, NPC_P64L0);
		load_tex(g, &g->npc.sl1, NPC_P64L1);
		load_tex(g, &g->npc.sl2, NPC_P64L2);
		load_tex(g, &g->npc.sl3, NPC_P64L3);
	}
	else if (format == 32)
	{
		load_tex(g, &g->npc.sr0, NPC_P32R0);
		load_tex(g, &g->npc.sr1, NPC_P32R1);
		load_tex(g, &g->npc.sr2, NPC_P32R2);
		load_tex(g, &g->npc.sr3, NPC_P32R3);
		load_tex(g, &g->npc.sl0, NPC_P32L0);
		load_tex(g, &g->npc.sl1, NPC_P32L1);
		load_tex(g, &g->npc.sl2, NPC_P32L2);
		load_tex(g, &g->npc.sl3, NPC_P32L3);
	}
}

void	load_pc_tex(t_game *g, int format)
{
	if (format == 64)
	{
		load_tex(g, &g->pc.sprr, PC_P64R0);
		load_tex(g, &g->pc.sprr1, PC_P64R1);
		load_tex(g, &g->pc.sprr2, PC_P64R2);
		load_tex(g, &g->pc.sprl, PC_P64L0);
		load_tex(g, &g->pc.sprl1, PC_P64L1);
		load_tex(g, &g->pc.sprl2, PC_P64L2);
	}
	else if (format == 32)
	{
		load_tex(g, &g->pc.sprr, PC_P32R0);
		load_tex(g, &g->pc.sprr1, PC_P32R1);
		load_tex(g, &g->pc.sprr2, PC_P32R2);
		load_tex(g, &g->pc.sprl, PC_P32L0);
		load_tex(g, &g->pc.sprl1, PC_P32L1);
		load_tex(g, &g->pc.sprl2, PC_P32L2);
	}
}

void	load_loot_tex(t_game *g, int format)
{
	if (format == 64)
	{
		load_tex(g, &g->loot.loot0, LOOT_P64);
		load_tex(g, &g->loot.loot1, LOOT_P641);
		load_tex(g, &g->loot.loot2, LOOT_P642);
	}
	else if (format == 32)
	{
		load_tex(g, &g->loot.loot0, LOOT_P32);
		load_tex(g, &g->loot.loot1, LOOT_P321);
		load_tex(g, &g->loot.loot2, LOOT_P322);
	}
}
