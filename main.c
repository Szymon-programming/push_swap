/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schoinsk <schoinsk@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/16 11:25:37 by schoinsk          #+#    #+#             */
/*   Updated: 2026/07/22 14:45:08 by schoinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	int			i;
	int			*numbers;
	int			size;
	t_options	options;
	t_data		data;

	i = init_and_check(argc, argv, &options);
	ft_bzero(&data.bench, sizeof(t_bench));
	if (i == -1)
		exit_error();
	numbers = get_parsed_numbers(argc, argv, i, &size);
	if (numbers == NULL)
		exit_error();
	i = stack_operations_controller(numbers, size, &options, &data);
	if (options.bench == 1)
		print_bench(&data, &options);
	return (0);
}
