/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_u_x.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazhara <amazhara@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/16 16:02:22 by amazhara          #+#    #+#             */
/*   Updated: 2018/12/23 14:40:05 by amazhara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

uintmax_t	u_case(t_printf *p, uintmax_t arg)
{
	if (p->m.space && (p->m.width > p->m.percision))
	{
		check_buff(p, ' ');
		p->m.width ? --p->m.width : false;
	}
	if (p->m.space && !p->m.width && !p->m.percision)
	{
		check_buff(p, ' ');
		p->m.width ? --p->m.width : false;
	}
	return (arg);
}

uintmax_t	u_modified_percision(t_printf *p, uintmax_t arg)
{
	if (p->m.percision && p->m.percision < p->m.width)
		p->m.width -= (p->m.percision - p->m.len);
	if (p->m.hash)
	{
		if (p->m.ch == 3)
			p->m.width >= 1 && arg != 0 ? --p->m.width : true;
		else
		{
			if (p->m.width == 2 || p->m.width == 1)
				p->m.width = 0;
			if (p->m.width > 2)
				p->m.width -= 2;
		}
	}
	if (p->m.zero && p->m.ch)
		output_buf_per_x(p);
	if (!p->m.minus)
		output_buf_x(p);
	if (p->m.percision)
		arg = u_case(p, arg);
	if (p->m.percision && p->m.percision - p->m.len && p->m.ch)
		output_buf_per_x(p);
	while (p->m.percision && (p->m.percision--) - p->m.len)
		check_buff(p, '0');
	return (arg);
}

uintmax_t	u_default_percision(t_printf *p, uintmax_t arg)
{
	arg = u_case(p, arg);
	p->m.space == true ? check_buff(p, ' ') : false;
	p->m.width = 0;
	if (p->m.percision && p->m.percision - p->m.len && p->m.ch)
		output_buf_per_x(p);
	while (p->m.percision && (p->m.percision--) - p->m.len)
		check_buff(p, '0');
	p->m.percision ? p->m.percision = 0 : false;
	return (arg);
}

uintmax_t	u_pers_width(t_printf *p, uintmax_t arg)
{
	p->m.len > (uintmax_t)p->m.percision ? p->m.percision = 0 : false;
	if (p->m.width && p->m.zero)
		arg = u_case(p, arg);
	if (p->m.width && (p->m.percision >= p->m.width))
		arg = u_default_percision(p, arg);
	arg = u_modified_percision(p, arg);
	if (p->m.width && !p->m.zero && !p->m.percision)
		arg = u_case(p, arg);
	return (arg);
}

void		process_u_x(t_printf *p, va_list ap)
{
	char					*out;
	uintmax_t				arg;

	arg = check_type_unsigned(p, ap);
	arg == 0 && (p->m.base != 8 || !p->m.tmp) ? p->m.hash = 0 : false;
	arg == 0 && (p->m.base != 8 || !p->m.tmp) ? p->m.ch = 0 : false;
	p->m.len = ft_base_len(arg, p->m.base);
	p->m.len >= (uintmax_t)p->m.width ? p->m.width = 0 : false;
	if (p->m.width && (!p->m.zero) && (!p->m.minus) && (!p->m.percision))
		p->m.space = false;
	!p->m.percision && !p->m.width ? arg = u_case(p, arg) : true;
	p->m.zero == true ? p->m.symbol = '0' : true;
	p->m.zero == false ? p->m.symbol = ' ' : false;
	arg = u_pers_width(p, arg);
	out = ft_itoa_base(arg, p->m.base, p->m.ch_size);
	p->m.outlen = ft_strlen(out);
	arg == 0 && p->m.tmp && !p->m.dsave ? --p->m.outlen : false;
	if (arg == 0 && p->m.tmp && !p->m.dsave && p->m.wtmp && !p->m.hash)
		check_buff(p, p->m.symbol);
	p->m.hash && p->m.minus ? output_buf_per_x(p) : false;
	while (p->m.outlen--)
		check_buff(p, out[p->m.iter++]);
	free(out);
	p->m.minus ? output_buf_x(p) : true;
	ft_bzero(&(p->m), sizeof(t_flag_printf));
}
