# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vheran <vheran@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/18 10:58:26 by vheran            #+#    #+#              #
#    Updated: 2022/01/18 13:50:57 by vheran           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# **************************************************************************** #
#							PROJECT'S DIRECTORY								   #
# **************************************************************************** #

NAME = so_long
NAME_BONUS = so_long_bonus
INCL_DIR = ./includes
BONUS_DIR = ./bonus/
MLX = minilibx

# **************************************************************************** #
#						COMPILATION AND LINK FLAGS							   #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
FRAMEWORKS = -framework OpenGL -framework AppKit
LIB_FLAGS = -L ${INCL_DIR}/libft -l ft
LIB_FLAGS +=  -L ${INCL_DIR}/${MLX} -l mlx

# **************************************************************************** #
#								SOURCE FILES								   #
# **************************************************************************** #

SRC = main.c hud.c parse.c check_errors.c errors.c gnl_wo_nl.c textures.c exit_game.c \
	hooks.c loot.c map.c moves.c
SRC_BONUS = main_bonus.c hud_bonus.c parse_bonus.c check_errors_bonus.c errors_bonus.c \
	gnl_wo_nl_bonus.c textures_bonus.c exit_game_bonus.c hooks_bonus.c loot_bonus.c \
	map_bonus.c moves_bonus.c load_all_tex_bonus.c animation.c npc_bonus.c npc_moves_bonus.c
SRC_BONUS := $(addprefix $(BONUS_DIR), $(SRC_BONUS))
OBJS = $(SRC:.c=.o)
OBJS_BONUS = $(SRC_BONUS:.c=.o)

# **************************************************************************** #
#								COLORS										   #
# **************************************************************************** #

GR = \033[32;1m
RE = \033[31;1m
YE = \033[33;1m
CY = \033[36;1m
RC = \033[0m

# **************************************************************************** #
#							MAKEFILE RULES									   #
# **************************************************************************** #

all: ${NAME}

${NAME}: compil_libs ${OBJS} c_done
	@${CC} ${CFLAGS} ${LIB_FLAGS} ${OBJS} -o ${NAME} ${FRAMEWORKS}
	@printf "$(GR)\n#************************#\n"
	@printf "#                        #\n"
	@printf "#  Usage:                #\n"
	@printf "#  ./${NAME} [MAP_NAME]  #\n"
	@printf "#                        #\n"
	@printf "#************************#$(RC)\n"

bonus: compil_libs ${OBJS_BONUS} c_done
	@${CC} ${CFLAGS} ${LIB_FLAGS} ${OBJS_BONUS} ${FRAMEWORKS} -o ${NAME_BONUS}
	@printf "$(GR)\n#******************************#\n"
	@printf "#                              #\n"
	@printf "#  Usage:                      #\n"
	@printf "#  ./so_long_bonus [MAP_NAME]  #\n"
	@printf "#                              #\n"
	@printf "#******************************#$(RC)\n"

compil_libs:
	@$(MAKE) all -C ./includes/libft
	@printf "$(CY)\nCompiling Minilibx...\n\n"
	@$(MAKE) all -C ./includes/${MLX}
	@printf "\nMinilibx ready !$(RC)\n\n\n"

.c.o:
	@${CC} ${CFLAGS} -o $@ -c $<
	@printf "$(GR)|"

compile:
	@echo "\n$(GR)[X] Compiling so_long$(RC)\n"

c_done:
	@echo "\n"

clean:
	@printf "\n$(YE)Cleaning...\n"
	@$(MAKE) clean -C ./includes/libft
	@printf "$(YE) Cleaning Minilibx...\n"
	@$(MAKE) clean -C ./includes/${MLX}
	@printf "$(GR) => Minilibx cleaned!$(RC)\n"
	@rm -f ${OBJS}
	@rm -f ${OBJS_BONUS}
	@printf "$(GR)=> Cleaning complete!$(RC)\n\n"

fclean: clean
	@printf "$(YE)Full cleaning...\n"
	@$(MAKE) fclean -C ./includes/libft
	@rm -f ${NAME}
	@rm -f ${NAME_BONUS}
	@printf "$(GR)=> Full cleaning complete!$(RC)\n\n"

re: fclean all

.PHONY: all bonus clean fclean re


# **************************************************************************** #
#	@printf "$(YE) Full cleaning Minilibx...\n"
#	@$(MAKE) fclean -C ./includes/${MLX}
#	@printf "$(GR) => Minilibx fully cleaned!$(RC)\n"
# **************************************************************************** #