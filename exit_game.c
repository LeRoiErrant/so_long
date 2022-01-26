/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vheran <vheran@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 19:00:02 by vheran            #+#    #+#             */
/*   Updated: 2021/12/23 11:03:12 by vheran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

static void	destroy_all_images(t_game *g)
{
	mlx_destroy_image(g->mlx, g->floor.img);
	mlx_destroy_image(g->mlx, g->pc.spr.img);
	mlx_destroy_image(g->mlx, g->wall.img);
	mlx_destroy_image(g->mlx, g->exit.off.img);
	mlx_destroy_image(g->mlx, g->exit.on.img);
	mlx_destroy_image(g->mlx, g->erase.img);
}

int	exit_game(t_game *g)
{
	int	i;

	printf("\n");
	i = -1;
	while (g->map[++i])
		free(g->map[i]);
	free(g->map);
	mlx_destroy_window(g->mlx, g->w);
	destroy_all_images(g);
	exit(0);
}
