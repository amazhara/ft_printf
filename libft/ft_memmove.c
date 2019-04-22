/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazhara <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 14:38:10 by amazhara          #+#    #+#             */
/*   Updated: 2018/11/01 15:49:52 by amazhara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*s1;
	char	*s2;
	size_t	i;

	i = 0;
	s1 = (char *)dst;
	s2 = (char *)src;
	if (s1 <= s2)
		while (i < len)
		{
			s1[i] = s2[i];
			i++;
		}
	else
	{
		i = len;
		while (i-- > 0)
			s1[i] = s2[i];
	}
	return ((void *)s1);
}
