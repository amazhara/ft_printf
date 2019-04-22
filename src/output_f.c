/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_f.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazhara <amazhara@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 16:14:58 by amazhara          #+#    #+#             */
/*   Updated: 2018/12/23 14:49:49 by amazhara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	output_f(t_printf *p, char *out)
{
	while (p->m.outlen--)
		check_buff(p, out[p->m.iter++]);
	while (p->m.percision && (p->m.percision--))
		check_buff(p, '0');
}
