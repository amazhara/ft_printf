/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazhara <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 23:13:23 by amazhara          #+#    #+#             */
/*   Updated: 2018/11/02 14:29:56 by amazhara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	end(char *s, size_t l)
{
	size_t	i;
	size_t	j;
	size_t	y;

	y = ft_strlen(s);
	i = 0;
	j = 0;
	while (s[i])
		i++;
	if ((s[i - 1] == ' ' || s[i - 1] == '\n' || s[i - 1] == '\t') && i == y)
		while (s[i - 1] == ' ' || s[i - 1] == '\n' || s[i - 1] == '\t')
		{
			i--;
			++j;
		}
	l = y - j;
	return (l);
}

static char		*start(const char *s)
{
	size_t	i;
	int		f;

	i = 0;
	f = 0;
	while (f == 0)
	{
		f = 1;
		if ((s[0] == ' ' || s[0] == '\n' || s[0] == '\t') && i == 0)
			while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
				i++;
	}
	return ((char *)&s[i]);
}

char			*ft_strtrim(char const *s)
{
	char	*s2;
	char	*buff;
	size_t	l;
	int		i;

	i = 0;
	l = 0;
	if (!s)
		return (NULL);
	while ((s[i] == ' ' || s[i] == '\n' || s[i] == '\t'))
	{
		i++;
		if ((size_t)i == ft_strlen(s))
		{
			s2 = ft_strsub(s, 0, 0);
			return (s2);
		}
	}
	buff = start(s);
	l = end(buff, l);
	s2 = ft_strsub(buff, 0, l);
	return (s2);
}
