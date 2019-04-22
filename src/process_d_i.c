/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_d_i.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazhara <amazhara@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 14:16:41 by amazhara          #+#    #+#             */
/*   Updated: 2018/12/23 14:36:34 by amazhara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

intmax_t	d_minus_plus_case(t_printf *p, intmax_t arg)
{
	if (arg < 0 && (arg + 1) * (-1) != 9223372036854775807)
	{
		check_buff(p, '-');
		arg < 0 ? arg *= -1 : false;
	}
	if (p->m.plus)
		check_buff(p, '+');
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

intmax_t	d_modified_percision(t_printf *p, intmax_t arg)
{
	if (p->m.percision && p->m.percision < p->m.width)
		p->m.width -= (p->m.percision - ft_intlen(arg));
	if (!p->m.minus)
		while (p->m.width && (p->m.width--) - ft_intlen(arg))
			check_buff(p, p->m.symbol);
	if (p->m.percision)
		arg = d_minus_plus_case(p, arg);
	while (p->m.percision && (p->m.percision--) - ft_intlen(arg))
		check_buff(p, '0');
	return (arg);
}

intmax_t	d_default_percision(t_printf *p, intmax_t arg)
{
	arg = d_minus_plus_case(p, arg);
	p->m.space == true ? check_buff(p, ' ') : false;
	p->m.width = 0;
	while (p->m.percision && (p->m.percision--) - ft_intlen(arg))
		check_buff(p, '0');
	p->m.percision ? p->m.percision = 0 : false;
	return (arg);
}

intmax_t	d_pers_width(t_printf *p, intmax_t arg)
{
	if (p->m.width && (p->m.plus || arg < 0))
		--p->m.width;
	ft_intlen(arg) > p->m.percision ? p->m.percision = 0 : false;
	if (p->m.width && p->m.zero)
		arg = d_minus_plus_case(p, arg);
	if (p->m.width && (p->m.percision >= p->m.width))
		arg = d_default_percision(p, arg);
	arg = d_modified_percision(p, arg);
	if (p->m.width && !p->m.zero && !p->m.percision)
		arg = d_minus_plus_case(p, arg);
	return (arg);
}

void		process_d_i(t_printf *p, va_list ap)
{
	char					*out;
	intmax_t				arg;

	arg = check_type_signed(p, ap);
	arg < 0 ? p->m.plus = false : false;
	arg < 0 ? p->m.space = false : false;
	ft_intlen(arg) >= p->m.width ? p->m.width = 0 : false;
	if (p->m.width && (!p->m.zero) && (!p->m.minus) && (!p->m.percision))
		p->m.space = false;
	!p->m.percision && !p->m.width ? arg = d_minus_plus_case(p, arg) : false;
	p->m.zero == true ? p->m.symbol = '0' : true;
	p->m.zero == false ? p->m.symbol = ' ' : false;
	arg = d_pers_width(p, arg);
	out = ft_itoa(arg);
	p->m.outlen = ft_strlen(out);
	arg == 0 && p->m.tmp && !p->m.dsave ? --p->m.outlen : false;
	if (arg == 0 && p->m.tmp && !p->m.dsave && p->m.wtmp)
		check_buff(p, p->m.symbol);
	while (p->m.outlen--)
		check_buff(p, out[p->m.iter++]);
	free(out);
	if (p->m.minus)
		while (p->m.width && (p->m.width--) - ft_intlen(arg))
			check_buff(p, p->m.symbol);
	ft_bzero(&(p->m), sizeof(t_flag_printf));
}
