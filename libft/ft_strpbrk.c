/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strpbrk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazhara <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/04 15:38:42 by amazhara          #+#    #+#             */
/*   Updated: 2018/11/04 16:10:11 by amazhara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strpbrk(const char *s, const char *ch)
{
	int	i;
	int j;

	i = 0;
	if (!s || !ch)
		return (NULL);
	while (s[i])
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
