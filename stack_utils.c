/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schoinsk <schoinsk@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/15 12:12:27 by jasiuda           #+#    #+#             */
/*   Updated: 2026/07/23 15:03:30 by schoinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_size(const t_stack *s)
{
	return (s->size);
}

int	stack_is_empty(const t_stack *s)
{
	return (s->size == 0);
}

int	stack_peek(const t_stack *s)
{
	if (stack_is_empty(s))
		return (0);
	return (s->top->value);
}

// pusty stack/1 element - nie wchodzi
int	stack_is_sorted(const t_stack *s)
{
	t_node	*cur;

	if (!s)
		return (1);
	cur = s->top;
	while (cur && cur->next)
	{
		if (cur->value > cur->next->value)
			return (0);
		cur = cur->next;
	}
	return (1);
}

void	stack_clear(t_stack *s)
{
	while (!stack_is_empty(s))
		stack_pop(s);
}
