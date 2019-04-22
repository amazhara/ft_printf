/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_pc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazhara <amazhara@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/23 14:43:46 by amazhara          #+#    #+#             */
/*   Updated: 2018/12/23 14:43:46 by amazhara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	process_pc(t_printf *p)
{
	if (p->m.zero)
		p->m.symbol = '0';
	else
		p->m.symbol = ' ';
	if (p->m.width && !p->m.minus)
		while ((p->m.width--) - 1)
			check_buff(p, p->m.symbol);
	check_buff(p, '%');
	if (p->m.width && p->m.minus)
		while ((p->m.width--) - 1)
			check_buff(p, p->m.symbol);
}
