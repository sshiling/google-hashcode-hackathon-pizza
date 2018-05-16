/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noprysk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 13:30:56 by noprysk           #+#    #+#             */
/*   Updated: 2017/10/31 12:04:40 by noprysk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*sor;
	unsigned char	*des;

	sor = (unsigned char *)src;
	des = (unsigned char *)dst;
	if (sor < des)
	{
		while (len > 0)
		{
			des[len - 1] = sor[len - 1];
			len--;
		}
	}
	else
		ft_memcpy(des, sor, len);
	return (des);
}
