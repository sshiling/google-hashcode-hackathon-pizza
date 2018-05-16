/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noprysk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 16:01:04 by noprysk           #+#    #+#             */
/*   Updated: 2017/10/29 11:37:49 by noprysk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned int	i;
	unsigned char	*s1;
	unsigned char	*s2;
	unsigned char	ch;

	i = 0;
	s1 = (unsigned char *)src;
	s2 = (unsigned char *)dst;
	ch = (unsigned char)c;
	if (ft_memchr(s1, ch, n) == NULL)
	{
		ft_memcpy(s2, s1, n);
		return (NULL);
	}
	else
	{
		while (s1[i] != ch)
			i++;
		ft_memcpy(s2, s1, i + 1);
		return (&s2[i + 1]);
	}
}
