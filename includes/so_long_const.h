/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_const.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vheran <vheran@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 15:02:37 by vheran            #+#    #+#             */
/*   Updated: 2021/12/18 15:02:37 by marvin           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_CONST_H
# define SO_LONG_CONST_H
/*  ***********************************	*/
/*				   PC tex 				*/
/*  ***********************************	*/
# define PC_P32L0 "./textures/PC/PC_left_32.xpm"
# define PC_P32L1 "./textures/PC/PC_left1_32.xpm"
# define PC_P32L2 "./textures/PC/PC_left2_32.xpm"
# define PC_P64L0 "./textures/PC/PC_left_64.xpm"
# define PC_P64L1 "./textures/PC/PC_left1_64.xpm"
# define PC_P64L2 "./textures/PC/PC_left2_64.xpm"
# define PC_P32R0 "./textures/PC/PC_right_32.xpm"
# define PC_P32R1 "./textures/PC/PC_right1_32.xpm"
# define PC_P32R2 "./textures/PC/PC_right2_32.xpm"
# define PC_P64R0 "./textures/PC/PC_right_64.xpm"
# define PC_P64R1 "./textures/PC/PC_right1_64.xpm"
# define PC_P64R2 "./textures/PC/PC_right2_64.xpm"
/*  ***********************************	*/
/*				   NPC tex 				*/
/*  ***********************************	*/
# define NPC_P32L0 "./textures/NPC/npc_L_0_32.xpm"
# define NPC_P32L1 "./textures/NPC/npc_L_1_32.xpm"
# define NPC_P32L2 "./textures/NPC/npc_L_2_32.xpm"
# define NPC_P32L3 "./textures/NPC/npc_L_3_32.xpm"
# define NPC_P64L0 "./textures/NPC/npc_L_0_64.xpm"
# define NPC_P64L1 "./textures/NPC/npc_L_1_64.xpm"
# define NPC_P64L2 "./textures/NPC/npc_L_2_64.xpm"
# define NPC_P64L3 "./textures/NPC/npc_L_3_64.xpm"
# define NPC_P32R0 "./textures/NPC/npc_R_0_32.xpm"
# define NPC_P32R1 "./textures/NPC/npc_R_1_32.xpm"
# define NPC_P32R2 "./textures/NPC/npc_R_2_32.xpm"
# define NPC_P32R3 "./textures/NPC/npc_R_3_32.xpm"
# define NPC_P64R0 "./textures/NPC/npc_R_0_64.xpm"
# define NPC_P64R1 "./textures/NPC/npc_R_1_64.xpm"
# define NPC_P64R2 "./textures/NPC/npc_R_2_64.xpm"
# define NPC_P64R3 "./textures/NPC/npc_R_3_64.xpm"
/*  ***********************************	*/
/*				  Loot tex 				*/
/*  ***********************************	*/
# define LOOT_P32 "./textures/loot/loot_32_0.xpm"
# define LOOT_P321 "./textures/loot/loot_32_1.xpm"
# define LOOT_P322 "./textures/loot/loot_32_2.xpm"
# define LOOT_P64 "./textures/loot/loot_64_0.xpm"
# define LOOT_P641 "./textures/loot/loot_64_1.xpm"
# define LOOT_P642 "./textures/loot/loot_64_2.xpm"
/*  ***********************************	*/
/*		  Floor, Walls & Exit tex 		*/
/*  ***********************************	*/
# define FLOOR_P32 "./textures/floor/floor_dark_32.xpm"
# define FLOOR_P64 "./textures/floor/floor_dark_64.xpm"
# define WALL_P32 "./textures/wall/wall_32.xpm"
# define WALL_P64 "./textures/wall/wall_64.xpm"
# define EXIT0_P32 "./textures/exit/exit_off_32.xpm"
# define EXIT0_P64 "./textures/exit/exit_off_64.xpm"
# define EXIT1_P32 "./textures/exit/exit_on_32.xpm"
# define EXIT1_P64 "./textures/exit/exit_on_64.xpm"
/*  ***********************************	*/
/*		   HUD codes & messages			*/
/*  ***********************************	*/
# define SCORES_HUD 1
# define CANT_MOVE 2
# define CANT_LEAVE 3
# define YOU_WON 4
# define KEY_HUD 5
# define CANT_MOVE_MSG "You can't go there! Did you not see the wall?"
# define CANT_LEAVE_MSG "You can't leave yet!"
# define BEER_LEFT_MSG "1 beer left to find!"
# define BEERS_LEFT_MSG " beers left to find!"
# define YOU_WON_MSG "Congrats! You escaped the Matrix!"
# define KEY_MSG "Use WASD to move! Collect all the beers!"
/*  ***********************************	*/
/*			   Configuration 			*/
/*  ***********************************	*/
# define BLACK 0x00000000
# define ELEMCODES "01ECP"
/*  ***********************************	*/
/*				 Key codes 				*/
/*  ***********************************	*/
# define ESC 53
# define W 13
# define A 0
# define S 1
# define D 2
/*  ***********************************	*/
/*			   Error messages 			*/
/*  ***********************************	*/
# define ERR_ARGC "Error\nSelect 1 map to play!\n"
# define ERR_EXT "Error\nWrong extension file (.ber)!\n"
# define ERR_WALLS "Error\nThe map must be closed by walls!\n"
# define ERR_NOEXIT "Error\nNo exit!\n"
# define ERR_NOCOLL "Error\nNo collectible!\n"
# define ERR_NOSTART "Error\nNo starting position!\n"
# define ERR_RECT "Error\nMap must be rectangular!\n"
# define ERR_CHAR "Error\nInvalid character in map!\n"

#endif