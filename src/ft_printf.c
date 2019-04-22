/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrazas <vbrazas@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 14:17:04 by amazhara          #+#    #+#             */
/*   Updated: 2018/12/26 16:54:35 by vbrazas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	check_buff(t_printf *p, char c)
{
	if (p->i + 1 == 4096)
	{
		write(1, p->buf, p->i);
		p->count += p->i;
		p->i = 0;
	}
	p->buf[p->i++] = c;
}

int		ft_printf(const char *str, ...)
{
	int					i;
	va_list				ap;
	static t_printf		p;
	static char			b[4096];

	i = 0;
	ft_bzero(&p, sizeof(t_printf));
	p.buf = b;
	va_start(ap, str);
	while (str[i])
	{
		if (str[i] == '%')
			i = pars_and_process(str, &p, &ap, i);
		else
			check_buff(&p, str[i++]);
	}
	va_end(ap);
	if (p.i > 0)
		write(1, p.buf, p.i);
	p.count += p.i;
	return (p.count);
}
