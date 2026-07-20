/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schoinsk <schoinsk@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/16 11:25:37 by schoinsk          #+#    #+#             */
/*   Updated: 2026/07/20 14:13:43 by schoinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	int			i;
	t_options	options;

	i = init_and_check(argc, argv, &options);
	if (i == -1)
		write(1, "Error\n", 6);
	parser(argc, argv, i);
	return (0);
}
