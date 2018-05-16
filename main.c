/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchornyi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 19:38:40 by vchornyi          #+#    #+#             */
/*   Updated: 2018/02/26 19:38:42 by vchornyi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hashcode_pizza.h"

int			main(int argc, char **argv)
{
	int		fd_gen;
	int		fd;
	t_pizza *pizza;
	t_res	*res;

	if (argc < 2)
		exit(1);
	else if (ft_strequ(argv[1], "-g"))
	{
		fd_gen = open("pizza.txt", O_WRONLY| O_CREAT | O_TRUNC | O_APPEND, 0666);
		generate_pizza(fd_gen, ft_atoi(argv[2]), ft_atoi(argv[3]), ft_atoi(argv[4]), ft_atoi(argv[5]));
	}
	else
	{
		fd = open(argv[1], O_RDONLY);
		pizza = reader(fd);
		// print_pizza(pizza);
		res = cut_pizza(pizza);
		print_pizza(res);
	}
	return (0);
}
