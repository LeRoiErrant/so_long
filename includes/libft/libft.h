/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vheran <vheran@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 12:42:51 by vheran            #+#    #+#             */
/*   Updated: 2021/12/18 11:30:04 by vheran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# define HEX_UP "0123456789ABCDEF"
# define HEX_LOW "0123456789abcdef"
# define OCTAL "01234567"
# define DECIMAL "0123456789"
# define BUFFER_SIZE 1
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <limits.h>
# include <stdbool.h>
# include <stdio.h>
# include "ft_printf/libftprintf.h"

typedef struct s_list
{
	void			*content;
	struct s_list	*next;	
}					t_list;

//---Fonctions Booleenes---//
int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_isalnum(int c);
int				ft_isascii(int c);
int				ft_isprint(int c);
int				ft_iswhitespace(int c);
//---Fonctions de conversion--//
int				ft_toupper(int c);
int				ft_tolower(int c);
int				ft_atoi(const char *nptr);
long long int	ft_atoi_base(const char *nptr, char *base);
char			*ft_itoa(long long int n);
char			*ft_itoa_base(long long int n, char *base);
char			*ft_itohex(int n, char *uppercase);
char			*ft_convert_base(char *str, char *bsrc, char *bdst);
char			*ft_ulltoa_base(unsigned long long n, char *base);
//---Fonctions d'écriture---//
size_t			ft_putchar_fd(char c, int fd);
size_t			ft_putstr_fd(char *s, int fd);
size_t			ft_putendl_fd(char *s, int fd);
size_t			ft_putnbr_fd(int n, int fd);
size_t			ft_putnbase_fd(int n, char *base, int fd);
size_t			ft_putunsigned_fd(int n, int fd);
size_t			ft_putubase_fd(unsigned long n, char *base, int fd);
//---Fonctions STR---//
size_t			ft_strlen(const char *s);
size_t			ft_strlcat(char *dst, const char *src, size_t dstsize);
size_t			ft_strlcpy(char *dst, const char *src, size_t dstsize);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
char			*ft_strchr(const char *s, int c);
char			*ft_strrchr(const char *s, int c);
char			*ft_strnstr(const char *haystack, const char *needle, size_t l);
char			*ft_strdup(const char *s1);
char			*ft_strldup(const char *s1, size_t max);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s1, char const *set);
char			**ft_split(char const *s, char c);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
//---Fonctions MEM---//
void			*ft_memset(void *b, int c, size_t len);
void			ft_bzero(void *s, size_t n);
void			*ft_memcpy(void *dst, const void *src, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
void			*ft_memmove(void *dst, const void *src, size_t len);
void			*ft_memchr(const void *s, int c, size_t n);
//---Fonctions d'allocation de mémoire---//
void			*ft_calloc(size_t count, size_t size);
//---Fonctions LST---//
int				ft_lstsize(t_list *lst);
t_list			*ft_lstnew(void *content);
t_list			*ft_lstlast(t_list *lst);
void			ft_lstadd_front(t_list **alst, t_list *new);
void			ft_lstadd_back(t_list **alst, t_list *new);
void			ft_lstdelone(t_list *lst, void (*del)(void *));
void			ft_lstclear(t_list **lst, void (*del)(void *));
void			ft_lstiter(t_list *lst, void (*f)(void *));
t_list			*ft_lstmap(t_list *l, void *(*f)(void *), void (*del)(void *));
//---Get_Next_Line---//
char			*get_next_line(int fd);

#endif