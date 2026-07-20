/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jasiuda <jasiuda@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/20 12:20:07 by jasiuda           #+#    #+#             */
/*   Updated: 2026/07/20 13:08:33 by jasiuda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

static void	rotate(t_stack *s)
{
	t_node	*first;

	if (s->size < 2)
		return ;
	first = s->top;
	s->top = s->top->next;
	s->top->prev = NULL;
	first->next = NULL;
	first->prev = s->bottom;
	s->bottom->next = first;
	s->bottom = first;
}

void	ra(t_stack *a)
{
	rotate(a);
	ft_putstr_fd("ra\n", 1);
}

void	rb(t_stack *b)
{
	rotate(b);
	ft_putstr_fd("rb\n", 1);
}

void	rr(t_stack *a, t_stack *b)
{
	rotate(a);
	rotate(b);
	ft_putstr_fd("rr\n", 1);
}
