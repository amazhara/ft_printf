/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_double_free.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazhara <amazhara@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/28 16:08:48 by amazhara          #+#    #+#             */
/*   Updated: 2018/12/28 16:09:04 by amazhara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_double_free(char **arr, int len)
{
	int		i;

	i = len;
	if (len == 0)
		while (arr[i])
			free(arr[i++]);
	else
		while (i != -1 && arr[i])
			free(arr[i--]);
	free(arr);
}
