/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_stars.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazhara <amazhara@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/23 14:48:27 by amazhara          #+#    #+#             */
/*   Updated: 2018/12/23 14:48:28 by amazhara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		width_star(t_printf *p, va_list ap, int i)
{
	p->m.width = va_arg(ap, intmax_t);
	return (++i);
}

int		presicion_star(t_printf *p, va_list ap, int i)
{
	p->m.percision = va_arg(ap, intmax_t);
	return (++i);
}
