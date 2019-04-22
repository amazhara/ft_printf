/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazhara <amazhara@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/23 14:48:10 by amazhara          #+#    #+#             */
/*   Updated: 2018/12/23 14:48:13 by amazhara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	process_c(t_printf *p, va_list ap)
{
	p->m.symbol = va_arg(ap, int);
	if (p->m.width && !p->m.minus)
		while ((p->m.width--) != 1)
			check_buff(p, ' ');
	check_buff(p, p->m.symbol);
	if (p->m.width && p->m.minus)
		while ((p->m.width--) != 1)
			check_buff(p, ' ');
	ft_bzero(&(p->m), sizeof(t_flag_printf));
}
