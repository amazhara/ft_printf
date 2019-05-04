/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazhara <amazhara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/30 14:25:06 by amazhara          #+#    #+#             */
/*   Updated: 2019/04/25 16:42:53 by amazhara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# define BUFF_SIZE 128
# include <sys/types.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include <stdint.h>
# include <stdbool.h>

typedef __int128_t	t_bzero_padd;

int					ft_printf(const char *str, ...);

/*
******************								******************
******************			Ft_array			******************
******************								******************
*/

typedef struct		s_array
{
	void			**arr;
	ssize_t			len;
	ssize_t			max;
}					t_array;

void				*new_array(size_t amount);
void				*push_array(void *dst, void *elem);

/*
******************								******************
******************		My get_line function	******************
******************								******************
*/

typedef struct		s_chain
{
	int				fd;
	char			*save;
	struct s_chain	*next;
}					t_chain;

int					get_next_line(int fd, char **line);

/*
******************								******************
****************** 	Funcions to allocate memory ******************
******************								******************
*/

void				*ft_memalloc(size_t size);
char				*ft_itoa(intmax_t n);
char				*ft_itoa_base(uintmax_t n, uintmax_t base, uintmax_t size);
char				*ft_strnjoin(char const *s1, char const *s2,
					char const *s3);
char				**ft_double_malloc(int y, int x);
char				*ft_strdup(const char *str);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strnew(size_t size);
char				*ft_strndup(const char *s1, size_t n);

/*
******************								******************
****************** 		Free memory funcions	******************
******************								******************
*/

void				ft_double_free(char **arr, int len);
void				ft_strdel(char **as);

/*
******************								******************
****************** 		Memory set funcions		******************
******************								******************
*/

void				ft_bzero(void *s, size_t n);
void				ft_memdel(void **ap);
void				*ft_memset(void *b, int c, size_t len);
void				*ft_memchr(const void *s, int c, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memccpy(void *restrict dst, const void *restrict src,
					int c, size_t n);
void				*ft_memcpy(void *restrict dst, const void *restrict src,
					size_t n);

/*
******************								******************
****************** Check & Change ascii values	******************
******************								******************
*/

int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
int					ft_isnum(char *str);

/*
******************								******************
******************			  Other				******************
******************								******************
*/

int					ft_sqrt(int n);
size_t				ft_strlen(const char *str);
int					strchr_count(char *line, char symbol);
int					ft_atoi(const char *str);
char				*ft_strpbrk(const char *s, const char *ch);
char				*ft_strnpbrk(const char *s, const char *ch, size_t len);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strtrim(char const *s);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strncpy(char *dst, const char *src, size_t len);
char				*ft_strcat(char *restrict s1, const char *restrict s2);
char				*ft_strchr(const char *s, int c);
char				**ft_strsplit(char const *s, char c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *s1, const char *s2);
char				*ft_strnstr(const char *s1, const char *s2, size_t len);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_modul(int x, int y);
intmax_t			ft_intlen(intmax_t c);
uintmax_t			ft_uintlen(uintmax_t c);
char				*ft_strncat(char *restrict s1, const char *restrict s2
, size_t len);
size_t				ft_strlcat(char *restrict dst, const char *restrict src
, size_t dstsize);
void				ft_swap(void **a, void **b);

#endif
