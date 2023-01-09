/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vheran <vheran@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 11:28:07 by vheran            #+#    #+#             */
/*   Updated: 2023/01/09 18:25:19 by vheran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long_bonus.h"

void	get_player_first_pos(t_game *g, char **map)
{
	int		x;
	int		y;

	y = -1;
	while (map[++y])
	{
		x = -1;
		while (map[y][++x])
		{
			if (map[y][x] == 'P')
			{
				g->pc.pos.x = x;
				g->pc.pos.y = y;
				map[y][x] = '0';
			}
		}
	}
}

void	init_game(t_game *g)
{
	if (g->msize.x < 11)
		g->size = 64;
	else
		g->size = 32;
	g->wsize.x = g->msize.x * g->size;
	g->wsize.y = (g->msize.y * g->size) + 64;
	if (g->size == 64)
		load_all_tex_64(g);
	else
		load_all_tex_32(g);
	g->moves = 0;
	g->loot_c = count_loot(g->map);
	get_player_first_pos(g, g->map);
	g->end_screen = 0;
	g->loose_scr = 0;
	g->framect = FRAMECOUNT;
	g->pc.dir = D;
	g->pc.current = g->pc.sprr.img;
	g->npc.cl = g->npc.sl0.img;
	g->npc.cr = g->npc.sr0.img;
	g->loot.current = g->loot.loot0.img;
	g->exit.current = g->exit.off.img;
	g->frame = 0;
	g->move = true;
}

void	open_game(t_game *g)
{
	g->mlx = mlx_init();
	init_game(g);
	g->w = mlx_new_window(g->mlx, g->wsize.x, g->wsize.y, "so_long");
	draw_map(g);
	print_hud(g, KEY_HUD);
	mlx_hook(g->w, 2, 0, ft_key_event, g);
	mlx_key_hook(g->w, ft_key_event_two, g);
	mlx_hook(g->w, 17, 1L << 5, exit_game, g);
	mlx_loop_hook(g->mlx, anim_frames, g);
	mlx_loop(g->mlx);
}

int	main(int argc, char **argv)
{
	t_game	g;
	int		err;

	if (argc != 2)
		error_arg(0);
	g.map_path = ft_strdup(argv[1]);
	if (!check_extension(g.map_path))
		error_arg(1);
	if (!parse_map(g.map_path, &g))
	{
		ft_putstr_fd("Error\nParsing error!\n", 2);
		exit(EXIT_FAILURE);
	}
	err = check_map(g.map, g.msize);
	if (err)
		error_map(err, &g);
	else
		open_game(&g);
	return (0);
}
