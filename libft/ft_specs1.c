/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noprysk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/23 16:44:48 by noprysk           #+#    #+#             */
/*   Updated: 2017/12/23 16:44:49 by noprysk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void				ft_s(t_print *node)
{
	wchar_t			*w_str;

	if (g_on[L].state == ON || g_on[B_S].state == ON)
	{
		if (!(w_str = va_arg(g_lst, wchar_t*)))
		{
			CHECK(node->str = ft_strdup("(null)"));
			node->len = ft_strlen(node->str);
		}
		else
			ft_sunicode(node, w_str);
	}
	else
	{
		node->str = ft_strdup((const char*)va_arg(g_lst, char*));
		node->str = !(node->str) ? ft_strdup("(null)") : node->str;
		CHECK(node->str);
		node->len = ft_strlen(node->str);
	}
}

void				ft_i_d(t_print *node)
{
	if (g_on[Z].state == ON)
		node->str = ft_mitoa((size_t)va_arg(g_lst, size_t));
	else if (g_on[J].state == ON)
		node->str = ft_mitoa((intmax_t)va_arg(g_lst, intmax_t));
	else if (g_on[LL].state == ON)
		node->str = ft_mitoa((long long)va_arg(g_lst, long long));
	else if (g_on[L].state == ON || g_on[B_D].state == ON)
		node->str = ft_mitoa((long)va_arg(g_lst, long));
	else if (g_on[H].state == ON)
		node->str = ft_itoa((short)va_arg(g_lst, int));
	else if (g_on[HH].state == ON)
		node->str = ft_itoa((char)va_arg(g_lst, int));
	else
		node->str = ft_itoa((int)va_arg(g_lst, int));
	node->len = ft_strlen(node->str);
}

void				ft_c(t_print *node)
{
	if (g_on[L].state == ON || g_on[B_C].state == ON)
		ft_unicode(node, va_arg(g_lst, wchar_t));
	else
	{
		CHECK(node->str = ft_strnew(1));
		node->str[0] = (char)va_arg(g_lst, int);
		node->len = 1;
	}
}

void				ft_u(t_print *node)
{
	if (g_on[Z].state == ON)
		node->str = ft_umitoa((size_t)va_arg(g_lst, size_t));
	else if (g_on[J].state == ON)
		node->str = ft_umitoa((uintmax_t)va_arg(g_lst, uintmax_t));
	else if (g_on[LL].state == ON)
		node->str = ft_umitoa((unsigned long long)\
			va_arg(g_lst, unsigned long long));
	else if (g_on[L].state == ON || g_on[B_U].state == ON)
		node->str = ft_umitoa((unsigned long)va_arg(g_lst, unsigned long int));
	else if (g_on[H].state == ON)
		node->str = ft_umitoa((unsigned short)va_arg(g_lst, unsigned int));
	else if (g_on[HH].state == ON)
		node->str = ft_umitoa((unsigned char)va_arg(g_lst, unsigned int));
	else
		node->str = ft_umitoa((unsigned int)va_arg(g_lst, unsigned int));
	node->len = ft_strlen(node->str);
}

void				ft_per(t_print *node)
{
	CHECK(node->str = ft_strnew(1));
	node->str[0] = '%';
	node->len = 1;
}
