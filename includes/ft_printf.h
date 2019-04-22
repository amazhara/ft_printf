/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazas <vbrazas@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 14:16:54 by amazhara          #+#    #+#             */
/*   Updated: 2018/12/26 17:19:23 by vbrazas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FT_PRINTF_H
# define _FT_PRINTF_H

# include <stdarg.h>
# include "libft.h"

typedef struct		s_flag_printf
{
	uint			zero	: 1;
	uint			hash	: 1;
	uint			minus	: 1;
	uint			plus	: 1;
	uint			space	: 1;
	uint			l		: 1;
	uint			ll		: 1;
	uint			lol		: 1;
	uint			z		: 1;
	uint			j		: 1;
	uint			h		: 1;
	uint			hh		: 1;
	uint			tmp		: 1;
	uint			wtmp	: 1;
	uint			ch_size	: 1;
	char			symbol;
	int				outlen;
	int				iter;
	intmax_t		ch;
	intmax_t		base;
	intmax_t		width;
	intmax_t		percision;
	intmax_t		dsave;
	uintmax_t		len;

}					t_flag_printf;

typedef struct		s_printf
{
	int				count;
	size_t			i;
	char			*buf;
	t_flag_printf	m;

}					t_printf;

int					pars_and_process(const char *str, t_printf *p
, va_list *ap, int i);
int					width_star(t_printf *p, va_list ap, int i);
int					presicion_star(t_printf *p, va_list ap, int i);
int					p_precision(t_printf *p, int i
, const char *str, va_list *ap);
int					case_l_j_z(t_printf *p, const char *str, int i);
void				check_buff(t_printf *p, char c);
void				process_d_i(t_printf *p, va_list ap);
void				process_s(t_printf *p, va_list ap);
void				process_c(t_printf *p, va_list ap);
void				process_u_x(t_printf *p, va_list ap);
void				process_p(t_printf *p, va_list ap);
void				process_f(t_printf *p, va_list ap);
void				process_pc(t_printf *p);
void				output_buf_x(t_printf *p);
void				output_buf_per_x(t_printf *p);
void				output_f(t_printf *p, char *out);
void				pars_u_x(t_printf *p, char c, va_list *ap);
char				*ft_fitoa(long double arg);
uintmax_t			count_f(long double arg, t_printf *p);
uintmax_t			ft_base_len(uintmax_t n, uintmax_t base);
uintmax_t			check_type_unsigned(t_printf *p, va_list ap);
intmax_t			check_type_signed(t_printf *p, va_list ap);
long double			check_type_double(t_printf *p, va_list ap);

#endif
