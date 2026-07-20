/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schoinsk <schoinsk@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/16 11:25:37 by schoinsk          #+#    #+#             */
/*   Updated: 2026/07/20 14:30:23 by schoinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	int			i;
	int			*numbers;
	t_options	options;

	i = init_and_check(argc, argv, &options);
	if (i == -1)
		exit_error();
	numbers = get_parsed_numbers(argc, argv, i);
	if (numbers == NULL)
		exit_error();
	return (0);
}
