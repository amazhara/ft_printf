/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazhara <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 09:27:40 by amazhara          #+#    #+#             */
/*   Updated: 2018/10/31 09:50:43 by amazhara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	size_t	i;
	size_t	y;
	size_t	j;

	i = 0;
	if (s2[0] == '\0')
		return ((char *)s1);
	while (s1[i] && i < len)
	{
		j = 0;
		y = i;
		while (s1[i] == s2[j] && i < len && s1[i] != '\0')
		{
			i++;
			if (s2[++j] == '\0')
				return ((char *)&s1[y]);
		}
		i = y;
		i++;
	}
	return (NULL);
}
