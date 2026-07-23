/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_radix.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schoinsk <schoinsk@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/21 10:53:30 by jasiuda           #+#    #+#             */
/*   Updated: 2026/07/23 17:54:32 by schoinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_max_bits(int size)
{
	int	max_bits;

	max_bits = 0;
	while (((size - 1) >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

static void	reindex_stack_a(t_data *data)
{
	t_node	*curr;
	t_node	*compare;
	int		index;

	curr = data->a->top;
	while (curr)
	{
		index = 0;
		compare = data->a->top;
		while (compare)
		{
			if (curr->value > compare->value)
				index++;
			compare = compare->next;
		}
		curr->index = index;
		curr = curr->next;
	}
}

void	radix_sort(t_data *data)
{
	int	i;
	int	max_bits;
	int	bit;
	int	size;

	size = data->a->size;
	max_bits = get_max_bits(size);
	bit = 0;
	while (bit < max_bits)
	{
		reindex_stack_a(data);
		i = 0;
		while (i < size)
		{
			if (((data->a->top->index >> bit) & 1) == 1)
				do_operation(data, "ra");
			else
				do_operation(data, "pb");
			i++;
		}
		while (data->b->size > 0)
			do_operation(data, "pa");
		bit++;
	}
}
