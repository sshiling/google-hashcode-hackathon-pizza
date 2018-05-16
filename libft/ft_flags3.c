/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noprysk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 11:41:41 by noprysk           #+#    #+#             */
/*   Updated: 2018/01/19 11:41:43 by noprysk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

static void			ft_nb_help_help(char *new, int width, t_print *node)
{
	if (g_on[SHARP].state == ON && g_on[MINUS].state == OFF\
		&& g_on[ZERO].state == ON\
			&& (g_on[S_X].state == ON || g_on[B_X].state == ON))
	{
		new[width - node->len + 1] = '0';
		new[1] = g_on[S_X].state == ON ? 'x' : 'X';
	}
	if (g_on[PLUS].state == ON && g_on[ZERO].state == ON\
		&& new[width - node->len] == '+')
	{
		new[width - node->len] = '0';
		new[0] = '+';
	}
}

static void			ft_nb_help(char *new, int width, t_print *node)
{
	int				len;

	ft_nb_help_help(new, width, node);
	if (g_on[ZERO].state == ON && new[width - node->len] == '-' &&\
		(g_on[I].state == ON || D))
	{
		new[width - node->len] = '0';
		new[0] = '-';
	}
	if (g_on[ZERO].state == ON && g_on[SPACE].state == ON &&\
			(g_on[I].state == ON || D) && ft_strchr(new, ' '))
	{
		new[0] = ' ';
		len = 1;
		while (new[len] != ' ')
			len++;
		new[len] = '0';
	}
}

void				ft_nb(t_print *node)
{
	int				width;
	char			*new;

	width = g_nb;
	if (node->len < width)
	{
		CHECK(new = ft_strnew(width));
		if (g_on[MINUS].state == ON)
		{
			ft_memset(new, ' ', width);
			ft_strncpy(new, node->str, node->len);
		}
		else
		{
			ft_memset(new, g_on[ZERO].state == ON ?\
				'0' : ' ', width - node->len);
			ft_strcpy(&new[width - node->len], node->str);
		}
		ft_strdel(&node->str);
		ft_nb_help(new, width, node);
		node->str = new;
		node->len = width;
	}
}
