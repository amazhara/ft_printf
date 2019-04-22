/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazhara <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 22:27:54 by amazhara          #+#    #+#             */
/*   Updated: 2018/11/01 23:02:24 by amazhara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	y;
	char	*str;

	i = 0;
	y = 0;
	if (!s)
		return (NULL);
	while (i < start)
		i++;
	if (!(str = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (y < len)
	{
		str[y] = s[i];
		y++;
		i++;
	}
	str[y] = '\0';
	return (str);
}
