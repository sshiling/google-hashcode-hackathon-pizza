/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noprysk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/02 20:55:47 by noprysk           #+#    #+#             */
/*   Updated: 2017/11/02 20:55:49 by noprysk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*hay;
	char	*nd;
	size_t	i;

	hay = (char *)haystack;
	nd = (char *)needle;
	i = 0;
	if (ft_strlen(nd) == 0)
		return (hay);
	while (hay[i] != '\0' && i < len)
	{
		if (ft_strncmp(&hay[i], nd, ft_strlen(nd)) == 0 &&
			i + ft_strlen(nd) <= len)
		{
			return (&hay[i]);
		}
		else
			i++;
	}
	return (NULL);
}
