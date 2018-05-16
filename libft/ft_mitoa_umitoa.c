/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ints.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noprysk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/24 17:13:12 by noprysk           #+#    #+#             */
/*   Updated: 2017/12/24 17:13:15 by noprysk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

static intmax_t		len(intmax_t num)
{
	intmax_t		i;
	size_t			n;

	i = 0;
	if (num < 0)
		num = -num;
	n = (size_t)num;
	while (n > 0)
	{
		i++;
		n = n / 10;
	}
	return (i);
}

static char			*pos(intmax_t n)
{
	intmax_t		i;
	char			*str;
	intmax_t		l;

	i = 0;
	l = len(n);
	CHECK(str = ft_memalloc(l + 1));
	while (l > 0)
	{
		str[l - 1] = '0' + (n % 10);
		n = n / 10;
		l--;
	}
	return (str);
}

char				*ft_mitoa(intmax_t n)
{
	intmax_t		i;
	char			*str;
	intmax_t		l;
	size_t			num;

	if (n == 0)
		CHECK(str = ft_strdup("0"));
	else if (n < 0)
	{
		n = -n;
		i = 0;
		l = len(n);
		CHECK(str = ft_memalloc(l + 2));
		num = (size_t)n;
		while (l > 0)
		{
			str[l--] = '0' + (num % 10);
			num /= 10;
		}
		str[0] = '-';
	}
	else
		str = pos(n);
	return (str);
}

static char			*ft_convert(uintmax_t n)
{
	char			*str;
	uintmax_t		l;
	uintmax_t		nb;

	l = 0;
	nb = n;
	while (nb > 0)
	{
		l++;
		nb = nb / 10;
	}
	CHECK(str = ft_memalloc(l + 1));
	if (str == NULL)
		return (NULL);
	while (l > 0)
	{
		str[l - 1] = '0' + (n % 10);
		n = n / 10;
		l--;
	}
	return (str);
}

char				*ft_umitoa(uintmax_t n)
{
	char			*str;

	if (n == 0)
	{
		CHECK(str = ft_memalloc(2));
		ft_strcpy(str, "0");
		return (str);
	}
	return (ft_convert(n));
}
