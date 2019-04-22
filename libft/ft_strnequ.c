/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazhara <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 22:11:02 by amazhara          #+#    #+#             */
/*   Updated: 2018/11/01 22:23:48 by amazhara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strnequ(char const *s1, char const *s2, size_t n)
{
	size_t i;

	i = 0;
	if (n == 0)
		return (1);
	if (!s1 || !s2)
		return (0);
	if (s1[i] == '\0' && s2[i] == '\0')
		return (1);
	while (s1[i] && s2[i] && s1[i] == s2[i] && i < n)
	{
		if (s1[i] == s2[i] && (i + 1) == n)
			return (1);
		i++;
	}
	if (s1[i - 1] == s2[i - 1] && s1[i] == '\0' && s2[i] == '\0' && i < n)
		return (1);
	return (0);
}
