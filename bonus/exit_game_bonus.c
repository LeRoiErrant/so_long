/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_game_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vheran <vheran@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 19:00:02 by vheran            #+#    #+#             */
/*   Updated: 2021/12/28 15:22:58 by vheran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long_bonus.h"

static void	destroy_all_images(t_game *g)
{
	mlx_destroy_image(g->mlx, g->floor.img);
	mlx_destroy_image(g->mlx, g->pc.sprr.img);
	mlx_destroy_image(g->mlx, g->pc.sprr1.img);
	mlx_destroy_image(g->mlx, g->pc.sprr2.img);
	mlx_destroy_image(g->mlx, g->pc.sprl.img);
	mlx_destroy_image(g->mlx, g->pc.sprl1.img);
	mlx_destroy_image(g->mlx, g->pc.sprl2.img);
	mlx_destroy_image(g->mlx, g->npc.sr0.img);
	mlx_destroy_image(g->mlx, g->npc.sr1.img);
	mlx_destroy_image(g->mlx, g->npc.sr2.img);
	mlx_destroy_image(g->mlx, g->npc.sr3.img);
	mlx_destroy_image(g->mlx, g->npc.sl0.img);
	mlx_destroy_image(g->mlx, g->npc.sl1.img);
	mlx_destroy_image(g->mlx, g->npc.sl2.img);
	mlx_destroy_image(g->mlx, g->npc.sl3.img);
	mlx_destroy_image(g->mlx, g->loot.loot0.img);
	mlx_destroy_image(g->mlx, g->loot.loot1.img);
	mlx_destroy_image(g->mlx, g->loot.loot2.img);
	mlx_destroy_image(g->mlx, g->wall.img);
	mlx_destroy_image(g->mlx, g->exit.off.img);
	mlx_destroy_image(g->mlx, g->exit.on.img);
	mlx_destroy_image(g->mlx, g->erase.img);
}

void	restart_game(t_game *g)
{
	int	i;

	mlx_clear_window(g->mlx, g->w);
	i = -1;
	while (g->map[++i])
		free(g->map[i]);
	free(g->map);
	g->map = parse_map(g->map_path, g);
	if (!g->map)
	{
		ft_putstr_fd("Parsing error!\n", 2);
		exit(EXIT_FAILURE);
	}
	destroy_all_images(g);
	init_game(g);
	draw_map(g);
	print_hud(g, KEY_HUD);
}

void	you_won(t_game *g)
{
	t_coord		c;

	g->end_screen = 1;
	c.x = g->pc.pos.x * g->size;
	c.y = g->pc.pos.y * g->size;
	mlx_put_image_to_window(g->mlx, g->w, g->floor.img, c.x, c.y);
	c.x = (g->wsize.x / 2) - 42;
	c.y = g->wsize.y - 60;
	mlx_string_put(g->mlx, g->w, c.x, c.y, WHITE, YOU_WON_MSG1);
	c.x = (g->wsize.x / 2) - 112;
	c.y += 32;
	mlx_string_put(g->mlx, g->w, c.x, c.y, WHITE, YOU_WON_MSG2);
}

int	exit_game(t_game *g)
{
	int	i;

	i = -1;
	while (g->map[++i])
		free(g->map[i]);
	free(g->map);
	mlx_destroy_window(g->mlx, g->w);
	destroy_all_images(g);
	exit(0);
}
