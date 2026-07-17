/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schoinsk <schoinsk@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/16 11:25:37 by schoinsk          #+#    #+#             */
/*   Updated: 2026/07/17 10:57:24 by schoinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	int			i;
	t_options	options;

	if (i = init_and_check(argc, argv, &options) == -1)
		write(1, "Error\n", 6);
	parser(argc, argv, i);
	return (0);
}
