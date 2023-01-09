/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_struct_bonus.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vheran <vheran@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 13:16:37 by vheran            #+#    #+#             */
/*   Updated: 2023/01/09 11:41:34 by vheran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_STRUCT_BONUS_H
# define SO_LONG_STRUCT_BONUS_H

typedef struct s_coord
{
	int	x;
	int	y;
}		t_coord;

typedef struct s_img
{
	void	*img;
	void	*addr;
	int		bpp;
	int		llen;
	int		endian;
}			t_img;

typedef struct s_tex
{
	void	*img;
	void	*addr;
	int		bpp;
	int		llen;
	int		endian;
	t_coord	wnh;
	char	*path;
}			t_tex;

typedef struct s_pc
{
	t_coord	pos;
	void	*current;
	t_tex	sprr;
	t_tex	sprr1;
	t_tex	sprr2;
	t_tex	sprl;
	t_tex	sprl1;
	t_tex	sprl2;
	int		dir;
}			t_pc;

typedef struct s_npc
{
	void	*cr;
	void	*cl;
	t_tex	sr0;
	t_tex	sr1;
	t_tex	sr2;
	t_tex	sr3;
	t_tex	sl0;
	t_tex	sl1;
	t_tex	sl2;
	t_tex	sl3;
}			t_npc;

typedef struct s_loot
{
	void	*current;
	t_tex	loot0;
	t_tex	loot1;
	t_tex	loot2;
}			t_loot;

typedef struct s_exit
{
	void	*current;
	t_tex	on;
	t_tex	off;
}			t_exit;

typedef struct s_frame {
	t_tex	wall;
	t_tex	left;
	t_tex	right;
	t_tex	cleft;
	t_tex	cright;
}	t_frame;

typedef struct s_game
{
	void	*mlx;
	void	*w;
	char	*map_path;
	char	**map;
	int		moves;
	int		loot_c;
	int		framect;
	int		frame;
	int		size;
	t_coord	msize;
	t_coord	wsize;
	t_img	erase;
	t_pc	pc;
	t_npc	npc;
	t_loot	loot;
	t_tex	wall;
	t_tex	water;
	t_frame	outer;
	t_tex	floor;
	t_exit	exit;
	int		end_screen;
	int		loose_scr;
	bool	move;
}			t_game;

#endif
