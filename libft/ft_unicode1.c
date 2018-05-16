/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unicode.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noprysk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 15:22:44 by noprysk           #+#    #+#             */
/*   Updated: 2018/01/16 15:22:46 by noprysk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

static int		ft_unicode_help_1(int nb)
{
	int			i;

	i = 0;
	while (nb)
	{
		nb /= 2;
		i++;
	}
	return (i);
}

static void		ft_unicode_help_2(int j, char *mask, int nb)
{
	while (j)
	{
		if (mask[j] != ' ' && mask[j] != '0' && mask[j] != '1')
		{
			mask[j] = '0' + nb % 2;
			nb /= 2;
		}
		j--;
	}
}

void			ft_unicode(t_print *node, wchar_t a)
{
	int			i;
	int			j;
	char		*mask;
	int			*array;

	i = ft_unicode_help_1(a);
	mask = ft_mask_len(node, i);
	ft_unicode_help_2(ft_strlen(mask) - 1, mask, a);
	array = ft_array(mask);
	i = 0;
	CHECK(node->str = ft_strnew(node->len));
	j = 0;
	while (array[i])
	{
		node->str[j] = (char)(array[i]);
		j++;
		i++;
	}
	ft_strdel(&mask);
	free(array);
}

void			ft_sunicode(t_print *node, wchar_t *w_str)
{
	int			len;
	char		*big;
	char		*temp;

	len = 0;
	CHECK(big = ft_strnew(0));
	while (*w_str)
	{
		ft_unicode(node, *w_str++);
		len += node->len;
		if (g_dot != -1 && len > g_dot)
			break ;
		temp = big;
		CHECK(big = ft_strnew(len));
		ft_strcpy(big, temp);
		ft_strcpy(&big[len - node->len], node->str);
		ft_strdel(&node->str);
		ft_strdel(&temp);
	}
	ft_strdel(&node->str);
	node->str = big;
	node->len = (g_dot != -1 && len > g_dot) ? len - node->len : len;
}
