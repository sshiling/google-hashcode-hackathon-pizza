/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_magic.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noprysk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 15:58:23 by noprysk           #+#    #+#             */
/*   Updated: 2017/12/19 15:58:26 by noprysk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

static t_print	*ft_vset(t_print **head)
{
	t_print	*cursor;
	t_print	*node;

	cursor = *head;
	while (cursor && cursor->next)
		cursor = cursor->next;
	CHECK(node = malloc(sizeof(t_print)));
	if (*head)
		cursor->next = node;
	else
		*head = node;
	node->next = NULL;
	node->str = NULL;
	node->len = 0;
	return (node);
}

static void		ft_arg_help(t_print *node, int end, const char *str)
{
	g_on[S_C].state = ON;
	CHECK(node->str = ft_strnew(1));
	node->str[0] = str[end];
	if (node->str[0])
		node->len = 1;
}

static void		ft_arg(t_print *head, t_print *node, int end, const char *str)
{
	if (g_on[S_S].state == ON || g_on[B_S].state == ON)
		ft_s(node);
	else if (g_on[I].state == ON || D)
		ft_i_d(node);
	else if (g_on[S_C].state == ON || g_on[B_C].state == ON)
		ft_c(node);
	else if (U)
		ft_u(node);
	else if (O)
		ft_o(node);
	else if (X)
		ft_x(node);
	else if (g_on[P].state == ON)
		ft_p(node);
	else if (g_on[PER].state == ON)
		ft_per(node);
	else if (g_on[N].state == ON)
		ft_n(head);
	else if (g_on[B].state == ON)
		ft_b(node);
	else
		ft_arg_help(node, end, str);
}

static void		ft_null(void)
{
	int			j;

	j = 0;
	while (j <= NFLAGS)
	{
		g_on[j].state = OFF;
		j++;
	}
}

void			ft_magic(const char *str, t_print **head, int beg, int end)
{
	t_print		*node;

	ft_on(str, beg, end);
	node = ft_vset(head);
	ft_arg(*head, node, end, str);
	if (g_on[DOT].state == ON)
		ft_dot(node);
	if (g_on[PLUS].state == ON)
		ft_plus(node);
	if (g_on[SHARP].state == ON)
		ft_sharp(node);
	if (g_on[SPACE].state == ON)
		ft_space(node);
	if (g_on[NB].state == ON)
		ft_nb(node);
	ft_null();
}
