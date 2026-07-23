/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_controller.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schoinsk <schoinsk@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 14:43:04 by schoinsk          #+#    #+#             */
/*   Updated: 2026/07/23 15:03:30 by schoinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	count_operations(t_data *data, char *operation)
{
	if (ft_strncmp(operation, "rra", 4) == 0)
		data->bench.rra++;
	else if (ft_strncmp(operation, "rrb", 4) == 0)
		data->bench.rrb++;
	else if (ft_strncmp(operation, "rrr", 4) == 0)
		data->bench.rrr++;
	else if (ft_strncmp(operation, "sa", 3) == 0)
		data->bench.sa++;
	else if (ft_strncmp(operation, "sb", 3) == 0)
		data->bench.sb++;
	else if (ft_strncmp(operation, "ss", 3) == 0)
		data->bench.ss++;
	else if (ft_strncmp(operation, "pa", 3) == 0)
		data->bench.pa++;
	else if (ft_strncmp(operation, "pb", 3) == 0)
		data->bench.pb++;
	else if (ft_strncmp(operation, "ra", 3) == 0)
		data->bench.ra++;
	else if (ft_strncmp(operation, "rb", 3) == 0)
		data->bench.rb++;
	else if (ft_strncmp(operation, "rr", 3) == 0)
		data->bench.rr++;
	data->bench.total_operations++;
}

void	do_operation(t_data *data, char *operation)
{
	if (ft_strncmp(operation, "rra", 4) == 0)
		rra(data->a);
	else if (ft_strncmp(operation, "rrb", 4) == 0)
		rrb(data->b);
	else if (ft_strncmp(operation, "rrr", 4) == 0)
		rrr(data->a, data->b);
	else if (ft_strncmp(operation, "sa", 3) == 0)
		sa(data->a);
	else if (ft_strncmp(operation, "sb", 3) == 0)
		sb(data->b);
	else if (ft_strncmp(operation, "ss", 3) == 0)
		ss(data->a, data->b);
	else if (ft_strncmp(operation, "pa", 3) == 0)
		pa(data->a, data->b);
	else if (ft_strncmp(operation, "pb", 3) == 0)
		pb(data->a, data->b);
	else if (ft_strncmp(operation, "ra", 3) == 0)
		ra(data->a);
	else if (ft_strncmp(operation, "rb", 3) == 0)
		rb(data->b);
	count_operations(data, operation);
}
