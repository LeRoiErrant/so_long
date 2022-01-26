/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vheran <vheran@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 18:02:36 by vheran            #+#    #+#             */
/*   Updated: 2022/01/13 14:29:05 by vheran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long_bonus.h"

void	move_pc(t_game *g, t_coord d, t_coord pc)
{
	t_coord	c;
	int		i;

	i = 0;
	c.x = pc.x * g->size;
	c.y = pc.y * g->size;
	mlx_put_image_to_window(g->mlx, g->w, g->floor.img, c.x, c.y);
	g->pc.pos.x += d.x;
	g->pc.pos.y += d.y;
	c.x += d.x * g->size;
	c.y += d.y * g->size;
	mlx_put_image_to_window(g->mlx, g->w, g->pc.current, c.x, c.y);
	g->moves++;
}

void	move(t_game *g, t_coord d, t_coord pc)
{
	if (g->map[pc.y + d.y][pc.x + d.x] == 'E' && g->loot_c != 0)
		print_hud(g, CANT_LEAVE);
	else if (g->map[pc.y + d.y][pc.x + d.x] == 'E' && g->loot_c == 0)
		print_hud(g, YOU_WON);
	else if (ft_strrchr(ENEMYCODES, g->map[pc.y + d.y][pc.x + d.x]))
		print_hud(g, YOU_DIED);
	else
	{
		if (g->map[pc.y + d.y][pc.x + d.x] == 'C')
			collect_loot(g, pc.x + d.x, pc.y + d.y);
		move_pc(g, d, pc);
		print_hud(g, SCORES_HUD);
	}
}

void	check_move(t_game *g, t_coord d)
{
	t_coord	c;
	t_coord	pc;

	pc.x = g->pc.pos.x;
	pc.y = g->pc.pos.y;
	c.x = pc.x * g->size;
	c.y = pc.y * g->size;
	if (g->map[pc.y + d.y][pc.x + d.x] != '1' )
		move(g, d, pc);
	else
	{
		mlx_put_image_to_window(g->mlx, g->w, g->floor.img, c.x, c.y);
		mlx_put_image_to_window(g->mlx, g->w, g->pc.current, c.x, c.y);
		print_hud(g, CANT_MOVE);
	}
}

void	get_move_dir(t_game *g, int kc)
{
	t_coord	d;

	d.x = 0;
	d.y = 0;
	if (kc == W)
		d.y--;
	else if (kc == A)
		d.x--;
	else if (kc == S)
		d.y++;
	else
		d.x++;
	check_move(g, d);
}
