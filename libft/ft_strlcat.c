/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazhara <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/27 20:20:48 by amazhara          #+#    #+#             */
/*   Updated: 2018/10/28 17:34:25 by amazhara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *restrict dst, const char *restrict src,
		size_t dstsize)
{
	size_t i;
	size_t y;
	size_t l;

	l = dstsize;
	i = 0;
	while (dst[i] && i < l)
		i++;
	y = i;
	while (src[i - y] && y + 1 < l)
	{
		dst[i] = src[i - y];
		i++;
		l--;
	}
	if (i < dstsize)
		dst[i] = '\0';
	return (ft_strlen(src) + y);
}
