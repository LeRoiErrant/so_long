/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vheran <vheran@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 11:24:13 by vheran            #+#    #+#             */
/*   Updated: 2022/01/13 14:42:59 by vheran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <fcntl.h>
# include "./libft/libft.h"
# include "./minilibx/mlx.h"
# include "so_long_const.h"
# include "so_long_struct.h"

/*  ***********************************	*/
/*				   Game 				*/
/*  ***********************************	*/
void	open_game(t_game *g);
void	print_hud(t_game *g, int msgno);

/*  ***********************************	*/
/*				 Parse&Map				*/
/*  ***********************************	*/
char	**parse_map(char *path, t_game *g);
char	*gnl_wo_nl(int fd);
int		count_loot(char	**map);
void	get_player_first_pos(t_game *g, char **map);
void	draw_map(t_game *g);
void	draw_square(t_game *g, int x, int y);

/*  ***********************************	*/
/*			   Textures&Images			*/
/*  ***********************************	*/
void	my_mlx_pixel_put(t_img *img, int x, int y, int color);
void	load_tex(t_game *g, t_tex *t, char *path);
void	load_all_tex_64(t_game *g);
void	load_all_tex_32(t_game *g);

/*  ***********************************	*/
/*			   	   Moves				*/
/*  ***********************************	*/
void	check_move(t_game *g, int xd, int yd);
void	move(t_game *g, int xd, int yd);
void	move_pc(t_game *g, int xd, int yd);

/*  ***********************************	*/
/*			   	   Hooks				*/
/*  ***********************************	*/
int		ft_key_event(int keyc, t_game *g);

/*  ***********************************	*/
/*			   	   Events				*/
/*  ***********************************	*/
int		exit_game(t_game *g);
void	collect_loot(t_game *g, int x, int y);

/*  ***********************************	*/
/*				  Errors				*/
/*  ***********************************	*/
int		check_extension(char *path);
int		check_map(char **map, t_coord size);
void	error_arg(int err_no);
void	error_map(int err_no, t_game *g);

#endif