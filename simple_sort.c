/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schoinsk <schoinsk@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 16:22:15 by schoinsk          #+#    #+#             */
/*   Updated: 2026/07/23 15:18:04 by schoinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_target_position(t_data *data, int index_target)
{
	t_node	*current;
	int		position;

	current = data->a->top;
	position = 0;
	while (current)
	{
		if (current->index == index_target)
			return (position);
		position++;
		current = current->next;
	}
	return (-1);
}

static void	bring_to_top_a(t_data *data, int position)
{
	int	stack_size;
	int	shifts;

	if (position <= 0)
		return;
	stack_size = data->a->size;
	if (position <= stack_size / 2)
	{
		shifts = position;
		while (shifts > 0)
		{
			do_operation(data, "ra");
			shifts--;
		}
	}
	else
	{
		shifts = stack_size - position;
		while (shifts > 0)
		{
			do_operation(data, "rra");
			shifts--;
		}
	}
}

void	selection_sort_with_index(t_data *data)
{
	int	index_target;
	int	position;

	index_target = 0;
	position = 0;
	while (data->a->size > 1)
	{
		position = get_target_position(data, index_target);
		bring_to_top_a(data, position);
		do_operation(data, "pb");
		index_target++;
	}
	while (data->b->size > 0)
		do_operation(data, "pa");
}
