/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnpbrk.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazhara <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/04 16:05:32 by amazhara          #+#    #+#             */
/*   Updated: 2018/11/04 16:10:21 by amazhara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnpbrk(const char *s, const char *ch, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!s || !ch)
		return (NULL);
	while (s[i] && i < len)
	{
		j = 0;
		while (s[i] != ch[j] && ch[j])
		{
			if (s[i] == ch[j])
				return ((char *)&s[i]);
			j++;
		}
		i++;
	}
	return (NULL);
}
