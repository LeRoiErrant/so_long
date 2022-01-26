# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vheran <vheran@student.42lausanne.ch>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/08 10:59:31 by vheran            #+#    #+#              #
#    Updated: 2021/12/20 15:20:16 by vheran           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRC = ft_printf.c ft_printf_format.c ft_printf_is_x.c ft_treat_pf_flags.c \
	ft_printf_width.c ft_treat_pf_flags_opt.c ft_printf_width_nbr.c \
	ft_printf_char.c ft_printf_str.c ft_printf_nbr.c ft_printf_hex.c \
	ft_printf_uns.c ft_printf_ptr.c

OBJS = $(SRC:.c=.o)

LIBS = libftprintf.a

BONUS_SRC = 

BONUS_OBJS = $(BONUS_SRC:.c=.o)

GR = \033[32;1m
RC = \033[0m

all: ${NAME}
	
$(NAME): compile $(OBJS)
	@ar rcs ${NAME} ${OBJS}

.c.o:
	@${CC} ${CFLAGS} -o $@ -c $<
	@printf "$(GR)|"

compile:
	@echo "\n$(GR)[X] Compiling Libft$(RC)\n"

clean:
	@rm -f *.o
	@rm -f bonus/*.o

fclean: clean
	@rm -f $(NAME)

re: fclean all

bonus: ${BONUS_OBJS}
	ar rc ${NAME} ${BONUS_OBJS}

.PHONY: all clean fclean re bonus test
