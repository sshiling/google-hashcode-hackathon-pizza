/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noprysk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 14:02:56 by noprysk           #+#    #+#             */
/*   Updated: 2018/02/28 14:02:58 by noprysk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hashcode_pizza.h"

void			print_pizza(t_res *pizza)
{
	FILE *fp;

	fp = fopen("result_example.txt", "ab+");
	fprintf(fp, "%i\n", pizza->slices_num);
	while (pizza->slices)
	{
		fprintf(fp, "%i %i %i %i\n", pizza->slices->start->y, pizza->slices->start->x, pizza->slices->end->y - 1, pizza->slices->end->x - 1);
		pizza->slices = pizza->slices->next;
	}
}