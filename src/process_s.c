/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazhara <amazhara@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 17:30:47 by amazhara          #+#    #+#             */
/*   Updated: 2018/12/23 14:42:56 by amazhara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	prinf_s_output(t_printf *p, char *out)
{
	while (p->m.outlen--)
		check_buff(p, out[p->m.iter++]);
}

void	s_percision_case(t_printf *p)
{
	if (p->m.percision < p->m.outlen)
		p->m.outlen = p->m.percision;
	if (p->m.width < p->m.percision)
		p->m.width = 0;
}

void	process_s(t_printf *p, va_list ap)
{
	char	*out;
	char	*err;
	int		tmp;

	err = "(null)";
	out = va_arg(ap, char*);
	p->m.outlen = 6;
	out ? p->m.outlen = ft_strlen(out) : false;
	if (p->m.percision)
		s_percision_case(p);
	tmp = p->m.outlen;
	if (!p->m.minus)
		while (p->m.width && (p->m.width--) - p->m.outlen)
			check_buff(p, ' ');
	if (!out)
	{
		while (p->m.outlen--)
			check_buff(p, err[p->m.iter++]);
	}
	else
		prinf_s_output(p, out);
	if (p->m.minus)
		while (p->m.width && (p->m.width--) - tmp)
			check_buff(p, ' ');
	ft_bzero(&(p->m), sizeof(t_flag_printf));
}
