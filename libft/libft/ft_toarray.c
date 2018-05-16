/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toarray.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noprysk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 19:23:24 by noprysk           #+#    #+#             */
/*   Updated: 2017/11/09 19:23:25 by noprysk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_static(t_list *head)
{
	int		i;

	i = 0;
	while (head != NULL)
	{
		i++;
		head = head->next;
	}
	return (i);
}

char		**ft_toarray(t_list *head)
{
	char	**array;
	int		i;

	i = 0;
	array = malloc((sizeof(char *)) * (1 + ft_count_static(head)));
	if (head == NULL)
		return (NULL);
	while (head != NULL)
	{
		array[i] = head->content;
		head = head->next;
		i++;
	}
	return (array);
}
