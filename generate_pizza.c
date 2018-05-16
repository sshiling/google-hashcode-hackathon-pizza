/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_pizza.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noprysk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 19:50:49 by noprysk           #+#    #+#             */
/*   Updated: 2018/02/26 19:50:50 by noprysk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hashcode_pizza.h"

void			generate_pizza(int fd, int rows, int columns,\
				int min_ingredients_per_slice, int max_cells_per_slice)
{
	FILE			*file;
	int				nb;
	int				i;
	int				j;

	file = fopen("/dev/random", "r");
	i = 0;
	ft_printf("{fd}%i %i %i %i\n", fd, rows, columns\
		, min_ingredients_per_slice, max_cells_per_slice);
	while (i < rows)
	{
		j = 0;
		while (j < columns)
		{
			fread(&nb, sizeof(nb), 1, file);
			(nb % 2) ? ft_printf("{fd}T", fd)\
			: ft_printf("{fd}M", fd);
			j++;
		}
		ft_printf("{fd}\n", fd);
		i++;
	}
	fclose(file);
}
