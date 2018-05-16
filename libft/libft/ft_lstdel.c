/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noprysk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 12:11:21 by noprysk           #+#    #+#             */
/*   Updated: 2017/11/09 12:11:22 by noprysk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *cursor;

	if (!alst || !del)
		return ;
	cursor = *alst;
	while (cursor != NULL)
	{
		cursor = cursor->next;
		ft_lstdelone(alst, del);
		*alst = cursor;
	}
}
