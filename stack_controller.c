/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_controller.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schoinsk <schoinsk@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/20 15:01:35 by schoinsk          #+#    #+#             */
/*   Updated: 2026/07/22 15:53:39 by schoinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sorting_method_chooser(t_data *data, t_options *options)
{
	if (options->simple == 1)
		radix_sort(data);
	else if (options->medium == 1)
		radix_sort(data);
	else if (options->complex == 1)
		radix_sort(data);
	else
		radix_sort(data);
}

static void	init_stack(t_data *data, int *numbers, int size)
{
	while (size > 0)
	{
		stack_push(data->a, numbers[size - 1]);
	}
}

int	stack_operations_controller(int *numbers, int size, t_options *options, t_data *data)
{
	data->a = stack_new();
	data->b = stack_new();
	init_stack(data, numbers, size);
	data->disorder = compute_disorder(data->a);
	if (stack_is_sorted(data->a) == 1)
		return (1);
	sorting_method_chooser(data, options);
	return (0);
}
