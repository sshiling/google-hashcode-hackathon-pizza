/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noprysk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 15:44:34 by noprysk           #+#    #+#             */
/*   Updated: 2017/10/29 17:45:49 by noprysk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strdup(const char *s1)
{
	char	*dup;

	if (!s1)
		return (NULL);
	dup = (char *)malloc(sizeof(char) * (1 + ft_strlen(s1)));
	if (dup == NULL)
		return (NULL);
	ft_memcpy(dup, s1, (1 + ft_strlen(s1)));
	return (dup);
}
