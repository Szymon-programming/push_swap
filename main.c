/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schoinsk <schoinsk@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/16 11:25:37 by schoinsk          #+#    #+#             */
/*   Updated: 2026/07/27 18:22:02 by schoinsk         ###   ########.fr       */
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

	numbers = NULL;
	size = 0;
	ft_bzero(&data, sizeof(t_data));
	if (argc == 1)
		exit(0);
	i = init_and_check(argc, argv, &options);
	if (i == -1)
		exit_error();
	ft_bzero(&data.bench, sizeof(t_bench));
	numbers = get_parsed_numbers(argc, argv, i, &size);
	if (numbers == NULL)
		exit_and_free(&data, numbers);
	stack_op_con(numbers, size, &options, &data);
	return (0);
}
