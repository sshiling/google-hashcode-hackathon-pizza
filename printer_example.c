/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer_example.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshiling <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 15:09:55 by sshiling          #+#    #+#             */
/*   Updated: 2018/02/28 15:09:58 by sshiling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hashcode_pizza.h"

typedef struct      s_slice
{
	int             x_cord[2];
	int             y_cord[2];
	struct s_slice  *next;
}					t_slice;

typedef struct      s_res
{
	int             slices_num;
	struct s_slice  *slice;
}                   t_res;

void			print_result(t_res *pizza)
{
	FILE *fp;

	fp = fopen("result_example.txt", "ab+");
	fprintf(fp, "%i\n", pizza->slices_num);
	while (pizza->slice)
	{
		fprintf(fp, "%i %i %i %i\n", pizza->slice->y_cord[0], pizza->slice->x_cord[0], pizza->slice->y_cord[1], pizza->slice->x_cord[1]);
		pizza->slice = pizza->slice->next;
	}
}

static t_slice  *slice_creator(int *x_cord, int *y_cord)
{
	t_slice *new;

	int i;

	i = -1;

	new = (t_slice*)malloc(sizeof(t_slice));
	while (++i < 2)
	{
		new->x_cord[i] = x_cord[i];
		new->y_cord[i] = y_cord[i];
	}
	new->next = NULL;
	return (new);
}

static void		result_creator(t_res **pizza, t_slice *slice)
{
	t_slice *tmp;

	if (!(*pizza))
	{
		*pizza = (t_res*)malloc(sizeof(t_res));
		(*pizza)->slices_num = 3;
		(*pizza)->slice = NULL;
	}
	if (!(*pizza)->slice)
		(*pizza)->slice = slice;
	else
	{
		tmp = (*pizza)->slice;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = slice;
	}
}

int 	main(void)
{
	t_res	*pizza;
	t_slice *slice_1;
	t_slice *slice_2;
	t_slice *slice_3;
	int 	x1[2] = {0, 1};
	int		x2[2] = {2, 2};
	int		x3[2] = {3, 4};
	int		y[2] = {0, 2};

	pizza = NULL;
	slice_1 = slice_creator(x1, y);
	slice_2 = slice_creator(x2, y);
	slice_3 = slice_creator(x3, y);

	result_creator(&pizza, slice_1);
	result_creator(&pizza, slice_2);
	result_creator(&pizza, slice_3);

	print_result(pizza);
	return (0);
}