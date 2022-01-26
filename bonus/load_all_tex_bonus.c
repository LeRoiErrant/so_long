/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_all_tex_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vheran <vheran@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 12:21:40 by vheran            #+#    #+#             */
/*   Updated: 2021/12/28 12:00:10 by vheran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long_bonus.h"

void	load_tex(t_game *g, t_tex *t, char *path)
{
	t->img = mlx_xpm_file_to_image(g->mlx, path, &t->wnh.x, &t->wnh.y);
	t->addr = mlx_get_data_addr(t->img, &t->bpp, &t->llen, &t->endian);
}

void	load_all_tex_64(t_game *g)
{
	t_img	tmp;
	int		x;
	int		y;

	load_tex(g, &g->floor, FLOOR_P64);
	load_pc_tex(g, 64);
	load_npc_tex(g, 64);
	load_loot_tex(g, 64);
	load_tex(g, &g->wall, WALL_P64);
	load_tex(g, &g->exit.off, EXIT0_P64);
	load_tex(g, &g->exit.on, EXIT1_P64);
	tmp.img = mlx_new_image(g->mlx, g->wsize.x, 64);
	tmp.addr = mlx_get_data_addr(tmp.img, &tmp.bpp, &tmp.llen, &tmp.endian);
	x = -1;
	while (++x < g->wsize.x)
	{
		y = -1;
		while (++y < 64)
			my_mlx_pixel_put(&tmp, x, y, BLACK);
	}
	g->erase = tmp;
}

void	load_all_tex_32(t_game *g)
{
	t_img	tmp;
	int		x;
	int		y;

	load_tex(g, &g->floor, FLOOR_P32);
	load_pc_tex(g, 32);
	load_npc_tex(g, 32);
	load_loot_tex(g, 32);
	load_tex(g, &g->wall, WALL_P32);
	load_tex(g, &g->exit.off, EXIT0_P32);
	load_tex(g, &g->exit.on, EXIT1_P32);
	tmp.img = mlx_new_image(g->mlx, g->wsize.x, 64);
	tmp.addr = mlx_get_data_addr(tmp.img, &tmp.bpp, &tmp.llen, &tmp.endian);
	x = -1;
	while (++x < g->wsize.x)
	{
		y = -1;
		while (++y < 64)
			my_mlx_pixel_put(&tmp, x, y, BLACK);
	}
	g->erase = tmp;
}
