/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazhara <amazhara@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 17:53:10 by amazhara          #+#    #+#             */
/*   Updated: 2018/12/23 14:48:52 by amazhara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char			*ft_itoa_malloc(intmax_t c, intmax_t m, intmax_t count)
{
	char	*str;
	char	*tmp;
	char	*tmp1;

	if (count == 1)
	{
		str = "-";
		tmp = ft_itoa(m);
		str = ft_strjoin(str, tmp);
		free(tmp);
	}
	else
		str = ft_itoa(m);
	tmp = str;
	str = ft_strjoin(str, ".");
	free(tmp);
	tmp = str;
	tmp1 = ft_itoa(c);
	str = ft_strjoin(str, tmp1);
	free(tmp);
	free(tmp1);
	return (str);
}

intmax_t		count_tail(long double arg)
{
	double		tmp;
	intmax_t	t;
	intmax_t	r;
	intmax_t	c;
	intmax_t	k;

	c = 10;
	while ((tmp = arg * c) && ((tmp - (intmax_t)tmp) != (double)0))
		c *= 10;
	t = (intmax_t)tmp;
	r = ft_intlen((intmax_t)arg);
	k = ft_intlen(t) - 1;
	c = 10;
	while (k && --k)
		c *= 10;
	while (r-- && (t %= c))
		c /= 10;
	return (t);
}

char			*ft_fitoa(long double arg)
{
	intmax_t		c;
	intmax_t		m;
	intmax_t		count;

	count = 0;
	if (arg < 0)
		++count ? arg *= -1 : false;
	c = count_tail(arg);
	m = (intmax_t)arg;
	return (ft_itoa_malloc(c, m, count));
}

uintmax_t		count_f(long double arg, t_printf *p)
{
	intmax_t	c;
	intmax_t	m;
	intmax_t	count;

	count = 1;
	if (arg < 0)
		++count ? arg *= -1 : false;
	c = count_tail(arg);
	m = (intmax_t)arg;
	if (p->m.percision <= ft_intlen(c))
		p->m.percision = 0;
	else
		p->m.percision -= ft_intlen(c);
	count += ft_intlen(c) + ft_intlen(m);
	return ((uintmax_t)count);
}
