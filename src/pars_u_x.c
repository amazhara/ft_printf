/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_u_x.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazhara <amazhara@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/23 14:44:41 by amazhara          #+#    #+#             */
/*   Updated: 2018/12/23 14:47:36 by amazhara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	pars_u_x(t_printf *p, char c, va_list *ap)
{
	c == 'u' ? p->m.base = 10 : false;
	c == 'x' || c == 'X' ? p->m.base = 16 : false;
	c == 'X' ? p->m.ch_size = true : false;
	p->m.hash && c == 'x' ? p->m.ch = 1 : false;
	p->m.hash && c == 'X' ? p->m.ch = 2 : false;
	c == 'u' ? p->m.hash = false : true;
	p->m.space = false;
	c == 'o' ? p->m.base = 8 : false;
	c == 'o' && p->m.percision ? p->m.hash = false : true;
	c == 'o' && p->m.hash ? p->m.ch = 3 : false;
	process_u_x(p, *ap);
}
