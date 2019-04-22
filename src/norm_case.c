/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norm_case.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazhara <amazhara@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/23 13:54:54 by amazhara          #+#    #+#             */
/*   Updated: 2018/12/23 14:50:02 by amazhara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		p_precision(t_printf *p, int i, const char *str, va_list *ap)
{
	p->m.tmp = true;
	p->m.zero = false;
	if (str[++i] == '*')
		i = presicion_star(p, *ap, i);
	else
	{
		p->m.percision = ft_atoi(&str[i]);
		while (str[i] && (ft_isdigit(str[i])))
			++i;
	}
	return (i);
}

int		case_l_j_z(t_printf *p, const char *str, int i)
{
	if (str[i] == 'L')
	{
		p->m.lol = true;
		return (++i);
	}
	if (str[i] == 'z')
	{
		p->m.z = true;
		return (++i);
	}
	if (str[i] == 'j')
	{
		p->m.j = true;
		return (++i);
	}
	return (i);
}
