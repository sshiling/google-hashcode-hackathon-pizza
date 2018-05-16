/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_on.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noprysk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/21 16:35:27 by noprysk           #+#    #+#             */
/*   Updated: 2018/01/21 16:35:29 by noprysk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

t_flag			g_on[] =
{
	{"0", OFF},
	{"#", OFF},
	{"-", OFF},
	{"+", OFF},
	{" ", OFF},
	{"hh", OFF},
	{"h", OFF},
	{"l", OFF},
	{"ll", OFF},
	{"j", OFF},
	{"z", OFF},
	{"s", OFF},
	{"S", OFF},
	{"p", OFF},
	{"d", OFF},
	{"D", OFF},
	{"i", OFF},
	{"o", OFF},
	{"O", OFF},
	{"u", OFF},
	{"U", OFF},
	{"x", OFF},
	{"X", OFF},
	{"c", OFF},
	{"C", OFF},
	{"n", OFF},
	{"b", OFF},
	{"%", OFF},
	{".", OFF},
	{"nb", OFF},
};

static void		ft_on_basic(const char *str, int beg, int end)
{
	int			j;
	int			len;

	j = SHARP;
	len = end - beg + 1;
	while (j < NFLAGS - 3)
	{
		if (ft_strnstr(&str[beg], g_on[j].c, len))
			g_on[j].state = ON;
		j++;
	}
}

static void		ft_on_prec(const char *str, int *beg)
{
	(*beg)++;
	g_on[DOT].state = ON;
	if (str[*beg] == '*')
	{
		g_dot = va_arg(g_lst, int);
		if (g_dot < 0)
			g_on[DOT].state = OFF;
		(*beg)++;
	}
	else if (!DIGIT(str[*beg]))
		g_dot = 0;
	else if (DIGIT(str[*beg]))
	{
		g_dot = ft_atoi(&str[*beg]);
		while (DIGIT(str[*beg]))
			(*beg)++;
	}
}

static void		ft_on_star(int *beg)
{
	g_on[NB].state = ON;
	g_nb = va_arg(g_lst, int);
	if (g_nb < 0)
	{
		g_nb = -g_nb;
		g_on[MINUS].state = ON;
	}
	(*beg)++;
}

static void		ft_on_nb(const char *str, int *beg)
{
	g_nb = ft_atoi(&str[*beg]);
	g_on[NB].state = ON;
	while (DIGIT(str[*beg]))
		(*beg)++;
}

void			ft_on(const char *str, int beg, int end)
{
	g_dot = -1;
	g_nb = -1;
	ft_on_basic(str, beg, end);
	while (beg < end)
	{
		if (str[beg] == '.')
			ft_on_prec(str, &beg);
		else if (str[beg] == '*')
			ft_on_star(&beg);
		else if (str[beg] >= '1' && str[beg] <= '9')
			ft_on_nb(str, &beg);
		else if (str[beg] == '0' && !(str[beg - 1] >= '1'\
			&& str[beg - 1] <= '9'))
		{
			g_on[ZERO].state = ON;
			beg++;
		}
		else
			beg++;
	}
	g_on[H].state = (g_on[HH].state == ON) ? OFF : g_on[H].state;
	g_on[L].state = (g_on[LL].state == ON) ? OFF : g_on[L].state;
}
