/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazhara <amazhara@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 13:39:23 by amazhara          #+#    #+#             */
/*   Updated: 2018/12/23 14:43:22 by amazhara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	process_p(t_printf *p, va_list ap)
{
	uintmax_t	arg;
	uintmax_t	c;
	char		*out;

	arg = va_arg(ap, unsigned long int);
	out = ft_itoa_base(arg, 16, 0);
	p->m.outlen = ft_strlen(out);
	p->m.width >= 2 ? p->m.width -= 2 : true;
	if (!p->m.minus)
		while (p->m.width && (p->m.width--) - p->m.outlen)
			check_buff(p, ' ');
	p->m.minus == true ? c = p->m.outlen : false;
	check_buff(p, '0');
	check_buff(p, 'x');
	arg == 0 && p->m.tmp && !p->m.dsave ? p->m.outlen = 0 : false;
	while (p->m.outlen--)
		check_buff(p, out[p->m.iter++]);
	free(out);
	if (p->m.minus)
		while (p->m.width && (p->m.width--) - c)
			check_buff(p, ' ');
	ft_bzero(&(p->m), sizeof(t_flag_printf));
}
