/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vheran <vheran@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 11:24:13 by vheran            #+#    #+#             */
/*   Updated: 2023/01/09 18:25:37 by vheran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H
# include <fcntl.h>
# include "../../includes/libft/libft.h"
# include "../../includes/minilibx/mlx.h"
# include "so_long_const_bonus.h"
# include "so_long_struct_bonus.h"

/*  ***********************************	*/
/*				   Game 				*/
/*  ***********************************	*/
void	open_game(t_game *g);
void	init_game(t_game *g);
void	print_hud(t_game *g, int msgno);
void	restart_game(t_game *g);

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
void	load_pc_tex(t_game *g, int format);
void	load_npc_tex(t_game *g, int format);
void	load_loot_tex(t_game *g, int format);
int		anim_frames(t_game *g);
void	anim_npc(t_game *g, int frame);

/*  ***********************************	*/
/*			   	   Moves				*/
/*  ***********************************	*/
void	get_move_dir(t_game *g, int kc);
void	check_move(t_game *g, t_coord d);
void	move(t_game *g, t_coord d, t_coord pc);
void	move_pc(t_game *g, t_coord d, t_coord pc);
void	move_npc_up(t_game *g, int x, int y);
void	move_npc_left(t_game *g, int x, int y);
void	move_npc_down(t_game *g, int x, int y);
void	move_npc_right(t_game *g, int x, int y);

/*  ***********************************	*/
/*			   	   Hooks				*/
/*  ***********************************	*/
int		ft_key_event(int keyc, t_game *g);
int		ft_key_event_two(int keyc, t_game *g);

/*  ***********************************	*/
/*			   	   Events				*/
/*  ***********************************	*/
int		exit_game(t_game *g);
void	collect_loot(t_game *g, int x, int y);
void	you_won(t_game *g);
void	you_died(t_game *g);

/*  ***********************************	*/
/*				  Errors				*/
/*  ***********************************	*/
int		check_extension(char *path);
int		check_map(char **map, t_coord size);
void	error_arg(int err_no);
void	error_map(int err_no, t_game *g);

#endif