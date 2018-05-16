/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noprysk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 20:11:25 by noprysk           #+#    #+#             */
/*   Updated: 2018/01/18 20:11:27 by noprysk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

static void			ft_sharp_help_1(t_print *node, char *str, int i)
{
	if (i != 0)
		node->str[i - 1] = '0';
	else
	{
		if (node->str[0] == '0')
			return ;
		CHECK(str = ft_strnew(node->len + 1));
		str[0] = '0';
		ft_strcpy(&str[1], node->str);
		ft_strdel(&(node->str));
		node->str = str;
		node->len += 1;
	}
}

static void			ft_sharp_help_2(t_print *node, char *str)
{
	CHECK(str = ft_strnew(node->len + 2));
	str[0] = '0';
	str[1] = g_on[S_X].state == ON ? 'x' : 'X';
	ft_strcpy(&str[2], node->str);
	ft_strdel(&(node->str));
	node->str = str;
	node->len += 2;
}

void				ft_sharp(t_print *node)
{
	char			*str;
	int				i;

	i = 0;
	str = NULL;
	if (g_on[DOT].state == ON)
		while (node->str[i] == '0')
			i++;
	if (O)
		ft_sharp_help_1(node, str, i);
	else if (X)
	{
		if (g_on[P].state == ON || g_on[DOT].state == ON)
			i = 0;
		if (i >= 2)
		{
			node->str[0] = '0';
			node->str[1] = g_on[S_X].state == ON ? 'x' : 'X';
		}
		else
			ft_sharp_help_2(node, str);
	}
}

void				ft_space(t_print *node)
{
	char			*str;

	if (g_on[PLUS].state == ON)
		return ;
	if ((D || g_on[I].state == ON) && node->str[0] != '-')
	{
		CHECK(str = ft_strnew(node->len + 1));
		str[0] = ' ';
		ft_strcpy(&str[1], node->str);
		ft_strdel(&(node->str));
		node->str = str;
		node->len += 1;
	}
}
