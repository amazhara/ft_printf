/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_and_process.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazhara <amazhara@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 14:16:47 by amazhara          #+#    #+#             */
/*   Updated: 2018/12/23 14:08:16 by amazhara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		process_printf_type(const char *str, t_printf *p, va_list *ap, int i)
{
	char c;

	c = str[i];
	str[i] == 'U' ? p->m.l = true : false;
	str[i] == 'F' ? p->m.l = true : false;
	str[i] == 'D' ? p->m.l = true : false;
	if (str[i] != 'X')
		c = ft_tolower(c);
	if (c == 'd' || c == 'i')
		process_d_i(p, *ap);
	if (c == 'u' || c == 'x' || c == 'X' || c == 'o')
		pars_u_x(p, c, ap);
	if (c == 'f')
		p->m.percision == false ? p->m.percision = 6 : false;
	c == 'f' ? process_f(p, *ap) : false;
	if (c == 's')
		process_s(p, *ap);
	if (c == 'p')
		process_p(p, *ap);
	if (c == 'c')
		process_c(p, *ap);
	if (c == '%')
		process_pc(p);
	return (++i);
}

int		check_l_h(const char *str, t_printf *p, int i)
{
	if (str[i] == 'l' && str[i + 1] != 'l')
	{
		p->m.l = true;
		return (++i);
	}
	if (str[i] == 'l' && str[i + 1] == 'l')
	{
		p->m.ll = true;
		return (i += 2);
	}
	if (str[i] == 'h' && str[i + 1] != 'h')
	{
		p->m.h = true;
		return (++i);
	}
	if (str[i] == 'h' && str[i + 1] == 'h')
	{
		p->m.hh = true;
		return (i += 2);
	}
	return (case_l_j_z(p, str, i));
}

int		check_w_p(const char *str, t_printf *p, int i, va_list *ap)
{
	if (ft_isdigit(str[i]) || str[i] == '*')
	{
		if (str[i] == '*')
			i = width_star(p, *ap, i);
		else
		{
			p->m.width = ft_atoi(&str[i]);
			while (str[i] && (ft_isdigit(str[i])))
				++i;
		}
	}
	if (str[i] == '.')
		i = p_precision(p, i, str, ap);
	p->m.width == false ? p->m.zero = false : false;
	p->m.dsave = p->m.percision;
	p->m.width ? p->m.wtmp = true : false;
	return (i);
}

int		check_flags(const char *str, t_printf *p, int c)
{
	int		i;

	i = c;
	while (str[++i] == ' ' || str[i] == '#' ||
	str[i] == '-' || str[i] == '+' || str[i] == '0')
	{
		str[i] == ' ' ? p->m.space = true : false;
		str[i] == '#' ? p->m.hash = true : false;
		str[i] == '-' ? p->m.minus = true : false;
		str[i] == '+' ? p->m.plus = true : false;
		str[i] == '0' ? p->m.zero = true : false;
	}
	p->m.plus == true ? p->m.space = false : false;
	p->m.minus == true ? p->m.zero = false : false;
	return (i);
}

int		pars_and_process(const char *str, t_printf *p, va_list *ap, int c)
{
	int i;

	i = check_flags(str, p, c);
	i = check_w_p(str, p, i, ap);
	i = check_l_h(str, p, i);
	return (process_printf_type(str, p, ap, i));
}
