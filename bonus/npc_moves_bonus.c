/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   npc_moves_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vheran <vheran@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 12:28:52 by vheran            #+#    #+#             */
/*   Updated: 2021/12/28 13:59:30 by vheran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long_bonus.h"

void	move_npc_right(t_game *g, int x, int y)
{
	if (g->map[y][x] == '3')
		g->map[y][x] = '2';
	else if (g->map[y][x + 1] == '0')
	{
		g->map[y][x] = '0';
		x++;
		g->map[y][x] = '3';
		if (y == g->pc.pos.y && x == g->pc.pos.x)
			print_hud(g, YOU_DIED);
	}
	else if (g->map[y][x - 1] == '0')
		g->map[y][x] = '6';
	else if (g->map[y - 1][x] == '0')
		g->map[y][x] = '4';
	else if (g->map[y + 1][x] == '0')
		g->map[y][x] = '8';
}

void	move_npc_up(t_game *g, int x, int y)
{
	if (g->map[y - 1][x] == '0')
	{
		g->map[y][x] = '0';
		y--;
		g->map[y][x] = '4';
		if (y == g->pc.pos.y && x == g->pc.pos.x)
			print_hud(g, YOU_DIED);
	}
	else if (g->map[y + 1][x] == '0')
		g->map[y][x] = '8';
	else if (g->map[y][x + 1] == '0')
		g->map[y][x] = '2';
	else if (g->map[y][x - 1] == '0')
		g->map[y][x] = '6';
}

void	move_npc_left(t_game *g, int x, int y)
{
	if (g->map[y][x - 1] == '0')
	{
		g->map[y][x] = '0';
		x--;
		g->map[y][x] = '6';
		if (y == g->pc.pos.y && x == g->pc.pos.x)
			print_hud(g, YOU_DIED);
	}
	else if (g->map[y][x + 1] == '0')
		g->map[y][x] = '2';
	else if (g->map[y - 1][x] == '0')
		g->map[y][x] = '4';
	else if (g->map[y + 1][x] == '0')
		g->map[y][x] = '8';
}

void	move_npc_down(t_game *g, int x, int y)
{
	if (g->map[y][x] == '9')
		g->map[y][x] = '8';
	else if (g->map[y + 1][x] == '0')
	{
		g->map[y][x] = '0';
		y++;
		g->map[y][x] = '9';
		if (y == g->pc.pos.y && x == g->pc.pos.x)
			print_hud(g, YOU_DIED);
	}
	else if (g->map[y - 1][x] == '0')
		g->map[y][x] = '4';
	else if (g->map[y][x + 1] == '0')
		g->map[y][x] = '2';
	else if (g->map[y][x - 1] == '0')
		g->map[y][x] = '6';
}
