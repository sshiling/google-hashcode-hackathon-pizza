/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cut_pizza.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchornyi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 15:05:01 by vchornyi          #+#    #+#             */
/*   Updated: 2018/02/28 15:05:02 by vchornyi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hashcode_pizza.h"

t_point	*init_point(int	x, int y)
{
	t_point	*point;

	point = (t_point *)malloc(sizeof(t_point));
	if (!point)
		exit(1);
	point->x = x;
	point->y = y;
	return (point);
}

int 	is_in_map(t_point *point, t_pizza *pizza_file)
{
	if (point->x > pizza_file->columns)
		return (0);
	if (point->y > pizza_file->rows)
		return (0);
	return (1);
}

int 	is_in_res(t_slice *slice, int x, int y)
{
	if (x >= slice->start->x && x < slice->end->x && y >= slice->start->y && y < slice->end->y)
		return (1);
	return (0);
}

void	move_point(t_point *point, t_pizza *pizza_file, t_res *res)
{
	t_slice *iter;

	if (point->x + 1 <= pizza_file->columns)
		point->x++;
	else
	{
		point->x = 0;
		point->y++;
	}
	if (!res)
		return ;
	iter = res->slices;
	while (iter)
	{
		if (is_in_res(iter, point->x, point->y))
			move_point(point, pizza_file, res);
		iter = iter->next;
	}
}

int		get_next_rect(t_point *point, int size, t_point *start)
{
	if (point->x == start->x && point->y == start->y)
	{
		point->x = size + start->x;
		point->y = start->y + 1;
	}
	else
	{
		point->y++;
		while (point->x - start->x)
		{
			point->x--;
			if ((point->y - start->y) * (point->x - start->x) == size)
				break;
		}
		if (point->x == start->x)
			return (0);
	}
	return (1);
}

int 	find_ingredients(t_pizza *pizza_file, t_point *start, t_point *end)
{
	int map_x;
	int map_y;
	int t;
	int m;

	t = 0;
	m = 0;
	map_y = start->y;
	while (map_y < end->y)
	{
		map_x = start->x;
		while (map_x < end->x)
		{
			if (pizza_file->pizza[map_y][map_x] == 'T')
				t++;
			else
				m++;
			map_x++;
		}
		map_y++;
	}
	if (m >= pizza_file->min_ingr && t >= pizza_file->min_ingr)
		return (1);
	return (0);
}

int 	is_ok(char	**map, int x, int y)
{
	int map_x;
	int map_y;

	map_x = 0;
	map_y = 0;
	while (map[0][map_x])
		map_x++;
	while (map[map_y])
		map_y++;
	if (x > map_x || y > map_y)
		return (0);
	return (1);
}

int 	is_overlap(t_res *res, t_point *start, t_point *end)
{
	t_slice *iter;
	int 	x;
	int 	y;

	x = start->x;
	y = start->y;
	if (!res)
		return (0);
	while (x < end->x && y < end->y)
	{
		iter = res->slices;
		while (iter)
		{
			if (is_in_res(iter, x, y))
				return (1);
			iter = iter->next;
		}
		if (x + 1 < end->x)
			x++;
		else
		{
			x = start->x;
			y++;
		}
	}
	return (0);
}

t_point *try_to_cut(t_point *start, int size, t_pizza *pizza_file, t_res *res)
{
	t_point	*end;

	end = init_point(start->x, start->y);
	while (get_next_rect(end, size, start))
	{
		if (is_ok(pizza_file->pizza, end->x, end->y))
			if (find_ingredients(pizza_file, start, end))
				if (!is_overlap(res, start, end))
					return (end);
	}
	return (NULL);
}

t_slice	*init_slice(t_point *start, t_point *end)
{
	t_slice *slice;

	slice = (t_slice * )malloc(sizeof(t_slice));
	if (!slice)
		exit(1);
	slice->start = init_point(start->x, start->y);
	slice->end = init_point(end->x, end->y);
	slice->next = NULL;
	return (slice);
}

void	add_res(t_res **res, t_point *start, t_point *end)
{
	t_slice *iter;

	if (!*res)
	{
		*res = (t_res *)malloc(sizeof(t_res));
		if(!*res)
			exit(1);
		(*res)->slices_num = 1;
		(*res)->slices = init_slice(start, end);
	}
	else
	{
		iter = (*res)->slices;
		while (iter->next)
		{
			iter = iter->next;
		}
		iter->next = init_slice(start, end);
		(*res)->slices_num++;
	}
}

t_res	*cut_pizza(t_pizza *pizza_file)
{
	t_res	*res;
	int 	size;
	t_point	*point;
	t_point	*end;

	size = pizza_file->min_ingr * 2;
	point = init_point(0, 0);
	res = NULL;
	while (is_in_map(point, pizza_file))
	{
		while (size <= pizza_file->max_cells)
		{
			if ((end = try_to_cut(point, size, pizza_file, res)))
			{
				add_res(&res, point, end);
				break;
			}
			else
				size++;
		}
		size = pizza_file->min_ingr * 2;
		move_point(point, pizza_file, res);
	}
	return (res);
}
