/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_base_len.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazhara <amazhara@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 15:54:04 by amazhara          #+#    #+#             */
/*   Updated: 2018/12/23 14:51:48 by amazhara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

uintmax_t	ft_base_len(uintmax_t n, uintmax_t base)
{
	uintmax_t		count;

	count = 0;
	while ((n = n / base))
		++count;
	return (++count);
}
