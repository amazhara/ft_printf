/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_f.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazhara <amazhara@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 14:04:52 by amazhara          #+#    #+#             */
/*   Updated: 2018/12/23 14:42:17 by amazhara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long double	f_minus_plus_case(t_printf *p, long double arg)
{
	if (arg < 0)
	{
		check_buff(p, '-');
		arg < 0 ? arg *= -1 : false;
	}
	if (p->m.plus)
	{
		check_buff(p, '+');
		p->m.plus = false;
	}
	if (p->m.space && (p->m.width > p->m.percision))
	{
		check_buff(p, ' ');
		p->m.width ? --p->m.width : false;
		p->m.space = false;
	}
	if (p->m.space && !p->m.width)
	{
		check_buff(p, ' ');
		p->m.width ? --p->m.width : false;
	}
	return (arg);
}

long double	f_modified_percision(t_printf *p, long double arg)
{
	if (p->m.percision && p->m.percision < p->m.width)
		p->m.width -= p->m.percision;
	if (!p->m.minus)
		while (p->m.width && ((p->m.width--) - (intmax_t)p->m.len) > 0)
			check_buff(p, p->m.symbol);
	if (p->m.percision)
		arg = f_minus_plus_case(p, arg);
	return (arg);
}

long double	f_default_percision(t_printf *p, long double arg)
{
	arg = f_minus_plus_case(p, arg);
	p->m.space == true ? check_buff(p, ' ') : false;
	p->m.width = 0;
	while (p->m.percision && (p->m.percision--) - p->m.len)
		check_buff(p, '0');
	p->m.percision ? p->m.percision = 0 : false;
	return (arg);
}

long double	f_pers_width(t_printf *p, long double arg)
{
	if (p->m.width && (p->m.plus || arg < 0))
		--p->m.width;
	if (p->m.width && p->m.zero)
		arg = f_minus_plus_case(p, arg);
	if (p->m.width && (p->m.percision >= p->m.width))
		arg = f_default_percision(p, arg);
	arg = f_modified_percision(p, arg);
	if (p->m.width && !p->m.zero && !p->m.percision)
		arg = f_minus_plus_case(p, arg);
	return (arg);
}

void		process_f(t_printf *p, va_list ap)
{
	char					*out;
	long double				arg;

	arg = check_type_double(p, ap);
	arg < 0 ? p->m.plus = false : false;
	arg < 0 ? p->m.space = false : false;
	p->m.len = count_f(arg, p);
	p->m.len >= (uintmax_t)p->m.width ? p->m.width = 0 : 0;
	if (p->m.width && (!p->m.zero) && (!p->m.minus) && (!p->m.percision))
		p->m.space = false;
	p->m.zero == true ? p->m.symbol = '0' : false;
	p->m.zero == false ? p->m.symbol = ' ' : true;
	arg = f_pers_width(p, arg);
	out = ft_fitoa(arg);
	p->m.outlen = ft_strlen(out);
	(int)arg == 0 && p->m.tmp && !p->m.dsave ? p->m.outlen = false : true;
	(int)arg == 0 && p->m.tmp && !p->m.dsave ? check_buff(p, '0') : false;
	if (p->m.outlen)
		output_f(p, out);
	free(out);
	if (p->m.minus)
		while (p->m.width && (p->m.width--) - (intmax_t)p->m.len)
			check_buff(p, p->m.symbol);
	ft_bzero(&(p->m), sizeof(t_flag_printf));
}
