/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazhara <amazhara@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 11:01:52 by amazhara          #+#    #+#             */
/*   Updated: 2018/12/14 19:20:57 by amazhara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static intmax_t	get_str_len(intmax_t n)
{
	intmax_t		i;
	intmax_t		k;

	k = 0;
	if (n < 0)
		k = 1;
	i = 1;
	while (n /= 10)
		i++;
	return (i + k);
}

char			*ft_itoa(intmax_t n)
{
	char			*str;
	intmax_t		str_len;
	uintmax_t		num;

	str_len = get_str_len(n);
	num = n;
	if (n < 0)
		num = n * -1;
	if (!(str = (char *)malloc(sizeof(char) * (str_len + 1))))
		return (NULL);
	str[str_len] = '\0';
	while (str_len--)
	{
		str[str_len] = num % 10 + 48;
		num /= 10;
	}
	if (n < 0)
		str[0] = '-';
	return (str);
}
