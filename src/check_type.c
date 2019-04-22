/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_type.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazhara <amazhara@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/23 14:53:13 by amazhara          #+#    #+#             */
/*   Updated: 2018/12/23 14:54:09 by amazhara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

intmax_t	check_type_signed(t_printf *p, va_list ap)
{
	if (p->m.l)
		return (va_arg(ap, long int));
	if (p->m.ll || p->m.z)
		return (va_arg(ap, long long int));
	if (p->m.j)
		return (va_arg(ap, intmax_t));
	if (p->m.h)
		return ((short int)va_arg(ap, int));
	if (p->m.hh)
		return ((signed char)va_arg(ap, int));
	return (va_arg(ap, int));
}

uintmax_t	check_type_unsigned(t_printf *p, va_list ap)
{
	if (p->m.l)
		return (va_arg(ap, unsigned long int));
	if (p->m.ll)
		return (va_arg(ap, unsigned long long int));
	if (p->m.z)
		return (va_arg(ap, size_t));
	if (p->m.j)
		return (va_arg(ap, uintmax_t));
	if (p->m.h)
		return ((unsigned short int)va_arg(ap, int));
	if (p->m.hh)
		return ((unsigned char)va_arg(ap, int));
	return (va_arg(ap, unsigned int));
}

long double	check_type_double(t_printf *p, va_list ap)
{
	if (p->m.lol)
		return (va_arg(ap, long double));
	return (va_arg(ap, double));
}
