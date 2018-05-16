/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_specs2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noprysk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 20:01:24 by noprysk           #+#    #+#             */
/*   Updated: 2018/01/18 20:04:28 by noprysk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

static char			*ft_to_o(uintmax_t nb)
{
	int				len;
	uintmax_t		j;
	char			*str;

	if (nb == 0)
	{
		CHECK(str = ft_strnew(1));
		str[0] = '0';
		return (str);
	}
	len = 0;
	j = nb;
	while (j)
	{
		len++;
		j /= 8;
	}
	CHECK(str = ft_strnew(len));
	while (len)
	{
		str[--len] = (char)('0' + nb % 8);
		nb /= 8;
	}
	return (str);
}

void				ft_o(t_print *node)
{
	if (g_on[Z].state == ON)
		node->str = ft_to_o((size_t)va_arg(g_lst, size_t));
	else if (g_on[J].state == ON)
		node->str = ft_to_o((uintmax_t)va_arg(g_lst, uintmax_t));
	else if (g_on[LL].state == ON)
		node->str = ft_to_o((unsigned long long)\
			va_arg(g_lst, unsigned long long));
	else if (g_on[L].state == ON || g_on[B_O].state == ON)
		node->str = ft_to_o((unsigned long)va_arg(g_lst, unsigned long));
	else if (g_on[H].state == ON)
		node->str = ft_to_o((unsigned short)va_arg(g_lst, unsigned int));
	else if (g_on[HH].state == ON)
		node->str = ft_to_o((unsigned char)va_arg(g_lst, unsigned int));
	else
		node->str = ft_to_o((unsigned int)va_arg(g_lst, unsigned int));
	node->len = ft_strlen(node->str);
}

static char			*ft_to_x(uintmax_t nb, int up)
{
	int				len;
	uintmax_t		j;
	char			*str;

	if (nb == 0)
	{
		CHECK(str = ft_strnew(1));
		str[0] = '0';
		return (str);
	}
	len = 1;
	j = nb;
	while ((j /= 16) != 0)
		len++;
	CHECK(str = ft_strnew(len));
	while (len)
	{
		len--;
		str[len] = nb % 16 < 10 ? (char)('0' + nb % 16)\
		: (char)('a' - up + (nb % 16) - 10);
		nb /= 16;
	}
	return (str);
}

void				ft_x(t_print *node)
{
	if (g_on[Z].state == ON)
		node->str = ft_to_x((size_t)va_arg(g_lst, size_t),\
			g_on[B_X].state == ON ? UP : OFF);
	else if (g_on[J].state == ON)
		node->str = ft_to_x((uintmax_t)va_arg(g_lst, uintmax_t),\
			g_on[B_X].state == ON ? UP : OFF);
	else if (g_on[LL].state == ON)
		node->str = ft_to_x((unsigned long long)\
			va_arg(g_lst, unsigned long long),\
			g_on[B_X].state == ON ? UP : OFF);
	else if (g_on[L].state == ON)
		node->str = ft_to_x((unsigned long)va_arg(g_lst, unsigned long),\
			g_on[B_X].state == ON ? UP : OFF);
	else if (g_on[H].state == ON)
		node->str = ft_to_x((unsigned short)va_arg(g_lst, unsigned int),\
			g_on[B_X].state == ON ? UP : OFF);
	else if (g_on[HH].state == ON)
		node->str = ft_to_x((unsigned char)va_arg(g_lst, unsigned int),\
			g_on[B_X].state == ON ? UP : OFF);
	else
		node->str = ft_to_x((unsigned int)va_arg(g_lst, unsigned int),\
			g_on[B_X].state == ON ? UP : OFF);
	if (node->str[0] == '0')
		g_on[SHARP].state = OFF;
	node->len = ft_strlen(node->str);
}

void				ft_p(t_print *node)
{
	node->str = ft_to_x((uintmax_t)va_arg(g_lst, void *), OFF);
	g_on[S_X].state = ON;
	g_on[SHARP].state = ON;
	node->len = ft_strlen(node->str);
}
