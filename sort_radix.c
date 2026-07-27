/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_radix.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schoinsk <schoinsk@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/21 10:53:30 by jasiuda           #+#    #+#             */
/*   Updated: 2026/07/27 14:49:17 by schoinsk         ###   ########.fr       */
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

static int	is_sorted(t_stack *s)
{
	t_node	*current;

	if (!s || !s->top)
		return (1);
	current = s->top;
	while (current->next)
	{
		if (current-> index > current->next->index)
			return (0);
		current = current->next;
	}
	return (1);
}

void	radix_sort(t_data *data)
{
	int	i;
	int	max_bits;
	int	bit;
	int	size;

	max_bits = get_max_bits(data->a->size);
	bit = 0;
	while (bit < max_bits)
	{
		if (is_sorted(data->a))
			break ;
		size = data->a->size;
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
