/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noprysk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 13:52:33 by noprysk           #+#    #+#             */
/*   Updated: 2017/10/30 14:11:46 by noprysk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strrchr(const char *s, int c)
{
	char	*str;
	char	ch;
	size_t	i;

	str = (char *)s;
	ch = (char)c;
	i = ft_strlen(str);
	if (c == '\0')
		return (&str[i]);
	while (i > 0 && s[i] != ch)
		i--;
	if (str[i] == ch)
		return (&str[i]);
	else
		return (NULL);
}
