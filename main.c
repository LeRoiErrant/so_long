/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vheran <vheran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 11:28:07 by vheran            #+#    #+#             */
/*   Updated: 2022/01/18 13:36:45 by vheran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

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
			}
		}
	}
}

static void	init_game(t_game *g)
{
	if (g->msize.x < 11)
		g->size = 64;
	else
		g->size = 32;
	g->wsize.x = g->msize.x * g->size;
	g->wsize.y = g->msize.y * g->size;
	if (g->size == 64)
		load_all_tex_64(g);
	else
		load_all_tex_32(g);
	g->moves = 0;
	g->loot_c = count_loot(g->map);
	get_player_first_pos(g, g->map);
}

void	open_game(t_game *g)
{
	g->mlx = mlx_init();
	init_game(g);
	g->w = mlx_new_window(g->mlx, g->wsize.x, g->wsize.y, "so_long");
	draw_map(g);
	print_hud(g, SCORES_HUD);
	mlx_key_hook(g->w, ft_key_event, g);
	mlx_hook(g->w, 17, 1L << 5, exit_game, g);
	mlx_loop(g->mlx);
}

int	main(int argc, char **argv)
{
	t_game	g;
	int		err;

	if (argc != 2)
		error_arg(0);
	if (!check_extension(argv[1]))
		error_arg(1);
	if (!parse_map(argv[1], &g))
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
