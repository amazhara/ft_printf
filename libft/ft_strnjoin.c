/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazhara <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 11:47:26 by amazhara          #+#    #+#             */
/*   Updated: 2019/04/19 11:47:29 by amazhara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnjoin(char const *s1, char const *s2, char const *s3)
{
	char	*tmp;

	tmp = NULL;
	if (s1)
		tmp = (char*)s1;
	if (!(s1 = ft_strjoin(s1, s2)))
		return (NULL);
	if (tmp)
		free(tmp);
	if (s1)
		tmp = (char*)s1;
	if (!(s1 = ft_strjoin(s1, s3)))
		return (NULL);
	if (tmp)
		free(tmp);
	return ((char *)s1);
}
