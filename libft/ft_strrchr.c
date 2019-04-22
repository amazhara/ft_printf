/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazhara <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 18:27:40 by amazhara          #+#    #+#             */
/*   Updated: 2018/10/29 20:41:03 by amazhara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;
	int	f;

	i = 0;
	while (s[i] != '\0')
		i++;
	f = i;
	while (s[--i] != c && f > 0)
		f--;
	if (i < 0 && c != '\0')
		return (NULL);
	if (s[i] == c && c != '\0')
		return ((char *)&s[i]);
	if (c == '\0')
		return ((char *)&s[ft_strlen(s)]);
	else
		return (NULL);
}
