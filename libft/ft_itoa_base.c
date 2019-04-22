/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazhara <amazhara@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/15 15:25:36 by amazhara          #+#    #+#             */
/*   Updated: 2018/12/22 15:24:09 by amazhara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static uintmax_t	base_len(uintmax_t n, uintmax_t base)
{
	uintmax_t		count;

	count = 0;
	while ((n = n / base))
		++count;
	return (++count);
}

char				*ft_itoa_base(uintmax_t n, uintmax_t base, uintmax_t size)
{
	char			*out;
	uintmax_t		len;

	len = base_len(n, base);
	out = (char *)malloc(sizeof(char) * len + 1);
	out[len] = '\0';
	while (len--)
	{
		if (size == 1)
			out[len] = "0123456789ABCDEF"[n % base];
		else
			out[len] = "0123456789abcdef"[n % base];
		n /= base;
	}
	return (out);
}
