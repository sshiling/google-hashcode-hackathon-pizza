/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noprysk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 17:46:02 by noprysk           #+#    #+#             */
/*   Updated: 2017/12/18 17:46:05 by noprysk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int				g_fd = 1;

static void		ft_strset(const char *str, t_print **head, int beg, int len)
{
	t_print		*cursor;
	t_print		*node;

	CHECK(node = malloc(240));
	if (!(*head))
		*head = node;
	else
	{
		cursor = *head;
		while (cursor->next)
			cursor = cursor->next;
		cursor->next = node;
	}
	CHECK(node->str = ft_strsub(str, beg, len));
	node->len = len;
	node->next = NULL;
}

static int		ft_count_print_del(t_print *head)
{
	t_print		*cursor;
	int			count;

	cursor = head;
	count = 0;
	while (cursor)
	{
		count += cursor->len;
		write(g_fd, cursor->str, cursor->len);
		cursor = cursor->next;
		ft_strdel(&head->str);
		free(head);
		head = cursor;
	}
	return (count);
}

static int		ft_printf_help_help(char *color, t_print **head,\
					const char *str, int i)
{
	ft_strset(color, head, 0, ft_strlen(color));
	ft_strdel(&color);
	while (str[i] != '}')
		i++;
	return (i);
}

static int		ft_printf_help(const char *str, t_print **head, int beg, int i)
{
	char		*color;

	if (str[i - 1] == '{')
	{
		if (ft_strncmp(&str[i], "fd}", 3) == 0)
		{
			g_fd = va_arg(g_lst, int);
			return (i + 2);
		}
		else if ((color = ft_format(&str[i])) != NULL)
			return (ft_printf_help_help(color, head, str, i));
		else
		{
			ft_strset(str, head, i - 1, 1);
			return (i - 1);
		}
	}
	beg = i;
	while (!(SPECIF(str[i])) &&\
		((FLAG(str[i])) || MODIF(str[i]) || DIGIT(str[i])))
		i++;
	ft_magic(str, head, beg, i);
	return (i);
}

int				ft_printf(const char *str, ...)
{
	int			i;
	int			beg;
	t_print		*head;

	i = 0;
	head = NULL;
	va_start(g_lst, str);
	while (1)
	{
		beg = i;
		while (str[i] != '%' && str[i] != '{' && str[i])
			i++;
		if (beg != i)
			ft_strset(str, &head, beg, i - beg);
		if (str[i++] == '\0')
			break ;
		if (str[i] == '%' && str[i - 1] != '{')
			ft_strset(str, &head, i, 1);
		else
			i = ft_printf_help(str, &head, beg, i);
		if (str[i])
			i++;
	}
	return (ft_count_print_del(head));
}
