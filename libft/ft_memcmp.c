/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazhara <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 16:36:19 by amazhara          #+#    #+#             */
/*   Updated: 2018/11/01 17:06:20 by amazhara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;
	size_t			i;
	int				c;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	i = 0;
	c = 0;
	while (i < n)
	{
		if ((c = str1[i] - str2[i]) < 0)
			return (c);
		if ((str2[i] - str1[i]) < 0)
			return (c);
		i++;
	}
	return (0);
}
