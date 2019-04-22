/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazhara <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 18:29:45 by amazhara          #+#    #+#             */
/*   Updated: 2018/11/01 12:36:26 by amazhara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	*ft_memccpy(void *restrict dst, const void *restrict src, int c,
		size_t n)
{
	char	*s1;
	char	*s2;
	size_t	i;

	i = 0;
	s1 = (char *)dst;
	s2 = (char *)src;
	while (n > 0 && s2[i] != (char)c)
	{
		n--;
		s1[i] = s2[i];
		i++;
	}
	if (n > 0)
	{
		s1[i] = s2[i];
		i++;
		return ((void *)&s1[i]);
	}
	else
		return (NULL);
}
