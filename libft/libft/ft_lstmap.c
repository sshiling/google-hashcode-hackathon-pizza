/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noprysk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 14:49:26 by noprysk           #+#    #+#             */
/*   Updated: 2017/11/09 14:49:29 by noprysk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	del(void *content, size_t size)
{
	if (size == 0 || !content)
		return ;
	free(&(*content));
	content = NULL;
}

static void	*ft_free(t_list *head)
{
	ft_lstdel(&head, del);
	return (NULL);
}

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*head;
	t_list	*node;
	t_list	*cursor;

	head = NULL;
	cursor = NULL;
	while (lst != NULL && f != NULL)
	{
		if (!(node = f(lst)))
			return (ft_free(head));
		node->next = NULL;
		if (head == NULL)
		{
			head = node;
			cursor = head;
		}
		else
		{
			cursor->next = node;
			cursor = cursor->next;
		}
		lst = lst->next;
	}
	return (head);
}
