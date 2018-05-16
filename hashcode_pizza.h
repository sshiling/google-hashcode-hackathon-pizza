/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashcode_pizza.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noprysk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 19:45:19 by noprysk           #+#    #+#             */
/*   Updated: 2018/02/26 19:45:21 by noprysk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HASHCODE_PIZZA_H
# define HASHCODE_PIZZA_H

#include "./libft/ft.h"
#include <stdio.h>
#include <fcntl.h>


typedef struct s_pizza	t_pizza;
typedef struct s_slice	t_slice;
typedef struct s_res	t_res;
typedef struct s_point	t_point;

struct	s_pizza
{
	int			rows;
	int			columns;
	int			min_ingr;
	int			max_cells;
	char		**pizza;
};

struct      s_slice
{
	t_point	*start;
	t_point	*end;
	t_slice	*next;
};

struct      s_res
{
	int		slices_num;
	t_slice	*slices;
};

struct      s_point
{
	int x;
	int y;
};

void			generate_pizza(int fd, int rows, int columns,\
				int min_ingredients_per_slice, int max_cells_per_slice);
t_pizza			*reader(int fd);
void			print_pizza(t_res *pizza);
t_res	*cut_pizza(t_pizza *pizza_file);

#endif
