# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vheran <vheran@student.42lausanne.ch>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/27 16:22:31 by vheran            #+#    #+#              #
#    Updated: 2021/12/20 15:22:25 by vheran           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
TEST_NAME = test_l

CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRC = 

OBJS = $(SRC:.c=.o)

LIBS = my_libft.a libftprintf.a

BONUS_SRC = 

BONUS_OBJS = $(BONUS_SRC:.c=.o)

GR = \033[32;1m
RC = \033[0m
YE = \033[33;1m

all: ${NAME}

$(NAME): ${OBJS}
	@$(MAKE) all -C ./ft_printf
	@cp ft_printf/libftprintf.a my_libft/my_libft.a
	@rm -f ft_printf/libftprintf.a
	@$(MAKE) all -C ./my_libft
	@cp my_libft/my_libft.a libft.a
	@rm -f my_libft/my_libft.a
	@printf "$(GR)Libft ready !$(RC)\n\n\n"

bonus: ${OBJS} ${BONUS_OBJS}
	ar rc ${NAME} ${OBJS} ${BONUS_OBJS}

clean:
	@printf "$(YE) Cleaning Libft...\n"
	@$(MAKE) clean -C ./my_libft
	@$(MAKE) clean -C ./ft_printf
	@rm -f *.o
	@printf "$(GR) => Libft cleaned!$(RC)\n"

fclean: clean
	@printf "$(YE) Full cleaning Libft...\n"
	@$(MAKE) fclean -C ./my_libft
	@$(MAKE) fclean -C ./ft_printf
	@rm -f $(NAME)
	@printf "$(GR) => Libft fully cleaned!$(RC)\n"

re: fclean all

.PHONY: all bonus clean fclean re