/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noprysk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 12:34:35 by noprysk           #+#    #+#             */
/*   Updated: 2017/10/29 19:02:09 by noprysk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*str;

	str = (unsigned char *)src;
	while (n > 0)
	{
		ft_memset(dst, *str, 1);
		dst++;
		str++;
		n--;
	}
	return (dst);
}
