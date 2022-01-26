/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vheran <vheran@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 18:57:50 by vheran            #+#    #+#             */
/*   Updated: 2022/01/13 14:43:01 by vheran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

int	ft_key_event(int keyc, t_game *g)
{
	if (keyc == ESC)
		exit_game(g);
	else if (keyc == W)
		check_move(g, 0, -1);
	else if (keyc == A)
		check_move(g, -1, 0);
	else if (keyc == S)
		check_move(g, 0, 1);
	else if (keyc == D)
		check_move(g, 1, 0);
	else
		print_hud(g, KEY_HUD);
	return (0);
}
