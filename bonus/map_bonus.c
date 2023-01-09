/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vheran <vheran@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 11:43:48 by vheran            #+#    #+#             */
/*   Updated: 2023/01/09 11:52:21 by vheran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long_bonus.h"

void draw_wall (t_game *g, int x, int y, t_coord c) {
		if (x == 0 && (y == 0 || y == g->msize.y - 1))
			mlx_put_image_to_window(g->mlx, g->w, g->outer.cleft.img, c.x, c.y);
		else if (x == g->msize.x - 1 && (y == 0 || y == g->msize.y - 1))
			mlx_put_image_to_window(g->mlx, g->w, g->outer.cright.img, c.x, c.y);
		else if (x == 0)
			mlx_put_image_to_window(g->mlx, g->w, g->outer.left.img, c.x, c.y);
		else if (x == g->msize.x - 1)
			mlx_put_image_to_window(g->mlx, g->w, g->outer.right.img, c.x, c.y);
		else if (y == 0 || y == g->msize.y - 1)
			mlx_put_image_to_window(g->mlx, g->w, g->outer.wall.img, c.x, c.y);
		else
			mlx_put_image_to_window(g->mlx, g->w, g->wall.img, c.x, c.y);
}

void	draw_square(t_game *g, int x, int y)
{
	t_coord	c;

	c.x = x * g->size;
	c.y = y * g->size;
	if (g->map[y][x] == '1')
		draw_wall(g, x, y, c);
	else
	{
		mlx_put_image_to_window(g->mlx, g->w, g->floor.img, c.x, c.y);
		if (g->map[y][x] == 'E')
			mlx_put_image_to_window(g->mlx, g->w, g->exit.current, c.x, c.y);
		if (g->map[y][x] == 'C')
			mlx_put_image_to_window(g->mlx, g->w, g->loot.current, c.x, c.y);
		if (g->map[y][x] == '2' || g->map[y][x] == '4')
			mlx_put_image_to_window(g->mlx, g->w, g->npc.cr, c.x, c.y);
		if (g->map[y][x] == '6' || g->map[y][x] == '8')
			mlx_put_image_to_window(g->mlx, g->w, g->npc.cl, c.x, c.y);
	}
}

void	draw_map(t_game *g)
{
	int		x;
	int		y;
	t_coord	pc_p;

	y = -1;
	while (g->map[++y])
	{
		x = -1;
		while (g->map[y][++x])
			draw_square(g, x, y);
	}
	pc_p.x = g->pc.pos.x * g->size;
	pc_p.y = g->pc.pos.y * g->size;
	mlx_put_image_to_window(g->mlx, g->w, g->pc.current, pc_p.x, pc_p.y);
}
