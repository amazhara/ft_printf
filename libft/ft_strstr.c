/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazhara <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 20:51:22 by amazhara          #+#    #+#             */
/*   Updated: 2018/10/29 22:57:27 by amazhara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_result(const char *s1, const char *s2, int i, int c)
{
	int y;
	int h;
	int u;

	h = 1;
	u = 0;
	while ((s1[i] != s2[c] && s1[i] && s2[c]) || h == 1)
	{
		h = 0;
		if (s1[0] != s2[0] || u++ >= 1)
			i++;
		if (s1[i] == s2[c])
		{
			y = i;
			while (s1[i++] == s2[c++])
				if (s2[c] == '\0')
					return ((char *)&s1[y]);
			h = 1;
			c = 0;
			i = y;
		}
	}
	return (NULL);
}

char		*ft_strstr(const char *s1, const char *s2)
{
	int		i;
	int		c;
	char	*g;

	i = 0;
	c = 0;
	if (s2[0] == '\0')
		return ((char *)s1);
	g = ft_result(s1, s2, i, c);
	if (g != NULL)
		return (g);
	return (NULL);
}
