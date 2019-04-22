/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazhara <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/28 21:37:46 by amazhara          #+#    #+#             */
/*   Updated: 2018/10/29 17:49:09 by amazhara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_count(char const *str, char c)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		while (str[i] == c && str[i])
			i++;
		if (!str[i])
			break ;
		while (str[i] != c && str[i])
			i++;
		count++;
	}
	return (count);
}

static char		*ft_array(char const *str, char c, int *j, int g)
{
	char	*r;
	int		count;
	int		a;
	int		l;

	a = -1;
	count = 0;
	while (str[*j] == c && str[*j])
		(*j)++;
	g = (*j);
	while (str[*j] != c && str[*j])
	{
		(*j)++;
		count++;
	}
	l = (*j);
	if (!(r = (char *)malloc(sizeof(char) * (count + 1))))
		return (NULL);
	while (g < l)
	{
		r[++a] = str[g];
		g++;
	}
	r[++a] = '\0';
	return (r);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**str;
	int		len;
	int		i;
	int		j;
	int		g;

	if (!s)
		return (NULL);
	i = -1;
	j = 0;
	g = 0;
	len = ft_count(s, c);
	if (!(str = (char **)malloc(sizeof(char *) * (len + 1))))
		return (NULL);
	while (len-- > 0)
		str[++i] = ft_array(s, c, &j, g);
	str[++i] = 0;
	return (str);
}
