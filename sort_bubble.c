/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_bubble.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jasiuda <jasiuda@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/21 13:04:33 by jasiuda           #+#    #+#             */
/*   Updated: 2026/07/21 13:50:31 by jasiuda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	bubble_sort(t_stack *a, t_stack *b)
{
	int	size;
	int	i;
	int	j;

	size = a->size;
	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - 1 - i)
		{
			if (a->top->value > a->top->next->value)
				sa(a);
			ra(a);
			j++;
		}
		while (j-- > 0)
			rra(a);
		i++;
	}
}
