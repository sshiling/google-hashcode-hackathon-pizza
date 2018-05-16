/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noprysk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 18:29:10 by noprysk           #+#    #+#             */
/*   Updated: 2017/12/06 18:29:11 by noprysk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			ft_copy(char *dup, t_data *node)
{
	while (*node->p != '\0' && *node->p != '\n')
	{
		*dup = *node->p;
		node->p++;
		dup++;
	}
	return (*node->p == '\n' ? 2 : 3);
}

static int			ft_read(t_data *node, char **dup, int res, int len)
{
	int				n;
	char			*big;

	*dup = ft_strnew(BUFF_SIZE);
	res = ft_copy(*dup, node);
	len = ft_strlen(*dup);
	while (res == 3)
	{
		ft_bzero(node->buff, BUFF_SIZE);
		if ((n = read(node->fd, node->buff, BUFF_SIZE)) == 0 && len == 0)
			return (0);
		if (n == -1)
			return (-1);
		node->p = node->buff;
		if (*node->p == '\0')
			return (1);
		big = ft_strnew(ft_strlen(*dup) + BUFF_SIZE);
		ft_strcpy(big, *dup);
		ft_strdel(dup);
		res = ft_copy(&big[len], node);
		len += node->p - node->buff;
		*dup = big;
	}
	*node->p == '\n' ? node->p++ : node->p;
	return (1);
}

static void			ft_null(t_data *node, int fd)
{
	node->fd = fd;
	node->p = node->buff;
	ft_bzero(node->buff, BUFF_SIZE + 1);
	node->next = NULL;
}

static t_data		*ft_set(t_data **head, int fd)
{
	t_data			*node;
	t_data			*cursor;

	if (*head == NULL)
	{
		node = malloc(sizeof(t_data));
		ft_null(node, fd);
		*head = node;
		return (node);
	}
	cursor = *head;
	while (cursor != NULL && cursor->next != NULL && cursor->fd != fd)
		cursor = cursor->next;
	if (cursor->fd == fd)
		return (cursor);
	node = malloc(sizeof(t_data));
	cursor->next = node;
	ft_null(node, fd);
	return (node);
}

int					get_next_line(const int fd, char **line)
{
	static t_data	*head = NULL;
	t_data			*node;
	char			*dup;
	int				res;
	int				len;

	len = 0;
	res = 0;
	if (fd == -1 || line == NULL)
		return (-1);
	node = ft_set(&head, fd);
	res = ft_read(node, &dup, res, len);
	if (res == 1)
	{
		*line = dup;
		return (1);
	}
	ft_strdel(&dup);
	return (res == 0 ? 0 : -1);
}
