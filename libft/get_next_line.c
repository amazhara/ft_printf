/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazhara <amazhara@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 11:49:58 by amazhara          #+#    #+#             */
/*   Updated: 2019/01/16 15:27:24 by amazhara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_chain	*lst_make(t_chain **sp, int fd)
{
	t_chain		*first;
	t_chain		*send;

	if (!*sp)
		(*sp = (t_chain *)ft_memalloc(sizeof(t_chain)))
			&& ((*sp)->fd = fd);
	first = *sp;
	while (sp)
	{
		if ((*sp)->fd == fd)
			break ;
		if ((*sp)->next == NULL)
		{
			(*sp)->next = (t_chain *)ft_memalloc(sizeof(t_chain));
			(*sp) = (*sp)->next;
			(*sp)->fd = fd;
			break ;
		}
		*sp = (*sp)->next;
	}
	send = (*sp);
	(*sp) = first;
	return (send);
}

int		n_circle(t_chain *cur)
{
	char			*buff;
	char			*tmp;
	int				red;

	if (ft_strchr(cur->save, '\n'))
		return (1);
	buff = malloc(sizeof(char) * (BUFF_SIZE + 1));
	while ((red = read(cur->fd, buff, BUFF_SIZE)) > 0)
	{
		buff[red] = '\0';
		if (!cur->save)
			(cur->save) = ft_strnew(1);
		tmp = cur->save;
		cur->save = ft_strjoin(cur->save, buff);
		free(tmp);
		if (ft_strchr(buff, '\n'))
			break ;
	}
	free(buff);
	if (red < 0)
		return (-1);
	if (red == 0 && (cur->save == NULL || cur->save[0] == '\0'))
		return (0);
	return (1);
}

int		get_next_line(const int fd, char **line)
{
	static t_chain	*sp;
	t_chain			*cur;
	int				r;
	char			*ll;
	char			*tmp;

	if (fd < 0 || BUFF_SIZE < 1)
		return (-1);
	cur = lst_make(&sp, fd);
	if ((r = n_circle(cur)) == -1 || r == 0)
		return (r);
	if ((ll = ft_strchr(cur->save, '\n')))
	{
		*line = ft_strsub(cur->save, 0, ll - (cur->save));
		tmp = cur->save;
		cur->save = ft_strdup(ll + 1);
		free(tmp);
	}
	else
	{
		*line = ft_strdup(cur->save);
		ft_strdel(&cur->save);
	}
	return (1);
}
