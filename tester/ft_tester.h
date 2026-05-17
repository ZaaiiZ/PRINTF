/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tester.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victor <victor.horel@learner.42.tech>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 19:03:11 by victor            #+#    #+#             */
/*   Updated: 2026/05/15 20:45:29 by victor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TESTER_H
# define FT_TESTER_H

# include <fcntl.h>
# include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>
#include <limits.h>
#include <string.h>

typedef struct s_format
{
	int		flag_plus;		//'+'
	int		flag_minus;		//'-'
	int		flag_zero;		//'0'
	int		flag_space;		//' '
	int		flag_hash;		//'#'
	int		has_width;
	int		width;
	int		has_precision;
	int		precision;
	char	specifier;
}	t_format;

int			ft_printf(const char *format, ...);
int			ft_vprintf(const char *format, va_list *arg);

const char	*ft_parse_format(const char *format, t_format *frm, va_list *arg);

int			ft_print_c(t_format	*frm, int nbr);
int			ft_print_s(t_format *frm, char *str);
int			ft_print_p(t_format *frm, void *p);
int			ft_print_d(t_format *frm, int nbr);
int			ft_print_u(t_format *frm, unsigned int unbr);
int			ft_print_x(t_format *frm, unsigned int unbr);

int			ft_isflag(char chr);
int			ft_isspecifier(char chr);
void		ft_putnchr(char chr, int n);
void		ft_putnstr(char *str, int n);
void		ft_putptr_fd(uintptr_t ptr, int fd);
void		ft_putulnbr_fd(unsigned long ulnbr, int fd);
void		ft_putxnbr_fd(unsigned int unbr, char *base, int fd);

typedef struct s_tester_format
{
	int		width_is_star;
	int		star_width;
	int		precision_is_star;
	int		star_precision;
	char	specifier;
}	t_tester_format;

int			ft_tester(char type_test, const char *format, ...);

const char	*ft_parse_tester_format(const char *format, t_tester_format *frm, va_list *arg);

void		ft_putbuffer_fd(char *buffer, int size, int fd);

void		ft_test_c(void);
void		ft_test_s(void);
void		ft_test_p(void);
void		ft_test_d(void);
void		ft_test_i(void);
void		ft_test_u(void);
void		ft_test_x(void);
void		ft_test_X(void);
void		ft_test_percent(void);


typedef struct	s_list
{
	void	*content;
	struct s_list *next;
}	t_list;

/*
  Fonctions Principales
*/

int		ft_tolower(int c);
int		ft_toupper(int c);
size_t	ft_strlen(const char *s);
int		ft_isascii(int c);
int		ft_atoi(const char *str);
int		ft_isdigit(int c);
int		ft_isalpha(int c);
int		ft_isprint(int c);
int		ft_isalnum(int c);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strstr(const char *haystack, const char *needle);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
char	*ft_strcat(char * s1, const char * s2);
char	*ft_strncat(char * s1, const char * s2, size_t n);
size_t	ft_strlcat(char * dst, const char * src, size_t dstsize);
char	*ft_strcpy(char *dst, const char *src);
char	*ft_strncpy(char *dst, const char *src, size_t len);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
char	*ft_strdup(const char *s1);
void	*ft_memset(void *b, int c, size_t len);
void	ft_bzero(void *s, size_t n);
void	*ft_memcpy(void * dst, const void * src, size_t n);
void	*ft_memccpy(void * dst, const void * src, int c, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t len);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_calloc(size_t count, size_t size);

/*
  Fonctions supplementaires
*/

void	ft_putchar(char c);
void	ft_putstr(char const *s);
void	ft_putnbr(int n);
void	*ft_memalloc(size_t size);
void	ft_memdel(void **ap);
char	*ft_strnew(size_t size);
void	ft_strdel(char **as);
void	ft_strclr(char *s);
void	ft_striter(char *s, void (*f)(char*));
void	ft_striteri(char *s, void (*f)(unsigned int, char *));
char	*ft_strmap(char const *s, char (*f)(char));
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int		ft_strequ(char const *s1, char const *s2);
int		ft_strnequ(char const *s1, char const *s2, size_t n);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(const char *s1, const char *set);
char	**ft_split(const char *s, char c);
char	*ft_itoa(int n);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);

/*
  Fonctions bonus
*/

int		ft_isspace(int c);
t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void*));
void	ft_lstclear(t_list **lst, void(*del)(void*));
void	ft_lstiter(t_list *lst, void (*f)(void*));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void*), void (*del)(void*));

#endif
