/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loot_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vheran <vheran@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 11:27:07 by vheran            #+#    #+#             */
/*   Updated: 2021/12/27 17:09:29 by vheran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long_bonus.h"

int	count_loot(char	**map)
{
	int	c;
	int	x;
	int	y;

	c = 0;
	y = -1;
	while (map[++y])
	{
		x = -1;
		while (map[y][++x])
			if (map[y][x] == 'C')
				c++;
	}
	return (c);
}

static void	open_exit(t_game *g)
{
	g->exit.current = g->exit.on.img;
	draw_map(g);
}

void	collect_loot(t_game *g, int x, int y)
{
	t_coord	c;

	c.x = x * g->size;
	c.y = y * g->size;
	g->loot_c--;
	g->map[y][x] = '0';
	mlx_put_image_to_window(g->mlx, g->w, g->floor.img, c.x, c.y);
	if (g->loot_c == 0)
		open_exit(g);
}
