/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazhara <amazhara@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 17:19:58 by amazhara          #+#    #+#             */
/*   Updated: 2018/12/26 17:58:25 by amazhara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				ft_bzero(void *s, size_t n)
{
	t_bzero_padd	*t_bzero_padd_s;
	unsigned char	*uchar_s;
	size_t			i;

	t_bzero_padd_s = (t_bzero_padd *)s;
	uchar_s = (unsigned char *)s;
	i = n - (n % sizeof(t_bzero_padd));
	while (i < n)
		uchar_s[i++] = 0;
	n /= sizeof(t_bzero_padd);
	while (n)
		t_bzero_padd_s[--n] = 0;
}
