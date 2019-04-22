/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_double_malloc.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazhara <amazhara@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/28 12:30:07 by amazhara          #+#    #+#             */
/*   Updated: 2018/12/29 20:14:04 by amazhara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_double_malloc(int y, int x)
{
	char	**mas;

	mas = (char **)malloc(sizeof(char *) * (y + 1));
	mas[y] = NULL;
	while (y--)
	{
		mas[y] = (char *)malloc(sizeof(char) * (x + 1));
		mas[y][x] = '\0';
	}
	return (mas);
}
