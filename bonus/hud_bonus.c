/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hud_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vheran <vheran@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 17:12:25 by vheran            #+#    #+#             */
/*   Updated: 2023/01/09 12:40:11 by vheran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long_bonus.h"

static void	print_cant_leave_yet(t_game *g, int loot_c)
{
	char	*msg;
	char	*bl;
	t_coord	c;

	c.x = (g->wsize.x / 2) - 100;
	c.y = g->wsize.y - 60;
	mlx_string_put(g->mlx, g->w, c.x, c.y, WHITE, CANT_LEAVE_MSG);
	if (loot_c == 1)
	{
		msg = ft_strdup(BEER_LEFT_MSG);
		c.x = (g->wsize.x / 2) - 125;
	}
	else
	{
		bl = ft_itoa(g->loot_c);
		msg = ft_strjoin(bl, BEERS_LEFT_MSG);
		free(bl);
		c.x = (g->wsize.x / 2) - 134;
	}
	c.y += 32;
	mlx_string_put(g->mlx, g->w, c.x, c.y, WHITE, msg);
	free(msg);
}

static void	print_scores(t_game *g)
{
	char	*msg;
	char	*tmp;
	char	*mv;
	char	*bc;
	t_coord	c;

	c.x = (g->wsize.x / 2) - 153;
	c.y = g->wsize.y - 40;
	(void) bc;
	mv = ft_itoa(g->moves);
	msg = ft_strjoin("Moves: ", mv);
	tmp = ft_strdup(msg);
	free(mv);
	free(msg);
	msg = ft_strjoin(tmp, "         ");
	free(tmp);
	tmp = ft_strdup(msg);
	free(msg);
	msg = ft_strjoin(tmp, "Collectibles: ");
	free(tmp);
	tmp = ft_strdup(msg);
	free(msg);
	bc = ft_itoa(g->loot_c);
	msg = ft_strjoin(tmp, bc);
	free(tmp);
	free(bc);
	mlx_string_put(g->mlx, g->w, c.x, c.y, WHITE, msg);
	free(msg);
}

static void	print_cant_move(t_game *g)
{
	t_coord	c;

	c.x = (g->wsize.x / 2) - 96;
	c.y = g->wsize.y - 60;
	mlx_string_put(g->mlx, g->w, c.x, c.y, WHITE, CANT_MOVE_MSG1);
	c.x = (g->wsize.x / 2) - 128;
	c.y += 32;
	mlx_string_put(g->mlx, g->w, c.x, c.y, WHITE, CANT_MOVE_MSG2);
}

static void	print_key_msg(t_game *g)
{
	t_coord	c;

	c.x = (g->wsize.x / 2) - 80;
	c.y = g->wsize.y - 60;
	mlx_string_put(g->mlx, g->w, c.x, c.y, WHITE, KEY_MSG1);
	c.x = (g->wsize.x / 2) - 60;
	c.y += 32;
	mlx_string_put(g->mlx, g->w, c.x, c.y, WHITE, KEY_MSG2);
}

void	print_hud(t_game *g, int msgno)
{
	t_coord	c;

	c.y = g->wsize.y - 64;
	mlx_put_image_to_window(g->mlx, g->w, g->erase.img, 0, c.y);
	if (msgno == SCORES_HUD)
		print_scores(g);
	else if (msgno == CANT_MOVE)
		print_cant_move(g);
	else if (msgno == CANT_LEAVE)
		print_cant_leave_yet(g, g->loot_c);
	else if (msgno == YOU_WON)
		you_won(g);
	else if (msgno == KEY_HUD)
		print_key_msg(g);
	else if (msgno == YOU_DIED)
		you_died(g);
}
