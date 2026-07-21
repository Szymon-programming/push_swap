/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jasiuda <jasiuda@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/21 10:53:30 by jasiuda           #+#    #+#             */
/*   Updated: 2026/07/21 13:51:18 by jasiuda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_max_bits(int size)
{
    int	max_bits;

    max_bits = 0;
    while ((size - 1) >> max_bits)
        max_bits++;
    return (max_bits);
}

void	radix_sort(t_stack *a, t_stack *b)
{
	int	i;
	int	max_bits;
	int	bit;
	int	size;

	size = a->size;
	max_bits = get_max_bits(size);
	bit = 0;
	while (bit < max_bits)
	{
		i = 0;
		while (i < size)
		{
			if (((a->top->index >> bit) & 1) == 1)
				pb(a, b);
			else
				ra(a);
			i++;
		}
		while (b->size > 0)
			pa(a, b);
		bit++;
	}
}
