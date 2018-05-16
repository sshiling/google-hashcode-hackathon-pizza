/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unicode3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noprysk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 19:19:17 by noprysk           #+#    #+#             */
/*   Updated: 2018/01/19 19:19:19 by noprysk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

static int		ft_two_power(int power)
{
	int			two;

	two = 2;
	if (power == 0)
		return (1);
	while (power > 1)
	{
		two = two * 2;
		power--;
	}
	return (two);
}

static int		ft_base(char *mask, int i)
{
	int			power;
	int			nb;

	power = 0;
	nb = 0;
	while (mask[i] != ' ' && i >= 0)
	{
		nb += (mask[i] - '0') * ft_two_power(power);
		power++;
		i--;
	}
	return (nb);
}

char			*ft_mask_len(t_print *node, int i)
{
	char		*mask;

	if (i <= 7)
	{
		node->len = 1;
		CHECK(mask = ft_strdup("0xxxxxxx"));
	}
	else if (i <= 11)
	{
		node->len = 2;
		CHECK(mask = ft_strdup("110xxxxx 10xxxxxx"));
	}
	else if (i > 11 && i <= 16)
	{
		node->len = 3;
		CHECK(mask = ft_strdup("1110xxxx 10xxxxxx 10xxxxxx"));
	}
	else
	{
		node->len = 4;
		CHECK(mask = ft_strdup("11110xxx 10xxxxxx 10xxxxxx 10xxxxxx"));
	}
	return (mask);
}

int				*ft_array(char *mask)
{
	int			*array;
	int			i;
	int			j;

	CHECK(array = ft_memalloc(sizeof(int) * 4));
	i = 0;
	j = 0;
	while (mask[i])
	{
		if (mask[i] == '1' || mask[i] == '0')
		{
			while (mask[i] == '1' || mask[i] == '0')
				i++;
			array[j] = ft_base(mask, i - 1);
			j++;
		}
		if (mask[i] == ' ')
			i++;
	}
	return (array);
}
