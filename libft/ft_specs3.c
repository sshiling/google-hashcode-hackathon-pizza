/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_specs5.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noprysk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 18:16:24 by noprysk           #+#    #+#             */
/*   Updated: 2018/01/25 18:16:26 by noprysk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void				ft_n(t_print *head)
{
	t_print			*cursor;
	int				*nb;

	if (!(nb = va_arg(g_lst, int*)))
		return ;
	cursor = head;
	*nb = 0;
	while (cursor)
	{
		*nb += cursor->len;
		cursor = cursor->next;
	}
}

static int			ft_len(int nb)
{
	int				len;

	len = 0;
	while (nb)
	{
		nb /= 2;
		len++;
	}
	return (len);
}

void				ft_b(t_print *node)
{
	int				nb;
	int				len;

	nb = va_arg(g_lst, int);
	if (nb < 0)
	{
		CHECK(node->str = ft_strnew(0));
		return ;
	}
	if (nb == 0)
	{
		CHECK(node->str = ft_strdup("0"));
		node->len = 1;
		return ;
	}
	len = ft_len(nb);
	node->len = len;
	CHECK(node->str = ft_strnew(len));
	while (len)
	{
		node->str[len-- - 1] = nb % 2 + '0';
		nb /= 2;
	}
}
