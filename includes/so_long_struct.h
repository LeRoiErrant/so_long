/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_struct.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vheran <vheran@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 13:16:37 by vheran            #+#    #+#             */
/*   Updated: 2021/12/23 11:02:37 by vheran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_STRUCT_H
# define SO_LONG_STRUCT_H

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
	t_tex	spr;
}			t_pc;

typedef struct s_exit
{
	t_tex	on;
	t_tex	off;
}			t_exit;

typedef struct s_game
{
	void	*mlx;
	void	*w;
	char	**map;
	int		moves;
	int		loot_c;
	int		size;
	t_coord	msize;
	t_coord	wsize;
	t_img	erase;
	t_pc	pc;
	t_tex	loot;
	t_tex	wall;
	t_tex	floor;
	t_exit	exit;
}			t_game;

#endif
