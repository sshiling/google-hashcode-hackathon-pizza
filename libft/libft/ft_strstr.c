/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noprysk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 11:23:25 by noprysk           #+#    #+#             */
/*   Updated: 2017/11/01 13:07:33 by noprysk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strstr(const char *haystack, const char *needle)
{
	char	*hay;
	char	*nd;
	int		i;

	hay = (char *)haystack;
	nd = (char *)needle;
	i = 0;
	if (ft_strlen(nd) == 0)
		return (hay);
	while (hay[i] != '\0')
	{
		if (ft_strncmp(&hay[i], nd, ft_strlen(nd)) == 0)
			return (&hay[i]);
		else
			i++;
	}
	return (NULL);
}
