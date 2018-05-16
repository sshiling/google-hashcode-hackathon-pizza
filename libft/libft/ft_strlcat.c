/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noprysk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 20:04:50 by noprysk           #+#    #+#             */
/*   Updated: 2017/11/26 17:17:40 by noprysk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	len;

	len = ft_strlen(dst);
	if (dstsize > len)
	{
		ft_strncat(dst, src, (dstsize - len - 1));
		ft_memset(&dst[dstsize - 1], '\0', 1);
	}
	if (dstsize < len)
		return (dstsize + ft_strlen(src));
	else
		return (len + ft_strlen(src));
}
