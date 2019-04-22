/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_buf_x.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazhara <amazhara@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 16:19:54 by amazhara          #+#    #+#             */
/*   Updated: 2018/12/23 14:49:14 by amazhara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	output_buf_x(t_printf *p)
{
	if (!p->m.minus)
	{
		while (p->m.width && (p->m.width--) - p->m.len)
			check_buff(p, p->m.symbol);
		if ((!p->m.dsave || (uintmax_t)p->m.dsave <= p->m.len) && p->m.ch)
			output_buf_per_x(p);
	}
	if (p->m.minus)
		while (p->m.width && (p->m.width--) - p->m.len)
			check_buff(p, p->m.symbol);
}

void	output_buf_per_x(t_printf *p)
{
	if (p->m.ch)
		check_buff(p, '0');
	if (p->m.ch == 1)
		check_buff(p, 'x');
	if (p->m.ch == 2)
		check_buff(p, 'X');
	p->m.ch = 0;
}
