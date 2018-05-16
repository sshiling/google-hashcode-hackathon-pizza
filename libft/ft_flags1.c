/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noprysk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/25 17:00:37 by noprysk           #+#    #+#             */
/*   Updated: 2017/12/25 17:00:39 by noprysk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

static void			ft_dot_help_1(t_print *node, char *new, int prec, int minus)
{
	if (minus == 1)
	{
		new[0] = '-';
		new[prec - node->len] = '0';
	}
	node->str = new;
	node->len = prec;
}

static void			ft_dot_help_2(t_print *node)
{
	if (node->str[0] == '0' && node->str[1] == '\0'\
		&& (NUMBER || g_on[P].state == ON))
	{
		node->str[0] = '\0';
		node->len = 0;
	}
	if (node->str[0] != '\0' && g_on[PER].state == OFF\
			&& g_on[S_C].state == OFF)
		g_on[ZERO].state = OFF;
	if (NUMBER)
		g_on[ZERO].state = OFF;
}

void				ft_dot(t_print *node)
{
	int				prec;
	char			*new;
	int				minus;

	minus = 0;
	prec = g_dot;
	if ((g_on[S_S].state == ON || g_on[B_S].state == ON) && node->len > prec)
	{
		node->str[prec] = '\0';
		node->len = prec;
	}
	else if (NUMBER && node->len - (ft_strchr((const char *)node->str, '-')\
			? 1 : 0) < prec)
	{
		if (ft_strchr((const char *)node->str, '-'))
			minus = 1;
		prec = (minus == 1) ? prec + 1 : prec;
		CHECK(new = ft_strnew(prec));
		ft_memset(new, '0', prec);
		ft_strcpy(&new[prec - node->len], node->str);
		ft_strdel(&node->str);
		ft_dot_help_1(node, new, prec, minus);
	}
	ft_dot_help_2(node);
}

void				ft_plus(t_print *node)
{
	char			*str;

	if (node->str[0] != '-' && (D || g_on[I].state == ON))
	{
		CHECK(str = ft_strnew(node->len + 1));
		str[0] = '+';
		ft_strcpy(&str[1], node->str);
		ft_strdel(&(node->str));
		node->str = str;
		node->len += 1;
	}
}
