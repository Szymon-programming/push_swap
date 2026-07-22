/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_controller.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schoinsk <schoinsk@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 14:43:04 by schoinsk          #+#    #+#             */
/*   Updated: 2026/07/22 14:55:05 by schoinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	count_operations(t_data *data, char *operation)
{
	if (ft_strncmp(operation, "sa", 2) == 0)
		data->bench.sa++;
	else if (ft_strncmp(operation, "sb", 2) == 0)
		data->bench.sb++;
	else if (ft_strncmp(operation, "ss", 2) == 0)
		data->bench.ss++;
	else if (ft_strncmp(operation, "pa", 2) == 0)
		data->bench.pa++;
	else if (ft_strncmp(operation, "pb", 2) == 0)
		data->bench.pb++;
	else if (ft_strncmp(operation, "ra", 2) == 0)
		data->bench.ra++;
	else if (ft_strncmp(operation, "rb", 2) == 0)
		data->bench.rb++;
	else if (ft_strncmp(operation, "rr", 2) == 0)
		data->bench.rr++;
	else if (ft_strncmp(operation, "rra", 3) == 0)
		data->bench.rra++;
	else if (ft_strncmp(operation, "rrb", 3) == 0)
		data->bench.rrb++;
	else if (ft_strncmp(operation, "rrr", 3) == 0)
		data->bench.rrr++;
	data->bench.total_operations++;
}

void	do_operation(t_data *data, char *operation)
{
	if (ft_strncmp(operation, "sa", 3))
		sa(data->a);
	else if (ft_strncmp(operation, "sb", 3))
		sb(data->b);
	else if (ft_strncmp(operation, "ss", 3))
		ss(data->a, data->b);
	else if (ft_strncmp(operation, "pa", 3))
		pa(data->a, data->b);
	else if (ft_strncmp(operation, "pb", 3))
		pb(data->a, data->b);
	else if (ft_strncmp(operation, "ra", 3))
		ra(data->a);
	else if (ft_strncmp(operation, "rb", 3))
		rb(data->b);
	else if (ft_strncmp(operation, "rra", 3))
		ra(data->a);
	else if (ft_strncmp(operation, "rrb", 3))
		rb(data->b);
	else if (ft_strncmp(operation, "rrr", 3))
		rrr(data->a, data->b);
	count_operations(data, operation);
}
