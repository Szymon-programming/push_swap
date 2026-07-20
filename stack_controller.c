/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_controller.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schoinsk <schoinsk@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/20 15:01:35 by schoinsk          #+#    #+#             */
/*   Updated: 2026/07/20 17:48:57 by schoinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sorting_method_chooser(t_stack a, t_stack b, t_options *options)
{
	if (options->simple == 1)
		//funkcja do sortowania prostego(O(n^2))
	else if (options->medium == 1)
		//funkcja do sortowania średniego(O(n(sqrt(n))))
	else if (options->complex == 1)
		//funkcja do sortowania(O(n(log(n))))
	else
		//funkcja do adapcyjnego sortowania(disorder)
}

static void	init_stack(t_stack a, int *numbers ,int size)
{
	while (size > 0)
	{
		stack_push(a, numbers[size - 1]);
	}
}

int	stack_operations_controller(int *numbers, int size, t_options *options)
{
	int		i;
	t_stack	a;
	t_stack	b;

	a = stack_new();
	b = stack_new();
	init_stack(a, numbers ,size);
	if (stack_is_sorted(a) == 1)
		return (1);
	sorting_method_chooser(a, b, &options);
}
