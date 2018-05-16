/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noprysk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 19:42:52 by noprysk           #+#    #+#             */
/*   Updated: 2017/11/04 19:42:54 by noprysk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	int		i;

	if (!s)
		return (NULL);
	sub = ft_memalloc(len + 1);
	if (!sub)
		return (NULL);
	i = 0;
	while (len > 0)
	{
		sub[i] = s[start];
		len--;
		start++;
		i++;
	}
	return (sub);
}
