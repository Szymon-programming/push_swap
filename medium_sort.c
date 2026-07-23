/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schoinsk <schoinsk@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/23 14:55:37 by schoinsk          #+#    #+#             */
/*   Updated: 2026/07/23 15:33:03 by schoinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_max_position(t_stack *b)
{
	t_node	*current;
	int		max_index;
	int		max_position;
	int		current_position;

	if (!b || !b->top)
		return (0);
	current = b->top;
	max_index = current->index;
	max_position = 0;
	current_position = 0;
	while (current)
	{
		if (current->index > max_index)
		{
			max_index = current->index;
			max_position = current_position;
		}
		current = current->next;
		current_position++;
	}
	return (max_position);
}

static void	push_to_b(t_data *data, int *i, int chunk_size)
{
	if (data->a->top->index <= *i)
	{
		do_operation(data, "pb");
		do_operation(data, "rb");
		(*i)++;
	}
	else if (data->a->top->index <= *i + chunk_size)
	{
		do_operation(data, "pb");
		(*i)++;
	}
	else
		do_operation(data, "ra");
}

static void	push_to_a(t_data *data)
{
	int max_position;

	max_position = get_max_position(data->b);
	bring_to_top_b(data, max_position);
	do_operation(data, "pa");
}

void	chank_sort(t_data *data)
{
	int chunk_size;
	int i;

	chunk_size = ft_sqrt(data->a->size) + 7;
	i = 0;
	while (data->a->size > 0)
		push_to_b(data, &i, chunk_size);
	while (data->b->size > 0)
		push_to_a(data);
}
