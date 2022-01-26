/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vheran <vheran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 18:58:57 by vheran            #+#    #+#             */
/*   Updated: 2022/01/11 12:23:08 by vheran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->llen + x * (img->bpp / 8));
	*(unsigned int *)dst = color;
}

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
	load_tex(g, &g->pc.spr, PC_P64R0);
	load_tex(g, &g->loot, LOOT_P64);
	load_tex(g, &g->wall, WALL_P64);
	load_tex(g, &g->exit.off, EXIT0_P64);
	load_tex(g, &g->exit.on, EXIT1_P64);
	tmp.img = mlx_new_image(g->mlx, g->size, g->size * 2);
	tmp.addr = mlx_get_data_addr(tmp.img, &tmp.bpp, &tmp.llen, &tmp.endian);
	x = -1;
	while (++x < g->size)
	{
		y = -1;
		while (++y < g->size * 2)
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
	load_tex(g, &g->pc.spr, PC_P32R0);
	load_tex(g, &g->loot, LOOT_P32);
	load_tex(g, &g->wall, WALL_P32);
	load_tex(g, &g->exit.off, EXIT0_P32);
	load_tex(g, &g->exit.on, EXIT1_P32);
	tmp.img = mlx_new_image(g->mlx, g->size, g->size * 2);
	tmp.addr = mlx_get_data_addr(tmp.img, &tmp.bpp, &tmp.llen, &tmp.endian);
	x = -1;
	while (++x < g->size)
	{
		y = -1;
		while (++y < g->size * 2)
			my_mlx_pixel_put(&tmp, x, y, BLACK);
	}
	g->erase = tmp;
}
