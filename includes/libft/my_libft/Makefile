# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vheran <vheran@student.42lausanne.ch>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/27 16:22:31 by vheran            #+#    #+#              #
#    Updated: 2021/12/20 15:20:42 by vheran           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = my_libft.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRC = ft_isalpha.c ft_isdigit.c ft_isalnum.c \
	ft_isascii.c ft_isprint.c ft_toupper.c \
	ft_tolower.c ft_strlen.c ft_strlcat.c \
	ft_strlcpy.c ft_atoi.c ft_strncmp.c \
	ft_strchr.c ft_strrchr.c ft_strnstr.c \
	ft_memset.c ft_bzero.c ft_memcpy.c \
	ft_memcmp.c ft_memmove.c ft_memchr.c \
	ft_strdup.c ft_calloc.c ft_substr.c \
	ft_strjoin.c ft_strtrim.c ft_split.c \
	ft_itoa.c ft_strmapi.c ft_striteri.c \
	ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c \
	ft_putnbr_fd.c ft_lstnew.c ft_lstadd_front.c \
	ft_lstsize.c ft_lstlast.c ft_lstadd_back.c \
	ft_lstdelone.c ft_lstclear.c ft_lstiter.c \
	ft_lstmap.c ft_putnbase_fd.c ft_putunsigned_fd.c \
	ft_putubase_fd.c ft_iswhitespace.c ft_atoi_base.c \
	ft_itoa_base.c ft_convert_base.c ft_itohex.c \
	ft_ulltoa_base.c ft_strldup.c get_next_line.c



OBJS = $(SRC:.c=.o)

BONUS_SRC = 

BONUS_OBJS = $(BONUS_SRC:.c=.o)

GR = \033[32;1m
RC = \033[0m

all: ${NAME}

$(NAME): ${OBJS} c_done
	@ar rc ${NAME} ${OBJS}

.c.o:
	@${CC} ${CFLAGS} -o $@ -c $<
	@printf "$(GR)|"

compile:
	@echo "\n$(GR)[X] Compiling My_Libft$(RC)\n"
	@printf "$(GR)[$(RC)"

c_done:
	@echo "$(GR) => 100%$(RC)\n"

bonus: ${OBJS} ${BONUS_OBJS}
	ar rc ${NAME} ${OBJS} ${BONUS_OBJS}

clean:
	@rm -f *.o

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re