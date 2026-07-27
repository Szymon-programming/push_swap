/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_controller.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schoinsk <schoinsk@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/20 15:01:35 by schoinsk          #+#    #+#             */
/*   Updated: 2026/07/27 16:37:45 by schoinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sorting_method_chooser(t_data *data, t_options *options)
{
	if (options->simple == 1)
		selection_sort_with_index(data);
	else if (options->medium == 1)
		chank_sort(data);
	else if (options->complex == 1)
		radix_sort(data);
	else
		adaptive_sort(data);
}

static void	init_stack(t_stack *s, int *numbers, int size)
{
	while (size > 0)
	{
		stack_push(s, numbers[size - 1]);
		size--;
	}
}

int	stack_op_con(int *numbers, int size, t_options *options, t_data *data)
{
	data->a = stack_new();
	data->b = stack_new();
	init_stack(data->a, numbers, size);
	data->disorder = compute_disorder(data->a);
	if (stack_is_sorted(data->a) == 1)
		return (0);
	index_stack(data->a);
	sorting_method_chooser(data, options);
	return (0);
}
