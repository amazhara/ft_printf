/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazhara <amazhara@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/15 15:25:53 by amazhara          #+#    #+#             */
/*   Updated: 2018/12/15 15:39:32 by amazhara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

intmax_t		ft_intlen(intmax_t c)
{
	intmax_t	count;

	count = 0;
	while (c /= 10)
		count++;
	return (++count);
}
