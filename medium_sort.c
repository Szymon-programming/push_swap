/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schoinsk <schoinsk@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/23 14:55:37 by schoinsk          #+#    #+#             */
/*   Updated: 2026/07/23 17:48:28 by schoinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_max_position_b(t_data *data)
{
	t_node	*current;
	int		max_val;
	int		max_pos;
	int		current_pos;

	if (!data->b || !data->b->top)
		return (0);
	current = data->b->top;
	max_val = current->value;
	max_pos = 0;
	current_pos = 0;
	while (current)
	{
		if (current->value > max_val)
		{
			max_val = current->value;
			max_pos = current_pos;
		}
		current = current->next;
		current_pos++;
	}
	return (max_pos);
}

static void	bring_to_top_b(t_data *data, int position)
{
	int	stack_size;
	int	shifts;

	if (position <= 0)
		return ;
	stack_size = data->b->size;
	if (position <= stack_size / 2)
	{
		shifts = position;
		while (shifts > 0)
		{
			do_operation(data, "rb");
			shifts--;
		}
	}
	else
	{
		shifts = stack_size - position;
		while (shifts > 0)
		{
			do_operation(data, "rrb");
			shifts--;
		}
	}
}

static void	push_to_b(t_data *data, int *i, int chunk_size)
{
	int	current_index;

	current_index = data->a->top->index;
	if (current_index >= *i && current_index < (*i + chunk_size / 2))
	{
		do_operation(data, "pb");
		do_operation(data, "rb");
	}
	else if (current_index >= *i && current_index < (*i + chunk_size))
	{
		do_operation(data, "pb");
	}
	else
	{
		do_operation(data, "ra");
	}
}

void	chank_sort(t_data *data)
{
	int	chunk_size;
	int	i;
	int	position;

	if (data->a->size <= 5)
		chunk_size = 4;
	else if (data->a->size <= 100)
		chunk_size = 15;
	else
		chunk_size = 30;
	i = 0;
	while (data->a->size > 0)
	{
		push_to_b(data, &i, chunk_size);
		if (data->b->size == i + chunk_size)
			i += chunk_size;
		else if (data->a->size == 0)
			break ;
	}
	while (data->b->size > 0)
	{
		position = get_max_position_b(data);
		bring_to_top_b(data, position);
		do_operation(data, "pa");
	}
}
