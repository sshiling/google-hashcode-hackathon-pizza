/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noprysk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 19:28:16 by noprysk           #+#    #+#             */
/*   Updated: 2017/10/30 11:35:52 by noprysk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	int i;
	int len;

	i = 0;
	len = ft_strlen(s1);
	while (s1[i] != '\0')
		i++;
	ft_strncpy(&s1[i], s2, (1 + (ft_strlen(s2)) > n ? n : 1 + ft_strlen(s2)));
	ft_bzero(&s1[(1 + (ft_strlen(s2)) > n ? len + n : len + ft_strlen(s2))], 1);
	return (s1);
}
